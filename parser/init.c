/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:40:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/19 20:58:34 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_pipe_red(t_pipe_red *value)
{
	value->pipe = 0;
	value->red = 0;
}

void	init_prompt(t_shell *shell, t_cmd *cmd)
{
	int i;
	
	i = 0;
	if (!check_cmd(shell))
	{
		ft_printf(RED"ERROR! (init_prompt)"NC);
		exit (EXIT_FAILURE);
	}
	cmd->full_cmd = parse_input(shell->prompt);
	expand_env_var(cmd, shell->env);
	while(cmd->full_cmd[i] != NULL)
	{
		remove_dquotes(cmd->full_cmd[i]);
		i++;
	}
}
