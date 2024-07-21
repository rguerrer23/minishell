/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:46:21 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/21 13:06:17 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	Extrae una parte de caracteres que sean pipes consecutivos.
*/
char	*process_pipe(char *prompt, int *pos)
{
	char	*aux;
	int		pos_aux;
	int		len;

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
char	*process_red1(char *prompt, int *pos)
{
	char	*aux;
	int		pos_aux;
	int		len;

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
char	*process_red2(char *prompt, int *pos)
{
	char	*aux;
	int		pos_aux;
	int		len;

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

/*
	Extrae una subcadena de caracteres "normales" consecutivos.
*/
char	*process_char(char *prompt, int *pos)
{
	int w_pos = ft_strlen(prompt) - *pos;
	char *aux = ft_calloc(w_pos + 2, sizeof(char));
	
	w_pos = 0;
	while (prompt[*pos] && prompt[*pos] != ' ' && prompt[*pos] != '|'
		&& prompt[*pos] != '<' && prompt[*pos] != '>')
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
	return (word);
}
