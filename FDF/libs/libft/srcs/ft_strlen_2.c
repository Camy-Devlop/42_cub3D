/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:22:41 by alephoen          #+#    #+#             */
/*   Updated: 2025/08/29 15:23:59 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen_2(const char *s, char c)
{
	size_t	len;

	if (!s)
		return (0);
	len = -1;
	while (s[++len] && (unsigned char)s[len] != (unsigned char)c)
		;
	return (len);
}
