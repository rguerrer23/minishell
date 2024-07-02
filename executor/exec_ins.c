/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:43:22 by rguerrer          #+#    #+#             */
/*   Updated: 2024/06/20 18:15:29 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_status;

/* Esta funcion ejecuta un comando de sistema. */

void	get_pid(t_shell *shell)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		shell->pid = 0;
	else if (pid < 0)
		shell->pid = -1;
	else
		shell->pid = pid;
}

char *get_cmd_path(char *cmd, char *bin)
{
	char *path;

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

void	exc(char *path, char **cmd, char **env, t_shell *shell)
{
	int status;

	status = 0;
	get_pid(shell);
	if(shell->pid == 0)
	{
		if (ft_strchr(path, '/') != NULL)
			execve(path, cmd, env);
		status = error_msg(cmd[0], 0);
		exit(status);
	}
	else
		waitpid(shell->pid, &status, 0);
	return (status);
}

void	execute_ins(t_shell *shell)
{
	int	i;
	char **bin;

	i = 0;
	while (shell.env && shell.env[i])
	{
		if (ft_strncmp(shell.env[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (shell.env[i] == NULL)
	{
		exc(shell->cmd->full_cmd[0], shell->cmd->full_cmd, shell->env, shell);
		exit;
	}
	bin = ft_split(shell->env[i] + 5, ':');
	if (!shell->cmd->full_cmd[0] && !bin)
	//error
	i = 1;
	shell->cmd->cmd_path = get_cmd_path(shell->cmd->full_cmd[0], bin[0]);
	while(shell->cmd->full_cmd[0] && bin[i] && path == NULL)
		shell->cmd->cmd_path = get_cmd_path(shell->cmd->full_cmd[0], bin[i++]);
	if (path != NULL)
		exc(path, shell->cmd->full_cmd, shell->env, shell);
	else
		exc(shell->cmd->full_cmd[0], shell->cmd->full_cmd, shell->env, shell);
	//liberar memoria utilizada
}
