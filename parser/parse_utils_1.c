/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:46:21 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/04 19:01:45 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*if_dq(char *prompt, int *pos)
{
	char	*aux;

	aux = process_dq(prompt, *pos);
	*pos += ft_strlen(aux); // Esto es para saltar posicion a la siguiente.
	return (aux);
}

char	*if_sq(char *prompt, int *pos)
{
	char	*aux;

	aux = process_sq(prompt, *pos);
	*pos += ft_strlen(aux); // Esto es para saltar posicion a la siguiente.
	return (aux);
}

char	*if_pipe(char *prompt, int *pos)
{
	char	*aux;

	aux = process_pipe(prompt, *pos);
	*pos += ft_strlen(aux); // Esto es para saltar posicion a la siguiente.
	return (aux);
}

char	*if_red1(char *prompt, int *pos)
{
	char	*aux;

	aux = process_red1(prompt, *pos);
	*pos += ft_strlen(aux); // Esto es para saltar posicion a la siguiente.
	return (aux);
}

char	*if_red2(char *prompt, int *pos)
{
	char	*aux;

	aux = process_red2(prompt, *pos);
	*pos += ft_strlen(aux); // Esto es para saltar posicion a la siguiente.
	return (aux);
}
