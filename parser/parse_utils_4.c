/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:49:08 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/09 19:26:21 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
/*
int	ft_get_index(char *str, char *index)
{
	int	i;

	i = 0;
	if (!index || !*index)
		return ((int)ft_strlen(str));
	while (str + i != index || !*(str + i))
	{
		i++;
	}
	return (i);
}

char	*ft_replace(char *str, char *start, char *end, char *replace)
{
	char	*left;
	char	*right;
	char	*final;

	left = ft_substr(str, 0, ft_get_index(str, start));
	right = ft_substr(str, ft_get_index(str, end), ft_strlen(str));
	final = ft_strjoin(left, replace);
	free(left);
	left = ft_strjoin(final, right);
	free(right);
	free(str);
	free(final);
	return (left);
}
*/
