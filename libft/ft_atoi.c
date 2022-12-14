/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:44:42 by shbi              #+#    #+#             */
/*   Updated: 2021/11/21 14:48:39 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long int	r;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	r = 0;
	while ((*str >= '0' && *str <= '9') && r < 2147483648)
		r = (*str++ - '0') + (r * 10);
	r = r * sign;
	if (r < -2147483648)
		return (0);
	else if (r > 2147483647)
		return (-1);
	return ((int)r);
}
