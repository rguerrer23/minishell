/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:30:25 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/20 17:09:31 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_var **init_envp(char **envp)
{
	t_var **list_var;
	int c;
	int i;

	i = 0;
	c = ft_strd_len(envp);
	list_var = ft_calloc(sizeof(t_var *), c + 1); // +1 para NULL.
	if (!list_var)
        return (NULL); // error por falta de memoria.
	while (i < c)
	{
		list_var[i] = ft_calloc(sizeof(t_var), 1);
		if (!list_var[i])
        {
            while (i-- > 0)
            {
                free(list_var[i]->key);
                free(list_var[i]->value);
                free(list_var[i]);
				
            }
            free(list_var);
            return (NULL); // error por falta de memoria.
		}
		list_var[i]->key = ft_strndup(envp[i], ft_strchr(envp[i], '=') - envp[i]);
		list_var[i]->value = ft_strdup(ft_strchr(envp[i], '=') + 1);
		i++;
	}
	list_var[i] = NULL;
	return (list_var);
}

char *get_var(t_var **list_var, char *key)
{
	int i;

	i = 0;
	while (list_var[i])
	{
		if (ft_strcmp(list_var[i]->key, key) == 0)
			return (ft_strdup(list_var[i]->value));
		i++;
	}
	return (ft_strdup(""));
}

char *find_varname(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] == '$' && (str[i + 1] == '?' || ft_isalpha(str[i + 1]) || str[i + 1] == '_'))
        {
            int start = i;
            i++;
            while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
                i++;
            if (str[start + 1] == '?')
                return ft_strndup(str + start, 2); // Devuelve "$?"
            return ft_strndup(str + start, i - start); // Devuelve "$VAR"
        }
        i++;
    }
    return NULL;
}

char *replace_value_var(t_var **env_list, char *str)
{
	char *varname;
	char *start;
	char *end;
	char *tmp1;
	char *tmp2;

	varname = find_varname(str); // $VAR
	while (varname)
	{
		start = ft_strnstr(str, varname, ft_strlen(str)); // find where the var starts: "hello $USER test" -> "$USER test"
		if (start)
			end = start + ft_strlen(varname); // find where the var ends: "$USER test" -> "USER test"
		else
			return (NULL);										// Panic, we should never reach this point
		tmp2 = ft_strndup(str, start - str);						// left side of the var: "hello $USER test" -> "hello "
		tmp1 = ft_strjoin(tmp2, get_var(env_list, varname + 1)); // "hello " + "user" -> "hello user"
		free(tmp2);
		tmp2 = ft_strjoin(tmp1, end); // "hello user" + " test" -> "hello user test"
		free(tmp1);
        free(str);
        str = tmp2; // Actualizar la cadena original con la nueva cadena
        free(varname); // Liberar la memoria asignada a varname
        varname = find_varname(str); // Buscar la siguiente variable
	}
	remove_dquotes(str);
	return (str);
}

void expand_env_var(t_cmd *cmd, char **envp)
{
	t_var **list_var;
	int i;
	char *key;
	char *status;

	i = 0;
	list_var = init_envp(envp); // INICIALIZAMOS VARIABLES DE ENTORNO
	status = ft_itoa(cmd->g_status);
	while (cmd->full_cmd[i])
	{
		if ((ft_strcmp(cmd->full_cmd[i], "$?") == 0))
			cmd->full_cmd[i] = ft_strdup(status);
		else if (cmd->full_cmd[i][0] == '$' && !cmd->full_cmd[i][1])
			cmd->full_cmd[i][0] = '$';
		else if (cmd->full_cmd[i][0] == '$')
		{
			key = cmd->full_cmd[i];
			cmd->full_cmd[i] = get_var(list_var, key + 1); // SOBREESCRIBIENDO!
			free(key);
		}
		else if (ft_strchr(cmd->full_cmd[i], '\"'))
			cmd->full_cmd[i] = replace_value_var(list_var, cmd->full_cmd[i]);
		i++;
	}
}
