/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:12:54 by ezhou             #+#    #+#             */
/*   Updated: 2024/03/07 15:51:07 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static	int	ft_valid_name(char	*string)
{
	int	i;

	i = 0;
	while (string[i] != '=')
	{
		if (i == 0)
		{
			if (!ft_isalpha(string[i]))
				return (2);
		}
		else
		{
			if (!ft_isalnum(string[i]))
			{
				if (string[i] == '_')
					;
				else
					return (ERROR);
			}
		}
	}
	return (SUCCESS);
}

static void	ft_update_env(char **env, size_t size, char *variable)
{
	if (ft_strcontains(variable, '='))
		env[size - 1] = ft_strdup(variable);
	else
	{
		env[size - 1] = ft_strjoin(variable, "=");
	}
}

static int	ft_print_export_error(char *variable)
{
	printf("export: `%s': not a valid identifier\n", variable);
	return (ERROR);
}

int	ft_export(t_cmd **cmd)
{
	int		i;
	char	**arg;

	arg = (*cmd)->arg;
	i = 1;
	if ((*cmd)->num_arg > 1)
		return (ft_env(cmd));
	while (arg[i])
	{
		if (ft_valid_name(arg[i]))
			return (ft_print_export_error(arg[i]));
		else
			ft_update_env((*cmd)->env->env, (*cmd)->env->env_size, arg[i]);
		i++;
	}
	return (SUCCESS);
}
