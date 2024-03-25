/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:13:59 by rguerrer          #+#    #+#             */
/*   Updated: 2024/03/25 18:13:59 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token_type	ft_get_token_type(char *line)
{
	if (ft_strncmp(line, "echo", 4) == 0)
		return (TOKEN_ECHO);
	else if (ft_strncmp(line, "cd", 2) == 0)
		return (TOKEN_CD);
	else if (ft_strncmp(line, "pwd", 3) == 0)
		return (TOKEN_PWD);
	else if (ft_strncmp(line, "export", 6) == 0)
		return (TOKEN_EXPORT);
	else if (ft_strncmp(line, "unset", 5) == 0)
		return (TOKEN_UNSET);
	else if (ft_strncmp(line, "env", 3) == 0)
		return (TOKEN_ENV);
	else if (ft_strncmp(line, "exit", 4) == 0)
		return (TOKEN_EXIT);
	else
		return (TOKEN_CMD);
}

static char	*ft_get_token_value(char *line, t_token_type type)
{
	char	*value;
	int		i;

	i = 0;
	if (type == TOKEN_CMD)
	{
		while (line[i] && line[i] != ' ')
			i++;
		value = ft_substr(line, 0, i);
	}
	else
		value = ft_strdup(line);
	if (!value)
		ft_exit_error("malloc", 1);
	return (value);
}

t_token	*ft_get_token(char *line)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		ft_exit_error("malloc", 1);
	token->type = ft_get_token_type(line);
	token->value = ft_get_token_value(line, token->type);
	return (token);
}