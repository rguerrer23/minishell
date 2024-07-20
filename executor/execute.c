/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:37:06 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/20 19:32:45 by rguerrer         ###   ########.fr       */
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

int apply_redirections(char **prompt, t_cmd *cmds)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (prompt[i])
	{
		if (ft_strcmp(prompt[i], ">") == 0 || ft_strcmp(prompt[i], ">>") == 0)
		{
			apply_outfile(prompt, cmds, i);
			j = i;
			while (prompt[j] != NULL)
			{
				prompt[j] = prompt[j + 2];
				j++;
			}
		} else if (ft_strcmp(prompt[i], "<") == 0 || ft_strcmp(prompt[i], "<<") == 0)
		{
			apply_infile(prompt, cmds, i);
			j = i;
			while(prompt[j] != NULL)
			{
				prompt[j] = prompt[j + 2];
				j++;
			}
		} 
		else
			i++;
	}
	return 0;
}

/* Esta funcion comprueba si existe un builtin y escoje*/
void	exec_choose(t_shell *shell, t_cmd *cmds, char **cmd)
{
	cmds->g_status = 0;

	exclude_redirections(cmd);
	if (cmd && is_builtin(cmd[0]) == 1)
		cmds->g_status = execute_builtin(cmd, shell, cmds);
	else if (cmd)
		cmds->g_status = execute_ins(shell, cmds, cmd);
	if (cmds->pin > 0)
		close(cmds->pin);
	if (cmds->pout > 0)
		close(cmds->pout);
	cmds->pin = -1;
	cmds->pout = -1;
}

void execute(t_shell *shell, t_cmd *cmds)
{
	char **cmd;
	int i = 0, j = 0, k = 0;
	int prev_fd = -1;

	cmds->infile = dup(STDIN_FILENO);
	cmds->outfile = dup(STDOUT_FILENO);
	while (cmds->full_cmd[i] != NULL)
	{
		while (cmds->full_cmd[i] != NULL && ft_strcmp(cmds->full_cmd[i], "|") != 0)
			i++;
		cmd = malloc(sizeof(char *) * (i - j + 1));
		k = 0;
		while (k < i - j) 
		{
			cmd[k] = cmds->full_cmd[j + k];
			k++;
		}
		cmd[k] = NULL;
        apply_redirections(cmd, cmds);
        if (cmds->full_cmd[i] != NULL)
			apply_pipe(shell, cmds, cmd, &prev_fd);
		else
		{
			if (prev_fd != -1)
			{
				dup2(prev_fd, STDIN_FILENO);
				close(prev_fd);
			}
			exec_choose(shell, cmds, cmd);
		}
		ft_strd_free(cmd);
		if (cmds->full_cmd[i] != NULL)
			i++;
		j = i;
	}
	dup2(cmds->infile, STDIN_FILENO);
	dup2(cmds->outfile, STDOUT_FILENO);
	close(cmds->infile);
	close(cmds->outfile);
}
