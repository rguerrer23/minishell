/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:05:28 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/20 19:10:27 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* Esta funcion cambia el directorio actual de trabajo. */

void	ft_cd(char **full_cmd, t_cmd *cmd)
{
	if (full_cmd[2] != NULL)
	{
		write(STDERR_FILENO, "cd: too many arguments\n", 23);
		cmd->g_status = 1;
		return ;
	}
	if (chdir(full_cmd[1]) != 0)
	{
		ft_putstr_fd("cd: no such file or directory: ", STDERR_FILENO);
		ft_putstr_fd(full_cmd[1], STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		cmd->g_status = 1;
		return ;
	}
	return ;
}
