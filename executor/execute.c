/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:37:06 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/17 16:54:52 by rguerrer         ###   ########.fr       */
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
void	exec_choose(t_shell *shell, t_cmd *cmds, char **cmd)
{
	cmds->infile = dup(STDIN_FILENO);
	cmds->outfile = dup(STDOUT_FILENO);
	cmds->g_status = 0;
	apply_redirections(cmd, cmds, shell);
	exclude_redirections(cmd);
	if (cmd && ft_strcmp(cmd[0], "exit") == 0 && has_pipe(cmd) == 0)
		ft_exit(shell);
	else if (cmd && is_builtin(cmd[0]) == 1)
		cmds->g_status = execute_builtin(cmd, shell);
	else if (cmd)
		cmds->g_status = execute_ins(shell, cmds, cmd);
	ft_close_resets(cmds, shell);
	// despues liberar memoria y dejar igual que antes
}

void	execute(t_shell *shell, t_cmd *cmds)
{
	char **cmd;
	int i;
	int j;

	i = 0;
	j = 0;
	while (cmds->full_cmd[i] != NULL)
	{
		while (cmds->full_cmd[i] != NULL && cmds->full_cmd[i][0] != '|' && cmds->full_cmd[i][0] != '<' && cmds->full_cmd[i][0] != '>')
			i++;
		if (cmds->full_cmd[i] != NULL)
			i = i + 2;
		cmd = malloc(sizeof(char *) * i - j + 1);
		while(j < i)
		{
			cmd[j] = cmds->full_cmd[j];
			j++;
		}
		cmd[j] = NULL;
		exec_choose(shell, cmds, cmd);
	}
}
