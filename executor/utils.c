/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:26:40 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/24 18:34:17 by rguerrer         ###   ########.fr       */
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
