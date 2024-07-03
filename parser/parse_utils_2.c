/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:55:09 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/03 16:07:00 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*no_quote(char *prompt, int *i)
{
	char	*aux;

	aux = no_q(prompt, *i);
	*i += ft_strlen(aux);
	return (aux);
}

char	*is_red1(char *prompt, int i)
{
	int		len;
	int		aux;
	char	*ret;

	len = 0;
	aux = i;
	while (prompt[aux] == '<')
	{
		len++;
		aux++;
	}
	ret = ft_substr(prompt, i, len);
	return (ret);
}

char	*is_red2(char *prompt, int i)
{
	int		len;
	int		aux;
	char	*ret;

	len = 0;
	aux = i;
	while (prompt[aux] == '>')
	{
		len++;
		aux++;
	}
	ret = ft_substr(prompt, i, len);
	return (ret);
}

char	*is_pipe(char *prompt, int i)
{
	int		len;
	int		aux;
	char	*ret;

	len = 0;
	aux = i;
	while (prompt[aux] == '|')
	{
		len++;
		aux++;
	}
	ret = ft_substr(prompt, i, len);
	return (ret);
}
