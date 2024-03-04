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

int	main(int argc, char **argv, char **envp)
{
	(void)envp;
	(void)argv;
	if (argc > 1)
	{
		ft_putstr_fd("Error: minishell does not accept arguments\n", 2);
		return (1);
	}
	return (0);
}
