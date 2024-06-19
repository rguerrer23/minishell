/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:03:39 by rguerrer          #+#    #+#             */
/*   Updated: 2024/06/19 10:40:08 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int g_mutex = 0;

/*
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
*/

int	main(int ac, char **av, char **envp)
{
	t_prompt	prompt;
	char		*str_in;
	char		*str_out;

	if (ac < 2)
	{
		ft_putstr_fd(RED"minishell: invalid arguments\n"NC, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	parse_input(&prompt, av);
	// shell_init(&shell, envp);
 	// while (1)
	// {
	// 	shell_prompt(&shell);
	// 	shell_read(&shell);
	// 	shell_lexer(&shell);
	// 	shell_parser(&shell);
	// 	shell_execute(&shell);
	// } 
	return (0);
}