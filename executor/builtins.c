/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:54:02 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/20 21:16:28 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* Esta funcion elige el builtin a ejecutar. */

int	execute_builtin(char **full_cmd, t_shell *shell, t_cmd *cmds)
{
	char	*builtins;

	builtins = full_cmd[0];
	if (!ft_strcmp(builtins, "echo"))
		ft_echo(full_cmd);
	else if (!ft_strcmp(builtins, "cd"))
		ft_cd(full_cmd, cmds);
	else if (!ft_strcmp(builtins, "env"))
		ft_env(shell);
	else if (!ft_strcmp(builtins, "exit"))
		ft_exit(full_cmd, shell, cmds);
	else if (!ft_strcmp(builtins, "export"))
		ft_export(full_cmd, shell, cmds);
	else if (!ft_strcmp(builtins, "unset"))
		ft_unset(full_cmd, shell, cmds);
	else if (!ft_strcmp(builtins, "pwd"))
		ft_pwd();
	return (cmds->g_status);
}

/* Esta funcion comprueba si el comando es un builtin o no. */

int	is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd") || !ft_strcmp(cmd,
			"env") || !ft_strcmp(cmd, "exit") || !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "pwd"))
		return (1);
	return (0);
}
