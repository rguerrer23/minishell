/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:40:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/03 16:26:04 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_cmd	init_prompt(char **av, char **envp)
{
	t_cmd	cmd;

	cmd.checked_prompt = parse_input();;
	cmd.cmd_path = ft_strdup(envp);
	cmd.infile = STDIN_FILENO;
	cmd.infile = STDOUT_FILENO;
	return (cmd);
}

void	init_pipe_red (t_pipe_red *value)
{
	value->pipe = 0;
	value->red = 0;
}
