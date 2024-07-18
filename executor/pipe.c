/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:59:55 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/17 16:59:55 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	apply_pipe(t_shell *shell, t_cmd *cmds, char **cmd, int *prev_fd)
{
	int fd[2];
	pipe(fd);

	pid_t pid = fork();
	if (pid == 0)
	{
		if (*prev_fd != -1)
		{
			dup2(*prev_fd, STDIN_FILENO);
			close(*prev_fd);
		}
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec_choose(shell, cmds, cmd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &cmds->g_status, 0);
		close(fd[1]);
		if (*prev_fd != -1)
			close(*prev_fd);
	}
	*prev_fd = fd[0];
}
