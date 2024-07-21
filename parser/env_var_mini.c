/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_mini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:39:47 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/22 00:50:09 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char *find_varname(char *str, int pos)
{
    char *key;
    int i;
    int j;

    i = pos;
    while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
        i++;
    key = ft_calloc(i - pos + 1, sizeof(char));
    j = 0;
    while (pos < i)
    {
        key[j] = str[pos];
        pos++;
        j++;
    }
    return key;
}

void    mini_expand_env_var(char *prompt, char **env, int *pos, t_shell *shell)
{
    t_var **list_var;
    int i;
    char *key;
    char *status;
    char *value;

    list_var = init_envp(env);
    i = 0;
    status = ft_itoa(shell->g_status);
    (*pos)++;
    int len = ft_strlen(prompt);
    while(list_var[i])
    {
        key = find_varname(prompt, *pos);
        if (ft_strncmp(list_var[i]->key, key, ft_strlen(key)) == 0)
        {
            value = get_var(list_var, key);
            int len_value = ft_strlen(value);
            int len_key = ft_strlen(key);
            char *aux = ft_calloc(len + len_value - len_key + 1, sizeof(char));
            strncpy(aux, prompt, *pos);
            strcat(aux, value);
            strcat(aux, prompt + *pos + len_key);
            prompt = aux;
            pos += len_value - len_key;
            break;
        }
        i++;
    }
    free(status);
}
