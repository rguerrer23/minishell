/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:53:27 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/18 19:06:15 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* Esta funcion sale del minishell. */

void	ft_exit(t_shell *shell, int status)
{
	(void)shell;
	// liberar memoria antes de salir
	exit(status);
}
