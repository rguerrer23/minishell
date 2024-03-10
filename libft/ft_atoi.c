/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:08:33 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/11 13:20:26 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *nptr)
{
	long	result;
	int		index;
	int		minus;

	minus = 1;
	result = 0;
	index = 0;
	while ((nptr[index] >= 9 && nptr[index] <= 13) || nptr[index] == 32)
		index++;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
			minus = -1;
		index += 1;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result = result * 10 + (nptr[index++] - '0');
	}
	return (result * minus);
}
