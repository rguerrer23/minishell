/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:40:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/06/18 22:36:02 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_prompt	init_prompt(char **av, char **envp)
{
	t_prompt	prompt;
	char		*str;

	str = NULL;
	prompt->input = ft_dup_matrix(av);
	prompt->cmd_path = ft_strdup(envp);
    prompt->infile = STDIN_FILENO;
    prompt->infile = STDOUT_FILENO;
	return (prompt);
}
