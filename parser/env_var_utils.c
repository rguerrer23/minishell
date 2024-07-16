/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:13:05 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/16 18:55:03 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	remove_dquotes(char *str)
{
	int	len;

	len = strlen(str);
	if (len > 1 && str[0] == '"' && str[len - 1] == '"')
	{
		// Mueve todo a la izquierda para sobrescribir la primera comilla.
		ft_memmove(str, str + 1, len - 2);
		str[len - 2] = '\0';
		// Añade el null.
	}
}

char	*implement_dolar_question(char *str, char *start, char *end,
		int g_status)
{
	char	*tmp1;
	char	*tmp2;
	char	*e_code;

	e_code = ft_itoa(g_status);
		// Convertir el estado de estado de comando a string.
	tmp1 = ft_strndup(str, start - str);
		// Parte izquierda de la variable: "hello $?" -> "hello ".
	tmp2 = ft_strjoin(tmp1, e_code);
		// Concatenar parte izquierda con el estado de salida:
		// "hello " + "0" -> "hello 0".
	free(tmp1);
	free(e_code);
	tmp1 = ft_strjoin(tmp2, end);
		// Concatenar con la parte derecha:
		// "hello 0" + " resto de la cadena" -> "hello 0 resto de la cadena".
	free(tmp2);
	return (tmp1);
}
