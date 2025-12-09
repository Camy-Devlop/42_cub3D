/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:35:25 by alephoen          #+#    #+#             */
/*   Updated: 2025/08/28 17:11:25 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// /*
// #include "libft.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *s);
void			ft_strcpy(char *des, const char *src);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*s;
	char	empty;

	if (!s1 && !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s1len > SIZE_MAX - s2len - 1)
		return (NULL);
	s = (char *) malloc(sizeof(char) * (s1len + s2len + 1));
	if (!s)
		return (NULL);
	empty = '\0';
	if (!s1)
		s1 = &empty;
	if (!s2)
		s2 = &empty;
	ft_strcpy(s, s1);
	ft_strcpy(s + s1len, s2);
	return (s);
}

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = -1;
	while (s[++len])
		;
	return (len);
}

void	ft_strcpy(char *des, const char *src)
{
	size_t	i;

	if (!des || !src)
		return ;
	i = -1;
	while (src[++i])
		des[i] = src[i];
	des[i] = '\0';
}
// */
