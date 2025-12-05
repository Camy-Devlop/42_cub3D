/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:21:37 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 13:08:50 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

size_t				ft_strlen3(const char *s, const char *deli);
static size_t		cntsubstr(const char *s, const char *deli, size_t len);
static char			**createsplits(
						char **s, const char *str, const char *deli, size_t n);
static const char	*skip_delimeters(const char *str, const char *deli);

/*
	if len = 0  then no splits will be created;
	if len = -1 then splits will be created until end of str;
	if 0 < len < -1 then splits will be created up to len bytes;
*/

/*
	if len = 0  then no splits will be created;
	if len = -1 then splits will be created until end of str;
	if 0 < len < -1 then splits will be created up to len bytes;
*/
char	**ft_split2_n(const char *str, const char *deli, size_t len)
{
	char	**s;
	size_t	n;

	if (!str || !len)
		return (NULL);
	str = skip_delimeters(str, deli);
	if (!(*str))
		return (NULL);
	n = cntsubstr(str, deli, len);
	s = (char **)malloc(sizeof(char *) * (n + 1));
	if (!s)
		return (NULL);
	s = createsplits(s, str, deli, n);
	return (s);
}

static int	is_deli(unsigned char c, const char *deli)
{
	return (c == (unsigned char)deli[0] || c == (unsigned char)deli[1]);
}

static const char	*skip_delimeters(const char *str, const char *deli)
{
	while (*str && is_deli((unsigned char)*str, deli))
		++str;
	return (str);
}

static size_t	cntsubstr(const char *s, const char *deli, size_t len)
{
	size_t				n;
	size_t				i;
	const unsigned char	*us;

	us = (const unsigned char *)skip_delimeters(s, deli);
	if (!*us)
		return (0);
	n = 1;
	i = 0;
	while (*us && i < len)
	{
		if (is_deli(*us, deli) && *(us + 1) && !is_deli(*(us + 1), deli))
			++n;
		++us;
		if (len != (size_t)(-1))
			++i;
	}
	return (n);
}

static char	**createsplits(
				char **s, const char *str, const char *deli, size_t n)
{
	size_t	i;
	size_t	sublen;

	i = -1;
	while (++i < n && *str)
	{
		sublen = ft_strlen3(str, deli);
		s[i] = ft_substr(str, 0, sublen);
		if (!s[i])
		{
			ft_free2dstr(s);
			return (NULL);
		}
		str += sublen;
		str = skip_delimeters(str, deli);
	}
	s[i] = NULL;
	return (s);
}
