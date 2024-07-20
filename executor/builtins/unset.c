/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:39:41 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/20 18:59:17 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_unset(char **name_var, t_shell *shell)
{
	int		i;
	int		len;
	int		j;

	i = 0;
	if (!(name_var[1]))
		return ;
	while (shell->env[i] != NULL)
	{
		len = ft_strlen(name_var[1]);
		if (!ft_strncmp(shell->env[i], name_var[1], len) && shell->env[i][len] == '=')
		{
			//free(shell->env[i]);
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
}
