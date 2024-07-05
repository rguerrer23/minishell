/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:21:51 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/05 17:52:42 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// Borramos el ultimo array de un array bidimensional.
char	**ft_charpp_del_back(char **str)
{
	char	**new;
	int		len;
	int		c;

	len = ft_strdlen(str);
	new = ft_calloc(len, sizeof(char *));
	c = 0;
	while (c < len - 1)
	{
		new[c] = ft_strdup(str[c]);
		c++;
	}
	ft_strdfree(str);
	return (new);
}

// Añadimos un string a la ultima posicion del array bidimensional.
char	**ft_str_add_back(char **str, char *add)
{
	int		temp_len;
	int		len;
	char	**new;

	len = ft_strdlen(str);
	temp_len = len;
	new = ft_calloc(sizeof(char *), len + 2);
	while (len--)
		new[len] = ft_strdup(str[len]);
	new[temp_len] = ft_strdup(add);
	ft_strdfree(str);
	free(add);
	return (new);
}

char	*ft_get_var(char *cmd)
{
	t_master	mas;

	init_all(&mas, cmd);
	if (cmd[0] == '\'' && condition2(cmd, mas))
		return (mas.strs.cpy);
	while (mas.strs.cpy[mas.count.i])
	{
		if (condition3(mas))
		{
			if_dollar_int(&mas);
			continue ;
		}
		mas.strs.aux = ft_strchr(mas.strs.cpy + mas.count.i, '$');
		if (!mas.strs.aux)
			break ;
		mas.count.j = ft_get_index(mas.strs.cpy,
				ft_strchr(mas.strs.cpy + mas.count.i, '$'));
		if (ft_isspace(mas.strs.aux[1]) || condition(mas))
		{
			mas.count.i++;
			continue ;
		}
		ft_aux_get_var(&mas);
	}
	return (mas.strs.cpy);
}

// 
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
	ft_strdfree(cmd);
	return (ret);
}
