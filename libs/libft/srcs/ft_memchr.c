/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:04:11 by alephoen          #+#    #+#             */
/*   Updated: 2025/05/14 17:46:32 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *byt, int c, size_t n)
{
	size_t				i;
	unsigned const char	*ub;
	unsigned char		uc;

	if (!byt)
		return (NULL);
	ub = (unsigned const char *) byt;
	uc = (unsigned char) c;
	i = -1;
	while (++i < n)
		if (ub[i] == uc)
			return ((void *)(ub + i));
	return (NULL);
}
