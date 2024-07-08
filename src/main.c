/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:03:39 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/08 19:58:00 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int g_mutex = 0;

/*
int	main(int ac, char **av, char **envp)
{
	t_cmd		prompt;
	t_shell		shell;

	if (ac < 2)
	{
		ft_putstr_fd(RED"minishell: invalid arguments\n"NC, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
 	while (1)
	{	
		shell_prompt();
		shell_read();
		init_prompt(&av); // jmartos-
		shell_execute(); // ricardo
	} 
	return (0);
}
*/

int	main(int argc, char **argv __attribute__((unused)), char **envp)
{
	char	*line;
    t_shell shell;
    t_cmd   cmd;

	if (argc != 1)
		exit(0);
	while (1)
	{
		line = readline("Minishell$~ ");
		shell.prompt = line;
		init_prompt(&shell, &cmd, envp);
        execute(&shell, &cmd);
		free(line);
    }
}
