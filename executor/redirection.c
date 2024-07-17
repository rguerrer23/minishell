/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:37:00 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/17 16:59:35 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	apply_outfile(char **name, t_cmd *cmds, int i)
{
	if (cmds->fdout > 2)
		close(cmds->fdout);
	cmds->fdout = open(name[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (cmds->fdout == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(name[i + 1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		cmds->g_status = 2;
	}
	dup2(cmds->fdout, STDOUT_FILENO);
}

void	apply_infile(char **name, t_cmd *cmds, int i)
{
	if (cmds->fdin > 2)
		close(cmds->infile);
	cmds->fdin = open(name[i + 1], O_RDONLY);
	if (cmds->fdin == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(name[i + 1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		cmds->g_status = 2;
	}
	dup2(cmds->fdin, STDIN_FILENO);
}
