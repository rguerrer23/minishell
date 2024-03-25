/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:04:18 by rguerrer          #+#    #+#             */
/*   Updated: 2024/03/12 12:04:18 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_input(t_minishell *minishell)
{
	t_token	*token;
	char	*line;

	line = minishell.line;
	token = ft_get_token(line);
	ft_lstadd_back(&minishell.tokens, ft_lstnew(token));
	free(line);
	minishell.line = NULL;
}