/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:13:05 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/10 14:23:25 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void remove_quotes(char *str)
{
	int len;

	len = strlen(str);
	if (len > 1 && str[0] == '"' && str[len - 1] == '"')
	{
		// Mueve el contenido hacia la izquierda para sobrescribir la primera comilla
		memmove(str, str + 1, len - 2);
		str[len - 2] = '\0'; // Añade el terminador nulo
	}
}
