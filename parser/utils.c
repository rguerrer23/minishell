/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:18:48 by kevlar            #+#    #+#             */
/*   Updated: 2024/06/19 19:41:45 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	Ejemplo de argumento qe puede entrar:

		echo "hello      there" how are 'you 'doing? $USER |wc -l >outfile
	
	¿Como spliteamos a un argumento asi y lo guardamos para trabajar con el?

	Paso 1: ¿cuantos argumentos hemos recibido?
				32 = espacio
				34 = "
				39 = '
	
	Paso 2: 
	
*/

static int	jump_next_quote(char *str, int pos, char quote)
{
	while (str[pos] && str[pos] != quote)
		pos++;
	return (pos);
}

int	count_args(char *args)
{
	int c;
	int	cont;
	
	c = 0;
	cont = 0;
	while (args[c])
	{
		if ((args[c] != 32 && args[c] != 34 && args[c] != 39)
			&& (args[c + 1] == '\0' || args[c + 1] == 32 
				|| args[c + 1] == 34 || args[c + 1] == 39))
			cont++;
		if (args[c] == 34 || args[c] == 39)
		{
			c = jump_next_quote(args, c + 1, args[c]);
			cont++;
		}
		c++;
	}
	return (cont);
}
