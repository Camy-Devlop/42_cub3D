/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:21:37 by alephoen          #+#    #+#             */
/*   Updated: 2025/10/16 00:12:39 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// /*
// #include "libft.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

static size_t	ft_strlen2(const char *s, int c);
static size_t	cntsubstr(const char *s, char c);
static char		**createsplits(char **s, const char *str, int c[2], size_t n);
char			*ft_substr2(
					char const *src,
					unsigned int beg,
					size_t len, bool expan);
void			*ft_free2dstr(char **s);

char	**ft_split2(const char *str, char c, char replace)
{
	char	**s;
	int		cc[2];
	size_t	n;

	if (!str)
		return (NULL);
	while (*str && (unsigned char)*str == (unsigned char)c)
		++str;
	n = cntsubstr(str, c);
	if (!(*str))
		n = 0;
	s = (char **)malloc(sizeof(char *) * (n + 1));
	if (!s)
		return (NULL);
	cc[0] = c;
	cc[1] = replace;
	s = createsplits(s, str, cc, n);
	return (s);
}

static size_t	cntsubstr(const char *s, char c)
{
	size_t				n;
	unsigned char		uc;
	const unsigned char	*us;

	if (!s || !(*s))
		return (0);
	while (*s && (unsigned char)*s == (unsigned char)c)
		++(s);
	uc = (unsigned char)c;
	us = (const unsigned char *)s;
	n = 1;
	while (*us)
	{
		if (*us == uc && *(us + 1) != uc && *(us + 1))
			++n;
		++us;
	}
	return (n);
}

static char	**createsplits(char **s, const char *str, int c[2], size_t n)
{
	size_t	i;
	size_t	sublen;

	i = -1;
	while (++i < n && *str)
	{
		sublen = ft_strlen2(str, c[0]);
		if (str[sublen] != 0 && str[sublen] != c[0])
			++sublen;
		s[i] = ft_substr2(str, 0, sublen + 1, 1);
		if (s[i] && s[i][sublen] == (char) c[0])
			s[i][sublen] = (char) c[1];
		else if (s[i])
		{
			s[i][sublen - 1] = (char) c[1];
			s[i][sublen] = '\0';
		}
		if (!s[i])
			return (ft_free2dstr(s));
		str += sublen;
		while (*str && (unsigned char)*str == (unsigned char)c[0])
			++str;
	}
	s[i] = NULL;
	return (s);
}

static size_t	ft_strlen2(const char *s, int c)
{
	size_t	len;

	if (!s)
		return (0);
	len = -1;
	while (s[++len] && (unsigned char)s[len] != (unsigned char)c)
		;
	return (len);
}
// */
