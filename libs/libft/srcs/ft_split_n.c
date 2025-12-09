/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:21:37 by alephoen          #+#    #+#             */
/*   Updated: 2025/08/29 15:51:55 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen2(const char *s, char c);
static size_t	cntsubstr(const char *s, char c, size_t len);
static char		**createsplits(char **s, const char *str, int c, size_t n);

/*
	if len = 0  then no splits will be created;
	if len = -1 then splits will be created until end of str;
	if 0 < len < -1 then splits will be created up to len bytes;
*/
char	**ft_split_n(const char *str, char c, size_t len)
{
	char	**s;
	size_t	n;

	if (!str)
		return (NULL);
	while (*str && (unsigned char)*str == (unsigned char)c)
		++str;
	n = cntsubstr(str, c, len);
	if (!(*str))
		n = 0;
	s = (char **)malloc(sizeof(char *) * (n + 1));
	if (!s)
		return (NULL);
	s = createsplits(s, str, c, n);
	return (s);
}

static size_t	cntsubstr(const char *s, char c, size_t len)
{
	size_t				n;
	size_t				i;
	unsigned char		uc;
	const unsigned char	*us;

	if (!s || !(*s))
		return (0);
	while (*s && (unsigned char)*s == (unsigned char)c)
		++(s);
	uc = (unsigned char)c;
	us = (const unsigned char *)s;
	n = 1;
	i = 0;
	while (*us && i < len)
	{
		if (*us == uc && *(us + 1) != uc && *(us + 1))
			++n;
		++us;
		if (len != (size_t)(-1))
			++i;
	}
	return (n);
}

static char	**createsplits(char **s, const char *str, int c, size_t n)
{
	size_t	i;
	size_t	sublen;

	i = -1;
	while (++i < n && *str)
	{
		sublen = ft_strlen2(str, c);
		s[i] = ft_substr(str, 0, sublen);
		if (!s[i])
		{
			ft_free2dstr(s);
			return (NULL);
		}
		str += sublen;
		while (*str && (unsigned char)*str == (unsigned char)c)
			++str;
	}
	s[i] = NULL;
	return (s);
}

static size_t	ft_strlen2(const char *s, char c)
{
	size_t	len;

	if (!s)
		return (0);
	len = -1;
	while (s[++len] && (unsigned char)s[len] != (unsigned char)c)
		;
	return (len);
}
