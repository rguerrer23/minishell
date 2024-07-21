/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:05:40 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/21 19:19:10 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	Extrae la parte de un array que está encerrada entre comillas dobles.
*/
char *process_dq(char *prompt, int *pos)
{
    int w_pos = 0;
    char *aux = ft_calloc(ft_strlen(prompt) - *pos + 1, sizeof(char));

    (*pos)++; // Saltar la comilla inicial
    while (prompt[*pos] && prompt[*pos] != '\"')
    {
        aux[w_pos++] = prompt[*pos];
        (*pos)++;
    }
    if (prompt[*pos] == '\"')
        (*pos)++; // Saltar la comilla de cierre
    char *word = ft_strdup(aux);
    free(aux);
    return word;
}

/*
	Extrae la parte de un array que está encerrada entre comillas simples,
	y ademas no las interpreta, ya que con las sq se imprime tal cual.
*/
char *process_sq(char *prompt, int *pos)
{
    int w_pos = 0;
    char *aux = ft_calloc(ft_strlen(prompt) - *pos + 1, sizeof(char));

    while (prompt[*pos])
    {
        aux[w_pos++] = prompt[*pos];
        (*pos)++;
    }
    char *word = ft_strdup(aux);
    free(aux);
    return word;
}
