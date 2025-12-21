/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:56:28 by alephoen          #+#    #+#             */
/*   Updated: 2025/04/18 19:02:36 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*des;
	size_t	i;

	if (!src)
		return (NULL);
	des = (char *) malloc(sizeof(char) * (n + 1));
	if (!des)
		return (NULL);
	i = -1;
	while (++i < n && src[i])
		des[i] = src[i];
	des[i] = '\0';
	return (des);
}
