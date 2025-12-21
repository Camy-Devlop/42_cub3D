/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:04:03 by alephoen          #+#    #+#             */
/*   Updated: 2025/11/22 13:02:04 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// !You should refactor your ft_close_fd()
// !it should be like this: ft_close_fd(int *fd)
void	ft_close_fd(int *fd)
{
	if (*fd >= 0)
	{
		close(*fd);
		*fd = -1;
	}
}
