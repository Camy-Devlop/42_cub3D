/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:33:46 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/18 10:34:05 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*free_lst2d(void ***s_ptr, size_t n)
{
	void	**s;
	size_t	i;

	if (!s_ptr || !(*s_ptr))
		return (NULL);
	s = *s_ptr;
	i = -1;
	if (n)
	{
		while (++i < n && (s)[i])
			free((s)[i]);
	}
	else
	{
		while ((s)[i])
			free((s)[i]);
	}
	free(s);
	*s_ptr = NULL;
	return (NULL);
}
