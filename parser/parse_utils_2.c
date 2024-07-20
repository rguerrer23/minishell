/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:05:40 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/20 19:20:56 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	Calcula la longuitud de una palabra dentro de prompt, empezando en pos y
	terminando cuando encuentre un espacio, "|", "<" o ">".
*/
int	strlen_end_word(char *prompt, int pos)
{
	int	w_len;

	w_len = 0;
	while (prompt[pos] && prompt[pos] != ' '
		&& prompt[pos] != '|' && prompt[pos] != '<' && prompt[pos] != '>')
	{
		w_len++;
		pos++;
	}
	return (w_len);
}

/*
	Extrae una subcadena de caracteres "normales" consecutivos.
*/
char *process_char(char *prompt, int *pos)
{
    int w_len = ft_strlen(prompt) - *pos;
    int w_pos = 0;
    char *aux = ft_calloc(w_len + 2, sizeof(char));

    while (prompt[*pos] && prompt[*pos] != ' ' && prompt[*pos] != '|' && prompt[*pos] != '<' && prompt[*pos] != '>')
    {
        if (prompt[*pos] == '\'')
        {
            char *sq_word = process_sq(prompt, pos);
            strcat(aux, sq_word);
            w_pos += ft_strlen(sq_word);
            free(sq_word);
        }
        else if (prompt[*pos] == '\"')
        {
            char *dq_word = process_dq(prompt, pos);
            strcat(aux, dq_word);
            w_pos += ft_strlen(dq_word);
            free(dq_word);
        }
        else
        {
            aux[w_pos++] = prompt[*pos];
            (*pos)++;
        }
    }
    aux[w_pos] = '\0';
    char *word = ft_strdup(aux);
    free(aux);
    return word;
}
