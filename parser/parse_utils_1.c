/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:46:21 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/03 22:45:25 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*dq(char *prompt, int *i)
{
	char	*aux;

	aux = is_dq(prompt, *i);
	*i += ft_strlen(aux);
	return (aux);
}

char	*sq(char *prompt, int *i)
{
	char	*aux;

	aux = is_sq(prompt, *i);
	*i += ft_strlen(aux);
	return (aux);
}

char	*pipe(char *prompt, int *i)
{
	char	*aux;

	aux = is_pipe(prompt, *i);
	*i += ft_strlen(aux);
	return (aux);
}

char	*red1(char *prompt, int *i)
{
	char	*aux;

	aux = is_red1(prompt, *i);
	*i += ft_strlen(aux);
	return (aux);
}

char	*red2(char *prompt, int *i)
{
	char	*aux;

	aux = is_red2(prompt, *i);
	*i += ft_strlen(aux);
	return (aux);
}
