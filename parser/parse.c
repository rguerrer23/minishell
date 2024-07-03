/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:59:05 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/03 15:28:52 by jmartos-         ###   ########.fr       */
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
	char	**new;
	char	*aux;
	int		i;

	i = 0;
	new = NULL;
	while (prompt[i] != '\0')
	{
		while (prompt[0] && prompt[i] == ' ')
			i++;
		if (prompt[i] == '\"')
			aux = call_dq(prompt, &i);
		else if (prompt[i] == '\'')
			aux = call_sq(prompt, &i);
		else if (prompt[i] == '|')
			aux = call_pipe(prompt, &i);
		else if (prompt[i] == '<')
			aux = call_red1(prompt, &i);
		else if (prompt[i] == '>')
			aux = call_red2(prompt, &i);
		else
			aux = call_no_quote(prompt, &i);
		new = ft_str_add_back(new, aux);
	}
	return (new);
}

char	**parse_input(char prompt)
{
	char	**cmd;

	cmd = cmd_trim(prompt); // VOY POR AQUI
	if (prompt[ft_strlen(prompt) - 1] == ' ')
		cmd = ft_charpp_del_back(cmd);
	cmd = ft_expand_vars(cmd);
	return (cmd);
}
