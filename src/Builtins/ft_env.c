/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:22:34 by ezhou             #+#    #+#             */
/*   Updated: 2024/03/06 17:39:54 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_env(t_cmd **cmd)
{
	int	i;

	i = 0;
	if ((*cmd)->num_args > 1)
		return (printf("Too many arguments\n"), ERROR);
	while ((*cmd)->env->env[i])
	{
		printf("%s\n", (*cmd)->env->env[i]);
		i++;
	}
	return (SUCCESS);
}
