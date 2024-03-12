/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:17:49 by rguerrer          #+#    #+#             */
/*   Updated: 2024/02/28 12:17:49 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_getenv(char **env)
{
}

int	main(int argc, char **argv, char **env)
{
	if (argc > 1)
	{
		ft_putstr_fd("Error: minishell does not accept arguments\n", 2);
		return (1);
	}
	(void)argv;
	ft_getenv(env);
	while (1)
	{
		ft_putstr_fd("minishell$ ", 1);
		ft_read_input(&minishell);
		ft_parse_input(&minishell);
		ft_execute_input(&minishell);
		ft_free_input(&minishell);
	}
	return (0);
}
