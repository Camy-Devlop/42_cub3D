/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_get_next_line_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:14:45 by alephoen          #+#    #+#             */
/*   Updated: 2025/11/24 13:06:08 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

void	*cleanup_gnl_buffer(t_gnl_buf **buffers, int fd)
{
	if (buffers[fd])
	{
		free(buffers[fd]);
		buffers[fd] = NULL;
	}
	return (NULL);
}

void	update_linlen_at_eol(t_gnl_buf *buf)
{
	buf->linlen += buf->len;
	buf->len = 0;
}

void	get_gnl_line_free_tmp(t_gnl_buf *buf, char **lin, char *tmp)
{
	if (!(*lin))
		buf->ero = 1;
	free(tmp);
}
