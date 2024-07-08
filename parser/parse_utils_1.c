/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:46:21 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/08 09:54:20 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	Extrae la parte de un array que está encerrada entre comillas dobles.
*/
char	*process_dq(char *prompt, int *pos)
{
	char	*aux;
	int		aux_pos;
	int		len;

	len = ft_substrlen(prompt, *pos + 1, '\"');
	aux = ft_calloc(len + 2, sizeof(char));
	aux_pos = 1;
	(*pos)++;
	aux[0] = '\"';
	while (prompt[*pos] != '\"')
	{
		aux[aux_pos] = prompt[*pos];
		if (prompt[*pos] == '\0')
			return (aux);
		(*pos)++;
		aux_pos++;
	}
	aux[aux_pos] = '\"';
	(*pos)++;
	return (aux);
}

/*
	Extrae la parte de un array que está encerrada entre comillas simples.
*/
char	*process_sq(char *prompt, int *pos)
{
	char	*aux;
	int		aux_pos;
	int		len;

	len = ft_substrlen(prompt, *pos + 1, '\'');
	aux = ft_calloc(len + 2, sizeof(char));
	aux_pos = 1;
	(*pos)++;
	aux[0] = '\'';
	while (prompt[*pos] != '\'')
	{
		aux[aux_pos] = prompt[*pos];
		if (prompt[*pos] == '\0')
			return (aux);
		(*pos)++;
		aux_pos++;
	}
	aux[aux_pos] = '\'';
	(*pos)++;
	return (aux);
}

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
