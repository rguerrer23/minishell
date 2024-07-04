/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:55:09 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/04 19:39:11 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*process_dq(char *prompt, int pos)
{
	char	*aux;
	int		aux_pos;
	int		len;

	len = ft_substrlen(prompt, pos + 1, '\"');
	aux = ft_calloc(len + 2, sizeof(char));
	aux_pos = 1;
	pos++;
	aux[0] = '\"';
	while (prompt[pos] != '\"')
	{
		aux[aux_pos] = prompt[pos];
		if (prompt[pos] == '\0')
			return (aux);
		pos++;
		aux_pos++;
	}
	aux[aux_pos] = '\"';
	return (aux);
}

char	*process_sq(char *prompt, int pos)
{
	char	*aux;
	int		aux_pos;
	int		len;

	len = ft_substrlen(prompt, pos + 1, '\'');
	aux = ft_calloc(len + 2, sizeof(char));
	aux_pos = 1;
	pos++;
	aux[0] = '\'';
	while (prompt[pos] != '\'')
	{
		aux[aux_pos] = prompt[pos];
		if (prompt[pos] == '\0')
			return (aux);
		pos++;
		aux_pos++;
	}
	aux[aux_pos] = '\'';
	return (aux);
}

char	*process_pipe(char *prompt, int pos)
{
	int		len;
	int		aux;
	char	*ret;

	len = 0;
	aux = pos;
	while (prompt[aux] == '|')
	{
		len++;
		aux++;
	}
	ret = ft_substr(prompt, pos, len);
	return (ret);
}

char	*process_red1(char *prompt, int pos)
{
	int		len;
	int		aux;
	char	*ret;

	len = 0;
	aux = pos;
	while (prompt[aux] == '<')
	{
		len++;
		aux++;
	}
	ret = ft_substr(prompt, pos, len);
	return (ret);
}

char	*process_red2(char *prompt, int pos)
{
	int		len;
	int		aux;
	char	*ret;

	len = 0;
	aux = pos;
	while (prompt[aux] == '>')
	{
		len++;
		aux++;
	}
	ret = ft_substr(prompt, pos, len);
	return (ret);
}
