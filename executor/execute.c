/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:37:06 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/23 14:53:21 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* Esta funcion comprueba si existe un builtin y escoje*/
void	exec_choose(t_shell *shell, char **cmd)
{
	shell->g_status = 0;
	if (cmd && is_builtin(cmd[0]) == 1)
		execute_builtin(shell, cmd);
	else if (cmd)
		execute_bin(shell, cmd);
	if (shell->pin > 0)
		close(shell->pin);
	if (shell->pout > 0)
		close(shell->pout);
	shell->pin = -1;
	shell->pout = -1;
}

char	**extract_command(char **full_cmd, int start, int end, t_shell *shell)
{
	char	**cmd;
	int		k;
	
	k = start;
	apply_redirections(full_cmd, shell, &k);
	cmd = ft_calloc(end - start + 1, sizeof(char *));
	if (cmd == NULL)
		return (NULL);
	k = 0;
	while (k < end - start)
	{
		cmd[k] = full_cmd[start + k];
		k++;
	}
	cmd[k] = NULL;
	return (cmd);
}

void	process_command(t_shell *shell, char **cmd, int *prev_fd, int has_pipe)
{
	if (has_pipe)
		apply_pipe(shell, cmd, prev_fd);
	else
	{
		if (*prev_fd != -1)
		{
			dup2(*prev_fd, STDIN_FILENO);
			close(*prev_fd);
		}
		if (shell->exec_signal == 0)
			exec_choose(shell, cmd);
	}
	ft_strd_free(cmd);
}

void	execute(t_shell *shell)
{
	int		i;
	int		j;
	int		prev_fd;
	char	**cmd;

	i = 0;
	j = 0;
	prev_fd = -1;
	setup_redirections(shell);
	while (shell->full_cmd[i] != NULL)
	{
		while (shell->full_cmd[i] != NULL && ft_strcmp(shell->full_cmd[i],
				"|") != 0)
			i++;
		cmd = extract_command(shell->full_cmd, j, i, shell);
		if (cmd == NULL)
			return ;
		process_command(shell, cmd, &prev_fd, shell->full_cmd[i] != NULL);
		if (shell->full_cmd[i] != NULL)
			i++;
		j = i;
	}
	reset_env(shell);
	reset_redirections(shell);
}
