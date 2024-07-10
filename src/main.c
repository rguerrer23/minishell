/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:03:39 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/10 11:42:49 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	g_mutex = 0;

int	main(int argc, char **argv __attribute__((unused)), char **envp)
{
	char	*line;
	t_shell	shell;
	t_cmd	cmd;

	if (argc != 1)
	{
		ft_putstr_fd(RED "minishell: invalid arguments\n" NC, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	while (1)
	{
		line = readline("Minishell$~ ");
		shell.prompt = line;
		init_prompt(&shell, &cmd, envp);
		exec_choose(&shell, &cmd);
		free(line);
	}
}
