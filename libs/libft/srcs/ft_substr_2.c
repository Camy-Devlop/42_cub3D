/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:10:49 by alephoen          #+#    #+#             */
/*   Updated: 2025/08/20 14:49:12 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// /*
// #include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

static void	*ft_calloc(size_t n, size_t data_size);
static void	*ft_memset(void *s, int c, size_t n);
static char	*allocate_substr(
				size_t len, size_t sublen, bool expan, bool need_extra);

// expan: expantion, in case I need a longer string use the full len instead;
char	*ft_substr2(char const *src, unsigned int beg, size_t len, bool expan)
{
	size_t	i;
	size_t	srclen;
	size_t	sublen;
	char	*substr;
	int		need_extra;

	if (!src)
		return (NULL);
	srclen = -1;
	while (src[++srclen])
		;
	if (beg >= srclen)
		return (ft_calloc(1, sizeof(char)));
	need_extra = 0;
	sublen = srclen - beg;
	if (sublen > len && ++need_extra)
		sublen = len;
	substr = allocate_substr(len, sublen, expan, need_extra);
	if (!substr)
		return (NULL);
	i = -1;
	while (++i < sublen && src[beg + i])
		substr[i] = src[beg + i];
	substr[i] = '\0';
	return (substr);
}

static char	*allocate_substr(
				size_t len, size_t sublen, bool expan, bool need_extra)
{
	char	*substr;
	size_t	tmp_len;

	substr = NULL;
	tmp_len = len;
	if (expan == 1 && need_extra == 1)
		substr = (char *)malloc(sizeof(char) * (len + 2));
	else if (expan == 1)
		substr = (char *)malloc(sizeof(char) * (len + 1));
	else
	{
		substr = (char *)malloc(sizeof(char) * (sublen + 1));
		tmp_len = sublen;
	}
	if (!substr)
		return (NULL);
	substr[tmp_len] = '\0';
	substr[tmp_len - 1] = '\0';
	return (substr);
}

static void	*ft_calloc(size_t n, size_t data_size)
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

static void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *) s;
	i = -1;
	while (++i < n)
		p[i] = (unsigned char) c;
	return (s);
}
// */
