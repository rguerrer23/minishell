/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:05:40 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/21 21:32:38 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	Extrae la parte de un array que está encerrada entre comillas dobles.
*/
char *process_dq(char *prompt, int *pos, t_shell *shell)
{
    char *word;
    int w_pos = 0;
    int n = 0;
    char *aux = ft_calloc(ft_strlen(prompt) - *pos + 1, sizeof(char));

    (*pos)++; // Saltar la comilla inicial
    while (prompt[*pos] && prompt[*pos] != '\"')
    {
        if (prompt[*pos] != '$')
        {
            n = *pos;
            expand_env_var(shell, shell->env, n);
        }
        else
        {        
            aux[w_pos++] = prompt[*pos];
            (*pos)++;
        }
    }
    (*pos)++; // Saltar la comilla de cierre
    word = ft_strdup(aux);
    free(aux);
    return word;
}

/*
	Extrae la parte de un array que está encerrada entre comillas simples,
	y ademas no las interpreta, ya que con las sq se imprime tal cual.
*/
char *process_sq(char *prompt, int *pos)
{
    char *word;
    int w_pos = 0;
    char *aux = ft_calloc(ft_strlen(prompt) - *pos + 1, sizeof(char));

    while (prompt[*pos])
    {    
            aux[w_pos++] = prompt[*pos];
            (*pos)++;
    }
    word = ft_strdup(aux);
    free(aux);
    return word;
}
