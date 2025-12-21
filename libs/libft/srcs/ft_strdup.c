/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:00:46 by alephoen          #+#    #+#             */
/*   Updated: 2025/11/16 16:30:11 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*des;
	size_t	srclen;
	size_t	i;

	if (!src)
		return (NULL);
	srclen = -1;
	while (src[++srclen])
		;
	des = (char *) malloc(sizeof(char) * (srclen + 1));
	if (!des)
		return (NULL);
	i = -1;
	while (++i < srclen)
		des[i] = src[i];
	des[i] = '\0';
	return (des);
}
