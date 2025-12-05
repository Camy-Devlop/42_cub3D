/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2dstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:00:13 by alephoen          #+#    #+#             */
/*   Updated: 2025/08/29 19:51:40 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_free2dstr(char ***s)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	while ((*s)[++i])
	{
		free((*s)[i]);
		(*s)[i] = NULL;
	}
	free(*s);
	*s = NULL;
	return (NULL);
}
