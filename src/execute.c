/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:55:35 by rguerrer          #+#    #+#             */
/*   Updated: 2024/05/08 10:55:35 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	shell_exec(t_shell *shell)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		exit_shell(shell, EXIT_FAILURE);
	if (pid == 0)
	{
		if (execve(shell->tokens[0], shell->tokens, shell->envp) < 0)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(shell->tokens[0], 2);
			ft_putstr_fd(": command not found\n", 2);
			exit_shell(shell, EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		shell->exit_status = WEXITSTATUS(status);
	}
}

void	shell_execute(t_shell *shell)
{
	shell->tokens = ft_split(shell->line, ' ');
	if (!shell->tokens)
		exit_shell(shell, EXIT_FAILURE);
	if (ft_strncmp(shell->tokens[0], "exit", 5) == 0)
		exit_shell(shell, EXIT_SUCCESS);
	/* else if (ft_strncmp(shell->tokens[0], "cd", 3) == 0)
		shell_cd(shell);
	else if (ft_strncmp(shell->tokens[0], "pwd", 4) == 0)
		shell_pwd(shell);
	else if (ft_strncmp(shell->tokens[0], "echo", 5) == 0)
		shell_echo(shell);
	else if (ft_strncmp(shell->tokens[0], "env", 4) == 0)
		shell_env(shell);
	else if (ft_strncmp(shell->tokens[0], "export", 7) == 0)
		shell_export(shell);
	else if (ft_strncmp(shell->tokens[0], "unset", 6) == 0)
		shell_unset(shell);
	else */
		shell_exec(shell);
}