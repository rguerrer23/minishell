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

	if (get_next_line(0, &line) == 0)
	{
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
	

}