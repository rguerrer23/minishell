/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:21:51 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/04 22:59:14 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**ft_charpp_del_back(char **str)
{
	char	**ret;
	int		len;
	int		i;

	len = ft_strdlen(str);
	ret = ft_calloc(len, sizeof(char *));
	i = 0;
	while (i < len - 1)
	{
		ret[i] = ft_strdup(str[i]);
		i++;
	}
	ft_strdfree(str);
	return (ret);
}

// 
char	**ft_str_add_back(char **str, char *add)
{
	int		temp_len;
	int		len;
	char	**ret;

	len = ft_strdlen(str);
	temp_len = len;
	ret = ft_calloc(sizeof(char *), len + 2);
	while (len--)
		ret[len] = ft_strdup(str[len]);
	ret[temp_len] = ft_strdup(add);
	ft_strdfree(str);
	free(add);
	return (ret);
}

char	*ft_get_var(char *cmd)
{
	t_master	mas;

	init_all(&mas, cmd);
	if (cmd[0] == SQ && condition2(cmd, mas))
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

char	**ft_expand_vars(char **cmd) // VAYA IDA DE OLLA!!!
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
