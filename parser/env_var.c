/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:30:25 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/23 12:57:58 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	Sobreescribimos el key por la variable de entonrno despues de un $.
*/
char	*key_x_value(t_var **list_var, char *str, t_shell *shell)
{
	char	*res;
	char	*dollar;
	char	*key;
	char	*value;
	char	*end;

	res = ft_strdup("");
	while ((dollar = ft_strchr(str, '$')))
	{
		res = ft_insert_str(res, ft_strndup(str, dollar - str), ft_strlen(res));
		if (*(dollar + 1) == '?')
		{
			res = ft_insert_str(res, ft_itoa(shell->g_status), ft_strlen(res));
			str = dollar + 2;
		}
		else
		{
			end = dollar + 1;
			while (*end && (ft_isalnum(*end) || *end == '_'))
				end++;
			key = ft_strndup(dollar + 1, end - dollar - 1);
			value = get_var(list_var, key);
			res = ft_insert_str(res, value, ft_strlen(res));
			free(key);
			str = end;
		}
	}
	res = ft_insert_str(res, str, ft_strlen(res));
	return (res);
}

/*
	Expande las variables de entorno.
*/
void	expand_env_var(t_shell *shell, char **envp)
{
	t_var	**list_var;
	int		i;
	int		j;
	char	*key;
	char	*status;

	list_var = init_envp(envp);
	i = 0;
	status = ft_itoa(shell->g_status);
	while (shell->full_cmd[i])
	{
		j = 0;
		if (shell->full_cmd[i][0] != '\'')
		{
			while (shell->full_cmd[i][j])
			{
				if (shell->full_cmd[i][j] == '$' && !shell->full_cmd[i][j + 1])
					shell->full_cmd[i][j] = '$';
				else if (shell->full_cmd[i][j] == '$')
				{
					if (shell->full_cmd[i][j + 1] == '?')
					{
						shell->full_cmd[i] = delete_str(shell->full_cmd[i], j, j + 1);
						shell->full_cmd[i] = insert_str(shell->full_cmd[i], status, j);
						j++;
					}
					else
					{
						key = find_varname(shell->full_cmd[i], j + 1);
						shell->full_cmd[i] = delete_str(shell->full_cmd[i], j, j + ft_strlen(key));
						shell->full_cmd[i] = insert_str(shell->full_cmd[i], get_var(list_var, key), j);
						free(key);
					}
				}
				j++;
			}
			if (strchr(shell->full_cmd[i], '\"'))
				shell->full_cmd[i] = key_x_value(list_var, shell->full_cmd[i], shell);
		}
		i++;
	}
	free(status);
}
