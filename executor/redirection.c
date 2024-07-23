/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:50:24 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/23 17:46:39 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	handle_output_redirection(char **prompt, t_shell *shell, int *i)
{
	int j;

	apply_outfile(prompt, shell, *i);
	if (prompt[*i] != NULL && prompt[*i + 1] != NULL)
	{
		free(prompt[*i]);
		free(prompt[*i + 1]);
	}
	j = *i;
	while (prompt[j + 2] != NULL)
	{
		prompt[j] = prompt[j + 2];
		j++;
	}
	prompt[j] = NULL;
	prompt[j + 1] = NULL;
	*i = *i - 1;
}

void	handle_input_redirection(char **prompt, t_shell *shell, int *i, int start)
{
	int	j;
	
	*i = *i - 2;
	j = start;	
	apply_infile(prompt, shell, j);
	while (prompt[j + 2] != NULL)
	{
		prompt[j] = prompt[j + 2];
		j++;
	}
	prompt[j] = NULL;
	prompt[j + 1] = NULL;
}

void	apply_redirections(char **prompt, t_shell *shell, int *i, int start)
{
	int	j;

	j = start;
	while (prompt[j])
	{
		if (ft_strcmp(prompt[j], ">") == 0 || ft_strcmp(prompt[j], ">>") == 0)
			handle_output_redirection(prompt, shell, i);
		else if (ft_strcmp(prompt[j], "<") == 0 || ft_strcmp(prompt[j],
				"<<") == 0)
			handle_input_redirection(prompt, shell, i, start);
		else
			j++;
	}
}
