/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:03:39 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/18 19:14:09 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
	while (cmd.g_status != 1)
	{
		if_signal();
		line = readline("Minishell$~ ");
		if (line == NULL)
			break;
		else if (ft_check_line(line) == 0)
		{
			shell.prompt = line;
			add_history(line);
			shell.env = envp;
			init_prompt(&shell, &cmd, envp);
			execute(&shell, &cmd);
		}
		free(line);
	}
	return (0);
}
