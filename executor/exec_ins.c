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

void	execute_ins(t_cmd *cmd, t_shell *shell)
{
	int	status;

	status = 0;
	shell->pid = fork();
	if (shell->pid == 0)
	{
		if (cmd->infile != 0)
		{
			dup2(cmd->infile, 0);
			close(cmd->infile);
		}
		if (cmd->outfile != 1)
		{
			dup2(cmd->outfile, 1);
			close(cmd->outfile);
		}
		status = execve(cmd->cmd_path, cmd->full_cmd, shell->env);
	}
	else if (shell->pid < 0)
	{
		ft_putstr_fd("minishell: fork failed\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(shell->pid, &status, 0);
		if (WIFEXITED(status))
			g_status = WEXITSTATUS(status);
	}
}
