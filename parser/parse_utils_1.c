/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:46:21 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/03 15:28:52 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*call_dq(char *prompt, int *i)
{
	char	*aux;

	aux = is_dq(prompt, *i);
	*i += ft_strlen(aux);
	return (aux);
}

char	*call_sq(char *prompt, int *i)
{
	char	*aux;

	aux = is_sq(prompt, *i);
	*i += ft_strlen(aux);
	return (aux);
}

char	*call_red1(char *prompt, int *i)
{
	char	*aux;

	aux = is_red1(prompt, *i);
	*i += strlen(aux);
	return (aux);
}

char	*call_red2(char *prompt, int *i)
{
	char	*aux;

	aux = is_red2(prompt, *i);
	*i += strlen(aux);
	return (aux);
}

char	*call_pipe(char *prompt, int *i)
{
	char	*aux;

	aux = is_pipe(prompt, *i);
	*i += strlen(aux);
	return (aux);
}