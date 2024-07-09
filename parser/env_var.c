/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:30:25 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/09 21:19:20 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*check_var(char *env_var)
{
	int		c;
	char	*var;

	c = 1;
	ft_strdup();
}

char	**expand_env_var(t_cmd *cmd)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	while (cmd->full_cmd)
	{
		c2 = 0;
		while (cmd->full_cmd[c1])
		{
			if (cmd->full_cmd[c1][0] == '$')
				check_var(cmd_full_cmd[c1]);
			c2++;
		}
		c1++;
	}
}
