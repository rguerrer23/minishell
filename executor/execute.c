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
	char	**cmd;

	cmd = shell->cmd->full_cmd;
	if (cmd && ft_strcmp(cmd[0], "exit") == 0 && has_pipe(cmd) == 0)
		ft_exit(shell);
		//liberar memoria cmd
	else if (cmd && is_builtin(cmd[0]) == 1)
		execute_builtin(shell);
	else if (cmd)
		execute_ins(shell);
	//despues liberar memoria y dejar igual que antes
}
