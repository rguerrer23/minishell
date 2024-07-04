/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:40:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/04 22:11:40 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_pipe_red (t_pipe_red *value)
{
	value->pipe = 0;
	value->red = 0;
}

void	init_prompt(char **av)
{
	t_cmd	cmd;
	t_shell	shell;

	shell.prompt = &av;
	if (!check_cmd(shell.prompt))
	{
		ft_printf(RED"ERROR! (init_prompt)"NC);
		exit (EXIT_FAILURE);
	}
	shell.parsed_prompt = check_cmd(shell.prompt);
	cmd.checked_prompt = parse_input(shell.parsed_prompt);
	cmd.cmd_path = ft_strdup(envp);
	cmd.infile = STDIN_FILENO;
	cmd.infile = STDOUT_FILENO;
	return (cmd);
}

