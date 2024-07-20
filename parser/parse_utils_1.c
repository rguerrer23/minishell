/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:46:21 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/20 20:44:29 by jmartos-         ###   ########.fr       */
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
    {
        (*pos)++; // Saltar la comilla de cierre
    }
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

    (*pos)++; // Saltar la comilla inicial
    while (prompt[*pos] && prompt[*pos] != '\'')
    {
		
        aux[w_pos++] = prompt[*pos];
        (*pos)++;
    }
    if (prompt[*pos] == '\'')
    {
        (*pos)++; // Saltar la comilla de cierre
    }
    char *word = ft_strdup(aux);
    free(aux);
    return word;
}


/*
	Extrae una parte de caracteres que sean pipes consecutivos.
*/
char *process_pipe(char *prompt, int *pos)
{
	char *aux;
	int pos_aux;
	int len;

	pos_aux = *pos;
	len = 0;
	while (prompt[pos_aux] == '|')
	{
		pos_aux++;
		len++;
	}
	aux = ft_substr(prompt, *pos, len);
	*pos += len;
	return (aux);
}

/*
	Extrae una parte de caracteres que sean "<" consecutivos.
*/
char *process_red1(char *prompt, int *pos)
{
	char *aux;
	int pos_aux;
	int len;

	pos_aux = *pos;
	len = 0;
	while (prompt[pos_aux] == '<')
	{
		pos_aux++;
		len++;
	}
	aux = ft_substr(prompt, *pos, len);
	*pos += len;
	return (aux);
}

/*
	Extrae una parte de caracteres que sean ">" consecutivos.
*/
char *process_red2(char *prompt, int *pos)
{
	char *aux;
	int pos_aux;
	int len;

	pos_aux = *pos;
	len = 0;
	while (prompt[pos_aux] == '>')
	{
		pos_aux++;
		len++;
	}
	aux = ft_substr(prompt, *pos, len);
	*pos += len;
	return (aux);
}
