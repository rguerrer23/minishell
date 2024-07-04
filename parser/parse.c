/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:59:05 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/04 19:01:44 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

	w_len = wordlen_perso(prompt, pos);
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

/* Separa la cadena teniendo en cuenta los espacios y las comillas. */
char	**cmd_trim(char *prompt)
{
	int		pos;
	char	*aux;
	char	**new;

	pos = 0;
	new = NULL;
	while (prompt[pos])
	{
		while (prompt[0] && prompt[pos] == ' ')
			pos++;
		if (prompt[pos] == '\"')
			aux = if_dq(prompt, &pos); // ...
		else if (prompt[pos] == '\'')
			aux = if_sq(prompt, &pos); // ...
		else if (prompt[pos] == '|')
			aux = if_pipe(prompt, &pos); // ...
		else if (prompt[pos] == '<')
			aux = if_red1(prompt, &pos); // ...
		else if (prompt[pos] == '>')
			aux = if_red2(prompt, &pos); // ...
		else
			aux = if_char(prompt, &pos); // ...
		new = ft_str_add_back(new, aux);
	}
	return (new);
}

char	**parse_input(char *prompt)
{
	char	**cmd;

	cmd = cmd_trim(prompt); // POR AQUI!!!
	if (prompt[ft_strlen(prompt) - 1] == ' ')
		cmd = ft_charpp_del_back(cmd);
	cmd = ft_expand_vars(cmd);
	return (cmd);
}
