/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:14:12 by alephoen          #+#    #+#             */
/*   Updated: 2025/12/05 22:37:13 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	if (!s)
		return (NULL);
	uc = (unsigned char) c;
	while (*s)
	{
		if ((unsigned char) *s == uc)
			return ((char *) s);
		++s;
	}
	if (uc == '\0')
		return ((char *) s);
	return (NULL);
}
