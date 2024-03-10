/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:03:45 by ezhou             #+#    #+#             */
/*   Updated: 2023/10/19 15:18:05 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dupe;
	int		index;
	int		length;

	length = ft_strlen(s);
	index = 0;
	dupe = (char *)malloc(sizeof(char) * (length + 1));
	if (!dupe)
		return (NULL);
	while (index < length)
	{
		dupe[index] = s[index];
		index++;
	}
	dupe[index] = '\0';
	return (dupe);
}
