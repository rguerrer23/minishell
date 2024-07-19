/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:30:25 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/19 17:51:34 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_var **parse_envp(char **envp)
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



char *replace_value_var(t_cmd *cmd, t_var **env_list, char *str)
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
		if (ft_strlen(varname) == 2 && ft_strcmp(varname, "$?") == 0)
		{
			ft_printf("%i\n",cmd->g_status);
			tmp1 = implement_dolar_question(str, start, end, cmd->g_status);
			ft_printf("%s\n",tmp1);
        }
		else
		{
			tmp2 = ft_strndup(str, start - str);						// left side of the var: "hello $USER test" -> "hello "
			tmp1 = ft_strjoin(tmp2, get_var(env_list, varname + 1)); // "hello " + "user" -> "hello user"
			free(tmp2);
			tmp2 = ft_strjoin(tmp1, end); // "hello user" + " test" -> "hello user test"
			free(tmp1);
		}
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

	i = 0;
	list_var = parse_envp(envp); // VARIABLES DE ENTORNO
	while (cmd->full_cmd[i])
	{
		if (cmd->full_cmd[i][0] == '$')
		{
			key = cmd->full_cmd[i];
			cmd->full_cmd[i] = get_var(list_var, key + 1); // SOBREESCRIBIENDO!
			//ft_printf("- (env_var.c) cmd->full_cmd[i] = %s\n", cmd->full_cmd[i]);
			free(key);
		}
		else if (cmd->full_cmd[i][0] == '"')
			cmd->full_cmd[i] = replace_value_var(cmd, list_var, cmd->full_cmd[i]); // SOBREESCRIBIENDO!
		i++;
	}
}
