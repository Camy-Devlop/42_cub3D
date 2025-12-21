/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:37:30 by alephoen          #+#    #+#             */
/*   Updated: 2025/05/27 21:54:17 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

// this is a custom made atoi() for printf() it skips leading '0' to
// correctly calculate the form->wid in this edge case "%0 22d"
// the original atoi() doesnt skip the leading zeroes!
int	ft_atoi(const char *s)
{
	long	nb;
	int		sign;

	if (!s)
		return (0);
	while ((unsigned char) *s == '0' || (unsigned char) *s == 32
		|| (9 <= (unsigned char) *s && (unsigned char) *s <= 13))
		++s;
	sign = 1 + (-2 * (*s == '-'));
	if (*s == '-' || *s == '+')
		++s;
	nb = 0;
	while (ft_isdigit(*s))
	{
		if (nb > LONG_MAX / 10
			|| (nb == LONG_MAX / 10 && (*s - '0' > LONG_MAX % 10)))
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		nb = (nb * 10) + (*s - '0');
		++s;
	}
	return ((int)(sign * nb));
}
