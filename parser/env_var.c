/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:30:25 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/24 21:59:21 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	replace_dollar(char **cmd, int *j, char *status, t_var **list_var)
{
	char	*key;

	if ((*cmd)[*j + 1] == '?')
	{
		*cmd = ft_delete_str(*cmd, *j, *j + 1);
		*cmd = ft_insert_str(*cmd, status, *j);
		(*j)++;
	}
	else
	{
		key = find_varname(*cmd, *j + 1);
		*cmd = ft_delete_str(*cmd, *j, *j + ft_strlen(key));
		*cmd = ft_insert_str(*cmd, get_var(list_var, key), *j);
		free(key);
	}
}

static void	do_command(char **cmd, t_var **list_var, char *status)
{
	int	j;

	j = 0;
	while ((*cmd)[j])
	{
		if ((*cmd)[j] == '$' && ((!ft_isalnum((*cmd)[j + 1])) && ((*cmd)[j
					+ 1] != '_') && ((*cmd)[j + 1] != '?')))
			(*cmd)[j] = '$';
		else if ((*cmd)[j] == '$')
			replace_dollar(cmd, &j, status, list_var);
		j++;
	}
}

void	restore_dolar(char **dolar)
{
	int	i;
	int	j;

	i = 0;
	while (dolar[i])
	{
		j = 0;
		while (dolar[i][j])
		{
			if (dolar[i][j] == 1)
				dolar[i][j] = '$';
			j++;
		}
		i++;
	}
}

void	expand_env_var(t_shell *shell, char **envp)
{
	t_var	**list_var;
	int		i;
	char	*status;

	list_var = init_envp(envp);
	status = ft_itoa(shell->g_status);
	i = 0;
	while (shell->full_cmd[i])
	{
		if (shell->full_cmd[i][0] != '\'')
			do_command(&shell->full_cmd[i], list_var, status);
		i++;
	}
	restore_dolar(shell->full_cmd);
	free(status);
	i = 0;
	while (shell->full_cmd[i] != NULL)
	{
		remove_quotes(shell->full_cmd[i]);
		i++;
	}
}
