/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:07:28 by alephoen          #+#    #+#             */
/*   Updated: 2025/04/25 08:45:02 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cntgits(int nbr);

char	*ft_itoa(int nbr)
{
	char	*s;
	long	nb;
	int		len;
	int		isneg;

	nb = nbr;
	len = cntgits(nbr);
	if (nbr < 0)
		++len;
	s = (char *) malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	isneg = (nbr < 0);
	if (isneg)
	{
		*s = '-';
		nb = -nb;
	}
	while (--len >= isneg)
	{
		s[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (s);
}

static int	cntgits(int nbr)
{
	long	nb;
	int		cnt;

	nb = nbr;
	if (nb < 0)
		nb = -nb;
	cnt = 1;
	while (nb >= 10)
	{
		++cnt;
		nb /= 10;
	}
	return (cnt);
}
