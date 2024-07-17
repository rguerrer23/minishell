/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:37:06 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/17 20:34:46 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_free(char **cmd)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

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

int	apply_redirections(char **promt, t_cmd *cmds, t_shell *shell)
{
	int	pipe;
	int i;
	int j;

	pipe = 0;
	i = 0;
	while (promt[i])
	{
		if (ft_strcmp(promt[i], ">") == 0 || ft_strcmp(promt[i], "<") == 0 || ft_strcmp(promt[i], ">>") == 0 || ft_strcmp(promt[i], "<<") == 0)
		{
			if (ft_strcmp(promt[i], ">") == 0 || ft_strcmp(promt[i], ">>") == 0)
				apply_outfile(promt, cmds, i);
			else if (ft_strcmp(promt[i], "<") == 0 || ft_strcmp(promt[i], "<<") == 0)
			apply_infile(promt, cmds, i);
			j = i;
			while (promt[j] != NULL)
			{
				promt[j] = promt[j + 2];
				j++;
			}
		}
		else if (ft_strcmp(promt[i], "|") == 0)
		{
			pipe = apply_pipe(shell, cmds);
			i++;
		}
		else
		{
			i++;
		}
	}
	return(pipe);
}

/* Esta funcion comprueba si existe un builtin y escoje*/
void	exec_choose(t_shell *shell, t_cmd *cmds, char **cmd)
{

	cmds->g_status = 0;

	exclude_redirections(cmd);
	if (cmd && ft_strcmp(cmd[0], "exit") == 0 && has_pipe(cmd) == 0)
		ft_exit(shell);
	else if (cmd && is_builtin(cmd[0]) == 1)
		cmds->g_status = execute_builtin(cmd, shell);
	else if (cmd)
		cmds->g_status = execute_ins(shell, cmds, cmd);
	// despues liberar memoria y dejar igual que antes
}

void	execute(t_shell *shell, t_cmd *cmds)
{
	char **cmd;
	int i;
	int j;
	int pipe;
	int k;

	i = 0;
	j = 0;	
	pipe = 0;
	k = 0;
	while (cmds->full_cmd[i] != NULL)
	{
		while (cmds->full_cmd[i] != NULL && cmds->full_cmd[i][0] != '|')
			i++;
		cmd = malloc(sizeof(char *) * (i - j + 1));
		k = 0;
		while(j < i)
		{
			cmd[k] = cmds->full_cmd[j];
			j++;
			k++;
		}
		cmd[k] = NULL;
		cmds->infile = dup(STDIN_FILENO);
		cmds->outfile = dup(STDOUT_FILENO);
		pipe = apply_redirections(cmd, cmds, shell);
		if (pipe == 1 || cmds->full_cmd[i] == NULL)
		{
			exec_choose(shell, cmds, cmd);
		}
		if (cmds->full_cmd[i] != NULL)
			i++;
		j = i;
		if (cmd)
			ft_free(cmd);
	}
	ft_close_resets(cmds, shell);
}
