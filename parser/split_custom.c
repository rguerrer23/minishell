/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_custom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:18:48 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/01 15:23:24 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	Ejemplo de argumento que puede entrar:

		echo "hello      there" how are 'you 'doing? $USER |wc -l >outfile
	
	¿Como spliteamos a un argumento asi y lo guardamos para trabajar con el?

	Paso 1: contar los argumentos que hemos recibidos por parametros, 
			teniendo en cuenta que tenemos que separar los que esten dentro
			de comillas simples y comillas dobles.
	
	Paso 2: metemos dichos argumentos en un array con un split modificado.

*/
// (static) Si encuentra comilla simple o doble busca otra para contarlo
// como argumento.
static int	next_quote(char *str, int pos, char quote)
{
	while (str[pos] && str[pos] != quote)
		pos++;
	if (str[pos] == '\0')
		return (0);
	else
		return (pos);
}

// (static) Cuenta cuantos argumentos hemos recibido por parametros,
// teniendo en cuenta que si hay comillas dobles o simples la salta para
// buscar que esten cerradas y lo cuenta como otro argumento.
static int	count_args(char *args)
{
	int c;
	int	words;
	
	c = 0;
	words = 0;
	while (args[c])
	{
		while (args[c] && args[c] == ' ')
			c++;
		if (args[c] == '\0')
			break;
		if (args[c]
			&& args[c] != ' ' && args[c] != '\"' && args[c] != '\'')
			c++;
		else if (args[c] == '\"' || args[c] == '\'')
		{
			if (!next_quote(args, c + 1, args[c]))
				error_exit("ERROR! (next_quote)");
			else
				c = next_quote(args, c + 1, args[c]);
		}
		words++;
	}
	return (words);
}

// (static) Guardamos los argumentos, con comillas y lo que tenga. 
static char	**saving_args(char *args, int words)
{
	char	**new;
	int		c;

	c = 0;
	while (args[c] && args[c] == ' ')
		c++;

}

// (static) Eliminamos las comillas inicial y final que puedieran
// tener algunos argumentos.
static void	remove_quotes(char **args)
{
	
}

// Toma los argumentos recibidos por parametros, los separa teniendo en
// cuenta las comillas dobles y simples, y los guarda en una matriz.
char	**minishell_custom_split(char const *str)
{
	char	**new;
	size_t	words;

	words = 0;
	new = malloc(sizeof(char *) * (count_args(str + 1)));
	if (!new)
		return (NULL);
	new = saving_args();
	if (!new)
		return (NULL);
	remove_quotes(new);
	return (new);
}
