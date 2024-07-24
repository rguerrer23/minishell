/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:26:40 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/24 20:54:04 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	update_shlvl(t_shell *shell)
{
	char	*shlvl;
	int		i;
	int		lvl;

	i = 0;
	while (shell->env[i] != NULL)
	{
		if (ft_strncmp(shell->env[i], "SHLVL=", 6) == 0)
		{
			shlvl = ft_strdup(shell->env[i] + 6);
			lvl = ft_atoi(shlvl);
			lvl++;
			shlvl = ft_itoa(lvl);
			shell->env[i] = ft_strjoin("SHLVL=", shlvl);
			free(shlvl);
			return ;
		}
		i++;
	}
}

void	reset_env(t_shell *shell, t_cmd **cmds)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (shell->env[i])
	{
		if (shell->oldpwd != NULL && ft_strncmp(shell->env[i], "OLDPWD=", 7) == 0)
			shell->env[i] = ft_strjoin("OLDPWD=", shell->oldpwd);
		if (ft_strncmp(shell->env[i], "_=", 2) == 0)
		{
			if (cmds[0]->args[0] != NULL)
			{
				while (cmds[0]->args[x] != NULL)
					x++;
				shell->env[i] = ft_strjoin("_=", cmds[0]->args[x - 1]);
			}	
			else
				shell->env[i] = ft_strjoin("_=", cmds[0]->cmd);
		}	
		i++;
	}
}
