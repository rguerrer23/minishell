/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:30:25 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/21 21:31:41 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

// Sobreescribimos la variable de entonrno despues de un $.
char *replace_value_var(t_var **list_var, char *str, t_shell *shell)
{
    char *result = ft_strdup(""); // Resultado inicial = vacío.
    char *dollar;

    while ((dollar = ft_strchr(str, '$')))
    {
        // Copiamos la parte antes del $
        result = ft_strjoin(result, ft_strndup(str, dollar - str));

        if (*(dollar + 1) == '?')
        {
            // Manejo de $?.
            result = ft_strjoin(result, ft_itoa(shell->g_status));
            str = dollar + 2; // Avanzamos más allá de $?.
        }
        else
        {
            // Encontramos el final del nombre de la variable.
            char *end = dollar + 1;
            while (*end && (ft_isalnum(*end) || *end == '_'))
                end++;
            
            char *key = ft_strndup(dollar + 1, end - dollar - 1);
            char *value = get_var(list_var, key);
            
            result = ft_strjoin(result, value);
            free(key);
            
            str = end;
        }
    }

    // Añadimos cualquier texto restante.
    result = ft_strjoin(result, ft_strdup(str));
    
    return result;
}

// Expande las variables de entorno.
void expand_env_var(t_shell *shell, char **envp, int pos)
{
    t_var **list_var;
    int i;
    char *key;
    char *status;

    list_var = init_envp(envp);
    i = 0;
    status = ft_itoa(shell->g_status);
    while (shell->full_cmd[i])
    {
        if ((ft_strcmp(shell->full_cmd[i], "$?") == 0))
            shell->full_cmd[i] = ft_strdup(status);
        else if (shell->full_cmd[i][0] == '$' && !shell->full_cmd[i][1])
            shell->full_cmd[i][0] = '$';
        else if (shell->full_cmd[i][0] == '$')
        {
            key = shell->full_cmd[i];
            shell->full_cmd[i] = get_var(list_var, key + 1);
            free(key);
        }
        else if (strchr(shell->full_cmd[i], '\"'))
        {
            shell->full_cmd[i] = replace_value_var(list_var, shell->full_cmd[i], shell);
        }
        i++;
    }
    free(status);
}
