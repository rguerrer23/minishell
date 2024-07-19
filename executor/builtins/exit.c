/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:53:27 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/19 18:25:10 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* Esta funcion sale del minishell. */

void	ft_exit(char **cmd, t_shell *shell, t_cmd *cmds)
{
	shell->exit = 1;
	if (cmd[1] && cmd[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		cmds->g_status = 1;
	}
	else if (cmd[1])
	{
		if (ft_isdigit(cmd[1][0]))
			cmds->g_status = ft_atoi(cmd[1]);
		else
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(cmd[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			cmds->g_status = 255;
		}
	}
	else
		cmds->g_status = 0;
}
