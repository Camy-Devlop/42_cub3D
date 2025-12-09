/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:08:04 by alephoen          #+#    #+#             */
/*   Updated: 2025/04/20 15:32:20 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned const char	*us1;
	unsigned const char	*us2;

	if (!n)
		return (0);
	us1 = (unsigned const char *) s1;
	us2 = (unsigned const char *) s2;
	i = -1;
	while (++i < n && us1[i] && us1[i] == us2[i])
		;
	if (i == n)
		return (0);
	return ((int)(us1[i] - us2[i]));
}
