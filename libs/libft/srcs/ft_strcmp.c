/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:08:04 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/16 14:37:22 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;
	unsigned const char	*us1;
	unsigned const char	*us2;

	us1 = (unsigned const char *) s1;
	us2 = (unsigned const char *) s2;
	i = -1;
	while (us1[++i] && us2[i] && us1[i] == us2[i])
		;
	return ((int)(us1[i] - us2[i]));
}
