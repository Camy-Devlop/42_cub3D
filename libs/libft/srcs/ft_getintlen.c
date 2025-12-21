/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getintlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:33:47 by alephoen          #+#    #+#             */
/*   Updated: 2025/05/27 22:44:30 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_get_int_len(int nbr)
{
	long	nb;
	size_t	cnt;

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

size_t	ft_get_uint_len(unsigned int nbr)
{
	long	nb;
	size_t	cnt;

	nb = nbr;
	cnt = 1;
	while (nb >= 10)
	{
		++cnt;
		nb /= 10;
	}
	return (cnt);
}

// Calculates the hexadicimal length of an unsigned int
size_t	ft_get_hex_uint_len(unsigned int ux)
{
	size_t	len;

	len = 0;
	if (!ux)
		return (1);
	while (ux && ++len > 0)
		ux /= 16;
	return (len);
}
