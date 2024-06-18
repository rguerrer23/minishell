/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:52:32 by rguerrer          #+#    #+#             */
/*   Updated: 2024/06/18 17:13:09 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int ft_echo(char **args)
{
    int i;
    int newline = 1;

    i = 1;
    if (args[i] && !ft_strcmp(args[i], "-n"))
    {
        newline = 0;
        i++;
    }
    while (args[i])
    {
        ft_putstr_fd(args[i], STDOUT_FILENO);
        if (args[i + 1])
            ft_putstr_fd(" ", STDOUT_FILENO);
        i++;
    }
    if (newline)
        ft_putstr_fd("\n", STDOUT_FILENO);
    return (EXIT_SUCCESS);
}