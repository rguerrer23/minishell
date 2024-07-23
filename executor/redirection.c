/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:50:24 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/23 14:37:43 by rguerrer         ###   ########.fr       */
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

void	handle_input_redirection(char **prompt, t_shell *shell, int *i)
{
	int	j;

	if (*i == 0 || prompt[*i - 1] == NULL)
		shell->exec_signal = 1;
	apply_infile(prompt, shell, *i);
	j = *i;
	while (prompt[j] != NULL)
	{
		prompt[j] = prompt[j + 1];
		j++;
	}
	*i = *i - 1;
}

void	apply_redirections(char **prompt, t_shell *shell, int *i)
{
	while (prompt[*i])
	{
		if (ft_strcmp(prompt[*i], ">") == 0 || ft_strcmp(prompt[*i], ">>") == 0)
			handle_output_redirection(prompt, shell, i);
		else if (ft_strcmp(prompt[*i], "<") == 0 || ft_strcmp(prompt[*i],
				"<<") == 0)
			handle_input_redirection(prompt, shell, i);
		else
			(*i)++;
	}
}
