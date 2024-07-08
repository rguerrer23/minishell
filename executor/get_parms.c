/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:37:00 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/08 18:48:50 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
/*
void    get_fd(char *name, t_cmd *shell, int *flags)
{
    int fd;

    //tengo que pasarme el nombre del archivo a abrir
    fd = open(name, flags[0], flags[1]);
    if (flags[0] == O_RDONLY)
        shell->fd_in = fd;
    else
        shell->fd_out = fd;
}

void    get_infile(char **cmd, t_cmd *shell, int i)
{
    int flags[2];

    flags[0] = O_RDONLY;
    flags[1] = 0;
    get_fd(cmd[i++], shell, flags);
}

void    get_outfile(char **cmd, t_cmd *shell, int i)
{
    int flags[2];

    flags[0] = O_WRONLY | O_CREAT | O_TRUNC;
    flags[1] = 0644;
    get_fd(cmd, shell, flags);
}

void    get_infile2(char **cmd, t_cmd *shell, int i)
{
    int flags[2];

    flags[0] = O_RDONLY;
    flags[1] = 0;
    get_fd(cmd, shell, flags);
}

void    get_outfile2(char **cmd, t_cmd *shell, int i)
{
    int flags[2];

    flags[0] = O_WRONLY | O_CREAT | O_APPEND;
    flags[1] = 0644;
    get_fd(cmd, shell, flags);
}
*/
