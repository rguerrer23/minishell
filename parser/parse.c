/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:59:05 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/04 21:59:58 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Separamos por los caracteres que estamos validando, teniendo en cuenta
	los espacios y las comillas que pudieran haber al principio.
*/
char	**cmd_trim(char *prompt)
{
	int		pos;
	char	*aux;
	char	**new;

	pos = 0;
	new = NULL;
	while (prompt[pos]) // el valor de pos se actualiza en cada funcion.
	{
		while (prompt[0] && prompt[pos] == ' ')
			pos++;
		if (prompt[pos] == '\"')
			aux = process_dq(prompt, &pos); // ...
		else if (prompt[pos] == '\'')
			aux = process_sq(prompt, &pos); // ...
		else if (prompt[pos] == '|')
			aux = process_pipe(prompt, &pos); // ...
		else if (prompt[pos] == '<')
			aux = process_red1(prompt, &pos); // ...
		else if (prompt[pos] == '>')
			aux = process_red2(prompt, &pos); // ...
		else
			aux = process_char(prompt, &pos); // OK
		new = ft_str_add_back(new, aux);
	}
	return (new);
}

char	**parse_input(char *prompt)
{
	char	**cmd;

	cmd = cmd_trim(prompt);
	if (prompt[ft_strlen(prompt) - 1] == ' ')
		cmd = ft_charpp_del_back(cmd); // POR AQUI!!!
	cmd = ft_expand_vars(cmd);
	return (cmd);
}
