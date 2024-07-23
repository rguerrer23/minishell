/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:37:06 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/23 18:03:13 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* Esta funcion comprueba si existe un builtin y escoje*/
void	exec_choose(t_shell *shell, char **cmd)
{
	shell->g_status = 0;
	if (cmd && is_builtin(cmd[0]) == 1)
		execute_builtin(shell, cmd);
	else if (cmd)
		execute_bin(shell, cmd);
	if (shell->pin > 0)
		close(shell->pin);
	if (shell->pout > 0)
		close(shell->pout);
	shell->pin = -1;
	shell->pout = -1;
}

char	**extract_command(char **full_cmd, int start, int end, t_shell *shell)
{
	char	**cmd;
	int		k;
	int		i;
	
	k = end;
	apply_redirections(full_cmd, shell, &k, start);
	cmd = ft_calloc(start + k + 1, sizeof(char *));
	if (cmd == NULL)
		return (NULL);
	i = 0;
	while (i < k - start)
	{
		cmd[i] = full_cmd[start + i];
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}

void	process_command(t_shell *shell, char **cmd, int has_pipe)
{
	if (has_pipe)
		apply_pipe(shell, cmd);
	else
	{
		if (shell->fdin != -1)
		{
			dup2(shell->fdin, STDIN_FILENO);
			close(shell->fdin);
		}
		if (shell->exec_signal == 0)
			exec_choose(shell, cmd);
	}
	ft_strd_free(cmd);
}

void	execute(t_shell *shell)
{
	int		i;
	int		j;
	char	**cmd;

	i = 0;
	j = 0;
	setup_redirections(shell);
	while (shell->full_cmd[i] != NULL)
	{
		while (shell->full_cmd[i] != NULL && ft_strcmp(shell->full_cmd[i],
				"|") != 0)
			i++;
		cmd = extract_command(shell->full_cmd, j, i, shell);
		if (cmd == NULL)
			return ;
		process_command(shell, cmd, shell->full_cmd[i] != NULL);
		if (shell->full_cmd[i] != NULL)
			i++;
		j = i;
	}
	reset_env(shell);
	reset_redirections(shell);
}
