/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 02:25:24 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/24 03:25:33 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_cmd(t_cmd *cmd)
{
	cmd->split = NULL;
	cmd->cmd = NULL;
	cmd->args = NULL;
	cmd->incmd = NULL;
	cmd->outcmd = NULL;

	
}

int		pipe_counter(char **str)
{
	int	i;
	int cont;

	i = 0;
	cont = 1;
	while (str[i])
	{
		if (str[i][0] == '|')
			cont++;
		i++;
	}
	return (cont);
}

void	executor_split(t_shell *shell)
{
	t_cmd	**cmd;
	int		i;
	int		j;

	cmd = ft_calloc(sizeof(t_cmd *), pipe_counter(shell->split_cmd));
	i = 0;
	while (cmd[i])
	{
		
	}




	
	while (shell->split_cmd[i])
	{
		j = 0;
		while (shell->split_cmd[i][j])
		{
			if (cmd->split[i][j] == '<')
			{
				cmd->incmd[i][j] = cmd->split[i][j];
				if (cmd->split[i][j + 1] == '<')
				{
					j++;
					cmd->incmd[i][j] = cmd->split[i][j];
				}
				j++;
				while (cmd->args[i][j] != ' ')
				{
					cmd->args[i][j] = cmd->split[i][j];
					j++;
				}
			}
			else if (cmd->split[i][j] == '>')
			{
				cmd->outcmd[i][j] = cmd->split[i][j];
				if (cmd->split[i][j + 1] == '>')
				{
					j++;
					cmd->incmd[i][j] = cmd->split[i][j];
				}
				j++;
				while (cmd->args[i][j] != ' ')
				{
					cmd->args[i][j] = cmd->split[i][j];
					j++;
				}
			}
			else
			{
				while (cmd->args[i][j] != ' ')
				{
					cmd->args[i][j] = cmd->split[i][j];
					j++;
				}
			}
		}
		i++;
	}
}
