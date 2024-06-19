/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:40:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/06/19 19:00:33 by kevlar           ###   ########.fr       */
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
