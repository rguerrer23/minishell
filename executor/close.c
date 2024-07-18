/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:49:15 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/18 12:13:30 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	reset_std(t_cmd *cmds)
{
	dup2(cmds->infile, STDIN_FILENO);
	dup2(cmds->outfile, STDOUT_FILENO);
}

void	close_fds(t_cmd *cmds)
{
	if (cmds->fdin > 0)
		close(cmds->fdin);
	if (cmds->fdout > 0)
		close(cmds->fdout);
	if (cmds->pin > 0)
		close(cmds->pin);
	if (cmds->pout > 0)
		close(cmds->pout);
}

void reset_fds(t_cmd *cmds, t_shell *shell)
{
	cmds->fdin = -1;
	cmds->fdout = -1;
	cmds->pin = -1;
	cmds->pout = -1;
	shell->pid = -1;
}

void	ft_close_resets(t_cmd *cmds, t_shell *shell)
{
	reset_std(cmds);
	close_fds(cmds);
	reset_fds(cmds, shell);
}