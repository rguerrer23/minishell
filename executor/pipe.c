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

int	apply_pipe(t_shell *shell, t_cmd *cmds)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		if(fd[0] > 0)
			close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		cmds->fdout = fd[1];
		shell->pid = pid;
		return (1);
	}
	else
	{
		if(fd[1] > 0)
			close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		cmds->fdin = fd[0];
		shell->pid = -1;
		return (2);
	}
}