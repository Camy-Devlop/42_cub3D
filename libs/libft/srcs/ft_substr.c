/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:10:49 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 12:53:43 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// I had to remove this part for efficiency for FDF to read Large Maps faster;

	// srclen = -1;
	// while (src[++srclen])
	// 	;
	// if (beg >= srclen)
	// 	return (ft_calloc(1, sizeof(char)));
	// sublen = srclen - beg;
	// if (sublen > len)
	// 		sublen = len;
char	*ft_substr(char const *src, unsigned int beg, size_t len)
{
	size_t	i;
	size_t	sublen;
	char	*substr;

	if (!src)
		return (NULL);
	sublen = len;
	substr = (char *)malloc(sizeof(char) * (sublen + 1));
	if (!substr)
		return (NULL);
	i = -1;
	while (++i < sublen && src[beg + i])
		substr[i] = src[beg + i];
	substr[i] = '\0';
	return (substr);
}
