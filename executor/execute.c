/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:37:06 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/08 18:44:48 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*

void	apply_redirections(char **promt, t_cmd *cmds)
{
	int i;

	i = 0;
	while(promt[i])
	{
		if (ft_strcmp(promt[i], ">") == 0)
			get_outfile(promt, cmds, i);
		else if (ft_strcmp(promt[i], "<") == 0)
			get_infile(promt, cmds, i);
		else if (ft_strcmp(promt[i], "|") == 0)
			get_pipe(promt, cmds, i);
		i++;
	}
}
*/

/* Esta funcion comprueba si existe un builtin y escoje*/
void	execute(t_shell *shell, t_cmd *cmds)
{
	char	**cmd;

	cmd = cmds->full_cmd;
	//apply_redirections(cmd, cmds);
	if (cmd && ft_strcmp(cmd[0], "exit") == 0 && has_pipe(cmd) == 0)
		ft_exit(shell);
		//liberar memoria cmd
	else if (cmd && is_builtin(cmd[0]) == 1)
		execute_builtin(cmd, shell);
	else if (cmd)
		execute_ins(shell, cmds);
	//despues liberar memoria y dejar igual que antes
}
