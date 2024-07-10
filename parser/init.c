/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:40:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/09 21:07:17 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_pipe_red(t_pipe_red *value)
{
	value->pipe = 0;
	value->red = 0;
}

void	init_prompt(t_shell *shell, t_cmd *cmd, char **envp)
{
	(void)envp;
	if (!check_cmd(shell))
	{
		ft_printf(RED"ERROR! (init_prompt)"NC);
		exit (EXIT_FAILURE);
	}
	cmd->full_cmd = parse_input(shell->prompt);
	expand_env_var(cmd);
	cmd->infile = STDIN_FILENO;
	cmd->outfile = STDOUT_FILENO;
}

void	init_var(t_var *var, char *cmd)
{
	var->var_copy = ft_strdup(cmd);
	var->var_pos_1 = 0;
	var->var_pos_2 = 0;
	var->exit_status = 0;
}
