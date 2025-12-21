/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_putstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:47:54 by alephoen          #+#    #+#             */
/*   Updated: 2025/10/29 13:49:53 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

size_t	ft_fd_putstr(int fd, const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = -1;
	while (str[++len])
		;
	write(fd, str, len);
	return (len);
}
