/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_get_next_line_utils1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:44:02 by alephoen          #+#    #+#             */
/*   Updated: 2025/11/24 16:11:05 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <get_next_line.h>

// size_t	ft_memjoin(void const **s1, void const *s2,
// 			size_t s1len, size_t s2len)
// {
// 	char	*s;

// 	if (!(*s1) && !s2)
// 		return (0);
// 	if (!s1len && !s2len)
// 		return (0);
// 	if (s1len > SIZE_MAX - 1)
// 		return (0);
// 	if (!(*s1))
// 		s1len = 0;
// 	if (!s2)
// 		s2len = 0;
// 	s = (char *) malloc(sizeof(char) * (s1len + s2len + 1));
// 	if (!s)
// 	{
// 		*s1 = NULL;
// 		return (0);
// 	}
// 	s[s1len + s2len] = '\0';
// 	ft_memcpy(s, *(s1), s1len);
// 	ft_memcpy(s + s1len, s2, s2len);
// 	*s1 = s;
// 	return (s1len + s2len);
// }

// void	*ft_memcpy(void *des, const void *src, size_t n)
// {
// 	size_t				i;
// 	unsigned char		*d;
// 	const unsigned char	*s;

// 	if (!des || !src)
// 		return (NULL);
// 	if (!n)
// 		return (des);
// 	d = (unsigned char *) des;
// 	s = (unsigned char *) src;
// 	i = -1;
// 	while (++i < n)
// 		d[i] = s[i];
// 	return (des);
// }

// void	*ft_memchr(const void *byt, int c, size_t n)
// {
// 	size_t				i;
// 	unsigned const char	*ub;
// 	unsigned char		uc;

// 	if (!byt)
// 		return (NULL);
// 	ub = (unsigned const char *)byt;
// 	uc = (unsigned char)c;
// 	i = -1;
// 	while (++i < n)
// 		if (ub[i] == uc)
// 			return ((void *)(ub + i));
// 	return (NULL);
// }

// void	*ft_memset(void *s, int c, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*p;

// 	p = (unsigned char *) s;
// 	i = -1;
// 	while (++i < n)
// 		p[i] = (unsigned char) c;
// 	return (s);
// }
