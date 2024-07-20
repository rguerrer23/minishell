/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:59:23 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/20 17:44:53 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* Esta función crea o modifica una variable de entorno. */

void	ft_env_error(int bad_env, char *env)
{
	int	i;

	i = 0;
	if (bad_env == -1)
		ft_putstr_fd("export: not valid in this context: ", STDERR_FILENO);
	else if (bad_env == 0 || bad_env == -3)
		ft_putstr_fd("export: not a valid identifier: ", STDERR_FILENO);
	while (env[i] && (env[i] != '=' && bad_env != -3))
	{
		ft_putchar_fd(env[i], STDERR_FILENO);
		i++;
	}
	ft_putchar_fd('\n', STDERR_FILENO);
}

int	is_bad_env(char *env)
{
	int	i;

	i = 0;
	if (ft_isdigit(env[i]))
		return (0);
	while (env[i] && env[i] != '=')
	{
		if (!ft_isalnum(env[i]) && env[i] != '_')
			return (-1);
		i++;
	}
	if (env[i] == '=')
		return (2);
	return (1);
}

#include "../../inc/minishell.h"

void	ft_new_env(char *name_var, char *value_var, t_shell *shell)
{
	int		i;
	char	**new_env;
	char	*new_entry;

	i = 0;
	while (shell->env[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return ;
	i = 0;
	while (shell->env[i])
	{
		new_env[i] = ft_strdup(shell->env[i]);
		i++;
	}
	new_entry = ft_strjoin(name_var, "=");
	if (value_var)
	{
		char *temp = ft_strjoin(new_entry, value_var);
		free(new_entry);
		new_entry = temp;
	}
	new_env[i] = new_entry;
	new_env[i + 1] = NULL;
	free(shell->env);
	shell->env = new_env;
}

void	ft_export(char **full_cmd, t_shell *shell, t_cmd *cmds)
{
	int		i;
	int		bad_env;
	char	*name_var;
	char	*value_var;
	char	*equal_sign;

	i = 0;
	if (full_cmd[1] && full_cmd[2])
	{
		ft_putstr_fd("export: too many arguments\n", STDERR_FILENO);
		cmds->g_status = 1;
		return;
	}
	if (!full_cmd[1])
	{
		while (shell->env[i])
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			ft_putendl_fd(shell->env[i], STDOUT_FILENO);
			i++;
		}
		return ;
	}
	else
	{
		bad_env = is_bad_env(full_cmd[1]);
		if(full_cmd[1][0] == '=')
			bad_env = -3;
		if(bad_env <= 0)
		{
			ft_env_error(bad_env, full_cmd[1]);
			cmds->g_status = 1;
			return;
		}
		equal_sign = ft_strchr(full_cmd[1], '=');
		if (equal_sign)
		{
			*equal_sign = '\0';
			name_var = full_cmd[1];
			value_var = equal_sign + 1;
		}
		else
		{
			name_var = full_cmd[1];
			value_var = NULL;
		}
		i = 0;
		while (shell->env[i])
		{
			if (!ft_strncmp(shell->env[i], name_var, ft_strlen(name_var))
				&& shell->env[i][ft_strlen(name_var)] == '=')
			{
				free(shell->env[i]);
				shell->env[i] = ft_strjoin(name_var, "=");
				if (value_var)
					shell->env[i] = ft_strjoin(shell->env[i], value_var);
				cmds->g_status = 0;
				return;
			}
			i++;
		}
		ft_new_env(name_var, value_var, shell);
		cmds->g_status = 0;
	}
}
