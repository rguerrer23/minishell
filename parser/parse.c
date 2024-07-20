/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:59:05 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/20 19:21:15 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	Separamos por los caracteres que estamos validando, teniendo en cuenta
	los espacios y las comillas que pudieran haber al principio.
*/
char	**ft_strd_new(char *str)
{
	char	**new;

	new = ft_calloc(sizeof(char *), 2);
	new[0] = ft_strdup(str);
	return (new);
}

char **super_split(char *prompt)
{
    int pos = 0;
    char *aux;
    char **new = NULL;

    while (prompt[pos])
    {
        while (prompt[pos] == ' ')
            pos++;

        if (prompt[pos] == '|')
            aux = process_pipe(prompt, &pos);
        else if (prompt[pos] == '<')
            aux = process_red1(prompt, &pos);
        else if (prompt[pos] == '>')
            aux = process_red2(prompt, &pos);
        else
            aux = process_char(prompt, &pos);

        if (aux && *aux)
        {
            if (!new)
                new = ft_strd_new(aux);
            else
                new = ft_strd_add(new, aux);
        }
        free(aux);
    }
    return new;
}

char	**parse_input(char *prompt)
{
	char	**cmd;

	cmd = super_split(prompt);
	if (prompt[ft_strlen(prompt) - 1] == ' ')
		cmd = ft_strd_lastdel(cmd);
	return (cmd);
}
