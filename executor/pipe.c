/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:58:36 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/23 18:03:28 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	handle_pipe_error(t_shell *shell)
{
	ft_putstr_fd("zsh: pipe or fork failed\n", 2);
	shell->exec_signal = 1;
	shell->g_status = 1;
}

void	parent_process(t_shell *shell, int fd[2])
{
	waitpid(shell->pid, &shell->g_status, 0);
	close(fd[1]);
	if (shell->fdin != -1)
		close(shell->fdin);
}

void	apply_pipe(t_shell *shell, char **cmd)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (handle_pipe_error(shell));
	pid = fork();
	if (pid == -1)
		return (handle_pipe_error(shell));
	if (pid == 0)
	{
		if (shell->fdin != -1)
		{
			dup2(shell->fdin, STDIN_FILENO);
			close(shell->fdin);
		}
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		if (shell->exec_signal == 0)
			exec_choose(shell, cmd);
		exit(EXIT_SUCCESS);
	}
	else
		parent_process(shell, fd);
	shell->fdin = fd[0];
	close(fd[1]);
}
