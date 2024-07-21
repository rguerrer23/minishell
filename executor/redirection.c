/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:37:00 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/21 16:04:29 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	apply_outfile(char **name, t_shell *shell, int i)
{
	if (shell->fdout > 2)
		close(shell->fdout);
	if (ft_strcmp(name[i], ">>") == 0)
		shell->fdout = open(name[i + 1], O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
	else
		shell->fdout = open(name[i + 1], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (shell->fdout == -1)
	{
		ft_putstr_fd("zsh: no such file or directory: ", 2);
		ft_putstr_fd(name[i + 1], 2);
		ft_putchar_fd('\n', 2);
		shell->exec_signal = 1;
		shell->g_status = 1;
	}
	dup2(shell->fdout, STDOUT_FILENO);
}

void	apply_infile(char **name, t_shell *shell, int i)
{
	if (shell->fdin > 2)
		close(shell->infile);
	shell->fdin = open(name[i + 1], O_RDONLY, S_IRWXU);
	if (shell->fdin == -1)
	{
		ft_putstr_fd("zsh: no such file or directory: ", 2);
		ft_putstr_fd(name[i + 1], 2);
		ft_putchar_fd('\n', 2);
		shell->exec_signal = 1;
		shell->g_status = 1;
	}
	dup2(shell->fdin, STDIN_FILENO);
}

void	apply_pipe(t_shell *shell, char **cmd, int *prev_fd)
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
		if (shell->exec_signal == 0)
			exec_choose(shell, cmd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &shell->g_status, 0);
		close(fd[1]);
		if (*prev_fd != -1)
			close(*prev_fd);
	}
	*prev_fd = fd[0];
}
