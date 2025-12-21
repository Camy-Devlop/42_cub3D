/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:57:22 by alephoen          #+#    #+#             */
/*   Updated: 2025/11/24 12:58:24 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

size_t	ft_memjoin(void const **s1, void const *s2,
			size_t s1len, size_t s2len)
{
	char	*s;

	if (!(*s1) && !s2)
		return (0);
	if (!s1len && !s2len)
		return (0);
	if (s1len > SIZE_MAX - 1)
		return (0);
	if (!(*s1))
		s1len = 0;
	if (!s2)
		s2len = 0;
	s = (char *) malloc(sizeof(char) * (s1len + s2len + 1));
	if (!s)
	{
		*s1 = NULL;
		return (0);
	}
	s[s1len + s2len] = '\0';
	ft_memcpy(s, *(s1), s1len);
	ft_memcpy(s + s1len, s2, s2len);
	*s1 = s;
	return (s1len + s2len);
}
