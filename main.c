/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:03:39 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/20 18:16:53 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

int g_error = 0;

static int	ft_check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_shell	shell;
	t_cmd	cmd;

	if (argc != 1 || argv[1] != NULL)
	{
		ft_putstr_fd(RED "minishell: invalid arguments\n" NC, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	cmd.g_status = 0;
	shell.exit = 0;
	shell.env = envp;
	while (shell.exit == 0)
	{
		if_signal();
		line = readline("Minishell$~ ");
		if (line == NULL)
			break;
		else if (ft_check_line(line) == 0)
		{
			shell.prompt = line;
			add_history(line);
			init_prompt(&shell, &cmd);
			//ft_printf("- (main.c) g_error = %i\n", g_error);
			execute(&shell, &cmd);
			
			
			//ft_printf("- (main.c) cmd.g_status = %i\n", cmd.g_status);
		}
		free(line);
	}
	return (0);
}