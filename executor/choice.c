/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:54:02 by rguerrer          #+#    #+#             */
/*   Updated: 2024/06/19 12:16:34 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* Esta funcion elige el builtin a ejecutar. */

void	check_builtins(t_shell *shell, t_cmd *cmds)
{
	char	*builtins;

	builtins = cmds->full_cmd[0];
	if (!ft_strcmp(builtins, "echo"))
		ft_echo(cmds->full_cmd);
	else if (!ft_strcmp(builtins, "cd"))
		ft_cd(cmds->full_cmd[1]);
	else if (!ft_strcmp(builtins, "env"))
		ft_env(shell);
	else if (!ft_strcmp(builtins, "exit"))
		ft_exit(shell);
	else if (!ft_strcmp(builtins, "export"))
		ft_export(cmds->full_cmd[1], shell);
	else if (!ft_strcmp(builtins, "unset"))
		ft_unset(cmds->full_cmd[1], shell);
	else if (!ft_strcmp(builtins, "pwd"))
		ft_pwd();
}

/* Esta funcion comprueba si el comando es un builtin o no. */

void	check(t_shell *shell, t_cmd *cmds)
{
	t_cmd	*tmp;

	tmp = cmds;
	if (tmp->cmd_path == NULL)
		check_builtins(shell, tmp);
	else
		ft_execute(tmp, shell);
}
