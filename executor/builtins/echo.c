/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:52:32 by rguerrer          #+#    #+#             */
/*   Updated: 2024/06/18 17:03:50 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int ft_echo(char **args)
{
    int i;

    i = 1;
    while (args[i])
    {
        ft_putstr_fd(args[i], STDOUT_FILENO);
        if (args[i + 1])
            ft_putstr_fd(" ", STDOUT_FILENO);
        i++;
    }
    ft_putstr_fd("\n", STDOUT_FILENO);
    return (EXIT_SUCCESS);
}