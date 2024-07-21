/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:39:41 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/21 18:25:53 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_unset(char **name_var, t_shell *shell)
{
	int		i;
	int		len;
	int		j;
	int		x;

	i = 0;
	x = 1;
	if (!(name_var[1]))
	{
		ft_putstr_fd("unset: not enough arguments\n", STDERR_FILENO);
		shell->g_status = 1;
		return ;
	}
	while (name_var[x] != NULL)
	{
		i = 0;
		if (ft_isdigit(name_var[x][0]))
		{
			ft_putstr_fd("unset: '", STDERR_FILENO);
			ft_putstr_fd(name_var[x], STDERR_FILENO);
			ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
			shell->g_status = 1;
			return ;
		}
		while (name_var[x][i] != '\0')
		{
			if (!ft_isalnum(name_var[x][i]) && name_var[x][i] != '_')
			{
				ft_putstr_fd("unset: '", STDERR_FILENO);
				ft_putstr_fd(name_var[x], STDERR_FILENO);
				ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
				shell->g_status = 1;
				return ;
			}
			i++;
		}
		x++;
	}
	x = 1;
	while (name_var[x] != NULL)
	{
		i = 0;
		while (shell->env[i] != NULL)
		{
			len = ft_strlen(name_var[x]);
			if (!ft_strncmp(shell->env[i], name_var[x], len) && shell->env[i][len] == '=')
			{
				j = i;
				while (shell->env[j] != NULL)
				{
					shell->env[j] = shell->env[j + 1];
					j++;
				}
				shell->env[j] = NULL;
				i--;
			}
			i++;
		}
		x++;
	}
}
