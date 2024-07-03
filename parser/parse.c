/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:59:05 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/03 23:56:32 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**ft_expand_vars(char **cmd)
{
	char	**ret;
	int		i;

	i = -1;
	ret = NULL;
	if (!cmd)
		return (NULL);
	while (cmd[++i])
		ret = ft_str_add_back(ret, ft_get_var(cmd[i]));
	ft_charppfree(cmd);
	return (ret);
}

/* Separa la cadena teniendo en cuenta los espacios y las comillas. */
char	**cmd_trim(char *prompt)
{
	int		pos;
	char	*aux;
	char	**new;

	pos = 0;
	new = NULL;
	while (prompt[pos])
	{
		while (prompt[0] && prompt[pos] == ' ')
			pos++;
		if (prompt[pos] == '\"')
			aux = dq(prompt, &pos); // ...
		else if (prompt[pos] == '\'')
			aux = sq(prompt, &pos); // ...
		else if (prompt[pos] == '|')
			aux = pipe(prompt, &pos); // ...
		else if (prompt[pos] == '<')
			aux = red1(prompt, &pos); // ...
		else if (prompt[pos] == '>')
			aux = red2(prompt, &pos); // ...
		else
			aux = normal_char(prompt, &pos); // ...
		new = ft_str_add_back(new, aux);
	}
	return (new);
}

char	**parse_input(char *prompt)
{
	char	**cmd;

	cmd = cmd_trim(prompt); //POR AQUI!!!
	if (prompt[ft_strlen(prompt) - 1] == ' ')
		cmd = ft_charpp_del_back(cmd);
	cmd = ft_expand_vars(cmd);
	return (cmd);
}
