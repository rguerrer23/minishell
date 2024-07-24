/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:28:22 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/24 22:29:02 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

void	ft_free_cmd(t_cmd *cmd)
{
    if (!cmd)
        return ;
    free(cmd->cmd);
    ft_strd_free(cmd->args);
    ft_strd_free(cmd->incmd);
    ft_strd_free(cmd->outcmd);
    free(cmd);
}

void	ft_free_struct(t_shell *shell)
{
    int	i;

    if (!shell)
        return ;
    ft_strd_free(shell->env);
    if (shell->cmds)
    {
        i = 0;
        while (shell->cmds[i])
        {
            ft_free_cmd(shell->cmds[i]);
            i++;
        }
        free(shell->cmds);
    }
    free(shell);
}
