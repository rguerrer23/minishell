/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:37:06 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/10 13:19:16 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void exclude_redirections(char **prompt)
{
	int	i;

	i = 0;
	while(prompt[i])
	{
		if (ft_strcmp(prompt[i], ">") == 0)
		{
			free(prompt[i]);
			prompt[i] = NULL;
		}
		i++;
	}
}

void	apply_redirections(char **promt, t_cmd *cmds, t_shell *shell)
{
	int	i;

	i = 0;
	while(promt[i])
	{
		if (ft_strcmp(promt[i], ">") == 0)
			apply_outfile(promt, cmds, i++);
		else if (ft_strcmp(promt[i], "<") == 0)
			apply_infile(promt, cmds, i++);
		else if (ft_strcmp(promt[i], "|") == 0)
			apply_pipe(shell);
		i++;
	}
}

/* Esta funcion comprueba si existe un builtin y escoje*/
void	exec_choose(t_shell *shell, t_cmd *cmds)
{
	char	**prompt;

	cmds->infile = dup(STDIN_FILENO);
	cmds->outfile = dup(STDOUT_FILENO);
	prompt = cmds->full_cmd;

	cmds->g_status = 0;
	apply_redirections(prompt, cmds, shell);
	exclude_redirections(prompt);
	if (prompt && ft_strcmp(prompt[0], "exit") == 0 && has_pipe(prompt) == 0)
		ft_exit(shell);
	else if (prompt && is_builtin(prompt[0]) == 1)
		cmds->g_status = execute_builtin(prompt, shell);
	else if (prompt)
		cmds->g_status = execute_ins(shell, cmds);
	ft_close_resets(cmds, shell);
	// despues liberar memoria y dejar igual que antes
}
