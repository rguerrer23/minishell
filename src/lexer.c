/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:24:27 by rguerrer          #+#    #+#             */
/*   Updated: 2024/05/02 12:24:27 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_token *ft_token_new(char *type, char *value)
{
	t_token *token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = value;
	token->next = NULL;
	token->prev = NULL;
	return (token);
}

t_token *ft_token_add(t_token *token, char *type, char *value)
{
	t_token *new;
	t_token *tmp;

	new = ft_token_new(type, value);
	if (!new)
		return (NULL);
	if (!token)
		return (new);
	tmp = token;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	return (token);
}

t_token *ft_tokenize(char *line)
{
	t_token *token;

	token = NULL;
	while(*line)
	{
		if (ft_isspace(*line))
			line++;
		else if (ft_isalnum(*line))
		{
			token = ft_token_add(token, "WORD", line);
			while (ft_isalnum(*line))
				line++;
		}
		else
		{
			token = ft_token_add(token, "OPERATOR", line);
			line++;
		}
	}
}

void	shell_lexer(t_shell *shell)
{
	char	*tmpline;
	t_token *token;

	tmpline = shell->line;
	token = ft_tokenize(tmpline);
	free(tmpline);
	shell->line = NULL;
}
