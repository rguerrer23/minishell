/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:05:40 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/04 19:39:53 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// Calcula la longuitud de una palabra dentro de prompt, empezando en pos y
// terminando cuando encuentre un espacio, "|", "<" o ">".
int	strlen_end_word(char *prompt, int pos)
{
	int	len;

	len = 0;
	while (prompt[pos] && prompt[pos] != ' '
        && prompt[pos] != '|' && prompt[pos] != '<' && prompt[pos] != '>')
	{
		len++;
		pos++;
	}
	return (len);
}

char	*if_char(char *prompt, int *pos)
{
	char	*aux;

	aux = process_char(prompt, *pos);
	*pos += ft_strlen(aux);
	return (aux);
}

char	*process_char(char *prompt, int pos)
{
	int		w_len;
	int		w_pos;
	char	*word;

	w_len = strlen_end_word(prompt, pos);
	word = ft_calloc(w_len + 2, sizeof(char));
	w_pos = 0;
	while (prompt[pos]
		&& prompt[pos] != ' ' && prompt[pos] != '\"' && prompt[pos] != '\'')
	{
		word[w_pos] = prompt[pos];
		pos++;
		w_pos++;
	}
	return (word);
}