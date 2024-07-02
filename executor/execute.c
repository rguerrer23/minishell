/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:37:06 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/02 16:48:47 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* Esta funcion comprueba si existe un builtin y escoje*/
void	execute(t_shell *shell)
{
	t_list	*tmp;
	t_cmd	*cmd;

	tmp = shell->cmds;
	while (tmp)
	{
		cmd = tmp->content;
		if (is_builtin(cmd->full_cmd[0]))
			execute_builtin(cmd->full_cmd);
		else
		{
			cmd->cmd_path = get_cmd_path(cmd->full_cmd[0], shell);
			execute_ins(cmd, shell);
		}
		tmp = tmp->next;
	}
}
