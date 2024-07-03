/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:40:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/03 14:20:11 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_cmd	init_prompt(char **av, char **envp)
{
	t_cmd	prompt;
	char	*str;

	str = ms_split(av);
	prompt.full_cmd = ft_dup_matrix(str);
	prompt.cmd_path = ft_strdup(envp);
	prompt.infile = STDIN_FILENO;
	prompt.infile = STDOUT_FILENO;
	return (prompt);
}

void	init_pipe_red (t_pipe_red *value)
{
	value->pipe = 0;
	value->red = 0;
}
