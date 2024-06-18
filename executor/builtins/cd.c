/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:05:28 by rguerrer          #+#    #+#             */
/*   Updated: 2024/06/18 17:51:57 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int cd(char *path)
{
    if (chdir(path) != 0)
    {
        write(STDERR_FILENO, "cd failed", 9);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}