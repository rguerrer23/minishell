/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:37:00 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/10 12:43:24 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	get_outfile(char **name, t_cmd *cmds, int i)
{
	if (cmds->outfile > 2)
		close(cmds->outfile);
	cmds->outfile = open(name[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (cmds->outfile < 0 || !name[i])
	{
		if (cmds->outfile != -1)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(name[i + 1], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			cmds->g_status = 2;
		}
		else
			cmds->g_status = 1;
	}
}

void	get_infile(char **name, t_cmd *cmds, int i)
{
	if (cmds->infile > 2)
		close(cmds->infile);
	cmds->infile = open(name[i + 1], O_RDONLY);
	if (cmds->infile < 0 || !name[i])
	{
		if (cmds->infile != -1)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(name[i + 1], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			cmds->g_status = 2;
		}
		else
			cmds->g_status = 1;
	}
}

void	get_pipe(t_shell *shell)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		if (pipefd[1] != STDIN_FILENO)
			close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		shell->pid = -1;

	}
	else
	{
		if (pipefd[0] != STDIN_FILENO)
			close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		shell->pid = pid;
	}
}
