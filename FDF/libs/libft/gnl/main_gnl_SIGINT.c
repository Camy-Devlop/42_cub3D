/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl_SIGINT.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 03:34:00 by alephoen          #+#    #+#             */
/*   Updated: 2025/08/22 13:47:39 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "get_next_line.h"
#include "signal_handler.h"
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	t_gnl_buf	**gnl_bufers;
	char		*line;
	int			fd;
	char		buf[1];

	set_sigint_handler();
	fd = open("get_next_line.c", O_RDWR);
	while (1)
	{
		if (get_is_sigint())
		{
			cleanup_buffer(gnl_bufers, fd);
			// if (line)
			// 	free(line);
			exit(1);
		}
		line = get_next_line(fd, &line, &gnl_bufers);
		if (!line)
			break ;
		printf("%s", line);
		read(0, buf, 1);
		free(line);
	}
	return (0);
}
*/
