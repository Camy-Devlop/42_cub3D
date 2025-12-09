/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:08:15 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 13:11:37 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	is_deli(unsigned char c, const char *deli);

size_t	ft_strlen3(const char *s, const char *deli)
{
	size_t	len;

	if (!s)
		return (0);
	len = -1;
	while (s[++len] && !is_deli((unsigned char)s[len], deli))
		;
	return (len);
}

static int	is_deli(unsigned char c, const char *deli)
{
	return (c == (unsigned char)deli[0] || c == (unsigned char)deli[1]);
}
