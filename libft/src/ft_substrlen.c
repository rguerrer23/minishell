/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:08:35 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/04 19:13:39 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* Libreria 42 "jmartos-". */

int ft_substrlen(char *str, int start, char chr)
{
	int	len;

	len = 0;
	while (str[start] && str[start] != chr)
	{
		len++;
		start++;
	}
	len++;
	return (len);
}