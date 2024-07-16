/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:03:39 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/16 20:51:38 by kevlar           ###   ########.fr       */
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
	while (1)
	{
		if_signal();
		line = readline("Minishell$~ ");
		if (line == NULL)
			exit (0);
		else if (ft_check_line(line) == 0)
		{
			shell.prompt = line;
			add_history(line);
			shell.env = envp;
			init_prompt(&shell, &cmd, envp);
			exec_choose(&shell, &cmd);
			ft_printf("g_status = %i\n", cmd.g_status);
			//ft_printf("g_error = %i\n", g_error);
		}
		free(line);
	}
	return (0);
}
