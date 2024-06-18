/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:03:39 by rguerrer          #+#    #+#             */
/*   Updated: 2024/06/18 17:24:04 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	shell_init(t_shell *shell, char **envp)
{
	shell->envp = envp;
}

void	shell_prompt(t_shell *shell)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		exit_shell(shell, EXIT_FAILURE);
	ft_putstr_fd(SHELL_PROMPT, shell->fd_out);
	ft_putstr_fd(cwd, shell->fd_out);
	ft_putstr_fd("% ", shell->fd_out);
	free(cwd);
}

void	shell_read(char **line)
{
	line = readline(NULL);
	if (!shell->line)
		exit_shell(shell, EXIT_SUCCESS);
	if (ft_strlen(shell->line) > 0)
		add_history(shell->line);
}

int	main(int argc, char **argv, char **envp)
{
	t_prompt	shell;

	if (argc != 1 || argv[1])
	{
		ft_putstr_fd("minishell: invalid arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	shell_init(&shell, envp);
 	while (1)
	{
		shell_prompt(&shell);
		shell_read(&shell);
		shell_lexer(&shell);
		shell_parser(&shell);
		shell_execute(&shell);
	} 
	return (0);
}