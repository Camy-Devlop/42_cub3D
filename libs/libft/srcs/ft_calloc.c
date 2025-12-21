/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:51:48 by alephoen          #+#    #+#             */
/*   Updated: 2025/08/30 16:12:51 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t data_size)
{
	void	*r;

	if (!n || !data_size)
	{
		n = 1;
		data_size = 1;
	}
	if (n > SIZE_MAX / data_size)
		return (NULL);
	r = malloc(n * data_size);
	if (!r)
		return (NULL);
	ft_memset(r, 0, n * data_size);
	return (r);
}
