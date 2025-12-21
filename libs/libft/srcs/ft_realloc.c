/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:03:51 by alephoen          #+#    #+#             */
/*   Updated: 2025/12/06 01:11:01 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static void	*ft_free(void **ptr);

char	*ft_realloc(char **s, size_t slen, size_t len)
{
	size_t	i;
	char	*new;

	if (slen >= len)
		return (NULL);
	*new = (char *) malloc((len + 1) * sizeof(char));
	if (!new)
		return (ft_free((void **) s), NULL);
	i = -1;
	while (++i < slen)
		new[i] = (*s)[i];
	new[i] = '\0';
	ft_free((void **) s);
	return (new);
}

static void	*ft_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}
