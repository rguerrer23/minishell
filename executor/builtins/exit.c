/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:53:27 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/21 10:21:07 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* Esta funcion sale del minishell. */

void	ft_exit(char **cmd, t_shell *shell)
{
	shell->exit = 1;
	if (cmd[1] && cmd[2])
		shell->g_status = 1;
	else if (cmd[1] && ft_isdigit_str(cmd[1]) == 0)
		shell->g_status = 255;
	else if (cmd[1])
		shell->g_status = ft_atoi(cmd[1]);
	else
		shell->g_status = 0;
}
