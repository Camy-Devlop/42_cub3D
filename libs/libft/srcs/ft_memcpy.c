/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:23:30 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/15 10:05:46 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_memory.h"
#include "libft.h"

void	*ft_memcpy(void *des, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if ((!des || !src) && n)
		return (NULL);
	if (!n)
		return (des);
	d = (unsigned char *) des;
	s = (unsigned char *) src;
	i = -1;
	while (++i < n)
		d[i] = s[i];
	return (des);
}
