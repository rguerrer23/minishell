/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:43:22 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/18 12:06:53 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* Esta funcion ejecuta un comando de sistema. */

int	error_msg(char *cmd)
{
	DIR *dir;
	int status;

	ft_putstr_fd(cmd, 2);
	if (ft_strchr(cmd, '/') == NULL) {
		ft_putstr_fd(": command not found\n", 2);
	} else if (access(cmd, F_OK) == -1) {
		ft_putstr_fd(": No such file or directory\n", 2);
	} else if ((dir = opendir(cmd)) != NULL) {
		closedir(dir);
		ft_putstr_fd(": Is a directory\n", 2);
	} else if (access(cmd, X_OK) == -1) {
		ft_putstr_fd(": Permission denied\n", 2);
	}
	if (ft_strchr(cmd, '/') == NULL || (dir == NULL))
		status = 127;
	else
		status = 126;
	return (status);
}

char	*get_cmd_path(char *cmd, char *bin)
{
	char	*path;

	path = malloc(ft_strlen(bin) + ft_strlen(cmd) + 2);
	if (path == NULL)
		return (NULL);
	ft_strlcpy(path, bin, ft_strlen(bin) + 1);
	ft_strlcat(path, "/", ft_strlen(bin) + 2);
	ft_strlcat(path, cmd, ft_strlen(bin) + ft_strlen(cmd) + 2);
	if (access(path, F_OK) == 0)
		return (path);
	else
	{
		free(path);
		return (NULL);
	}
}

int	exc(char *path, char **cmd, t_shell *shell)
{
	int status;

	status = 0;
	shell->pid = fork();
	if (shell->pid == 0)
	{
		if (ft_strchr(path, '/') != NULL)
			execve(path, cmd, shell->env);
		status = error_msg(path);
		exit(status);
	}
	else
		waitpid(shell->pid, &status, 0);
	return (status);
}

int	execute_ins(t_shell *shell, t_cmd *cmds, char **cmd)
{
	int		i;
	char	**bin;
	int		status;

	i = 0;
	while (shell->env && shell->env[i])
	{
		if (ft_strncmp(shell->env[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (shell->env[i] == NULL)
		return (exc(cmd[0], cmd, shell));
	bin = ft_split(shell->env[i], ':');
	if (!cmd[0] && !bin)
		return (1);
	i = 1;
	cmds->cmd_path = get_cmd_path(cmd[0], bin[0] + 5);
	while (cmd[0] && bin[i] && cmds->cmd_path == NULL)
		cmds->cmd_path = get_cmd_path(cmd[0], bin[i++]);
	if (cmds->cmd_path != NULL)
		status = exc(cmds->cmd_path, cmd, shell);
	else
		status = exc(cmd[0], cmd, shell);
	// liberar memoria bin
	// liberar memoria utilizada
	return (status);
}
