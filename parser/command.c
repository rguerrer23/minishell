/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:59:54 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/03 14:20:11 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_cmd(char *prompt)
{
	int	pos;
	int	state;

	pos = 0;
	state = NO_QUOTE;
	while (prompt[pos])
	{
		if (prompt[pos] == '\"' || prompt[pos] == '\'')
			state = check_quotes(prompt[pos], state);
		pos++;
	}
	if (state != NO_QUOTE)
	{
		printf(RED"ERROR! (check_cmd)\n"NC);
		return (-1);
	}
	if (is_first_pipe(prompt))
		return (0);
	else
		return (validating_pipes_reds(prompt));
}
