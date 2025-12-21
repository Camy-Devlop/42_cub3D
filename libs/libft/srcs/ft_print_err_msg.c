/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_err_msg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:46:59 by alephoen          #+#    #+#             */
/*   Updated: 2025/10/29 18:07:26 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

static size_t	ft_fd_putstr(int fd, const char *str);

void	ft_print_err_msg(const char *cmd, const char *file, const char *str)
{
	int	fd;

	fd = STDERR_FILENO;
	ft_fd_putstr(fd, "minishell: ");
	if (cmd)
	{
		ft_fd_putstr(fd, cmd);
		ft_fd_putstr(fd, ": ");
	}
	if (file)
	{
		ft_fd_putstr(fd, file);
		ft_fd_putstr(fd, ": ");
	}
	if (str)
		ft_fd_putstr(fd, str);
	else
		perror(NULL);
}

static size_t	ft_fd_putstr(int fd, const char *str)
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
