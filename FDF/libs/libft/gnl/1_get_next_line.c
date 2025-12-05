/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_get_next_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:20:43 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 23:07:51 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl_buf	*getbuffer(int fd, t_gnl_buf **buf, t_gnl_buf ***gnl_bufers)
{
	if (fd < 0 || OPEN_MAX <= fd || BUFFER_SIZE > SSIZE_MAX)
		return (NULL);
	if (!buf[fd])
	{
		buf[fd] = malloc(sizeof(t_gnl_buf));
		if (!buf[fd])
			return (NULL);
		ft_memset(buf[fd], 0, sizeof(t_gnl_buf));
		buf[fd]->fd = fd;
		buf[fd]->bi = buf[fd]->buf;
		if (gnl_bufers)
			*gnl_bufers = buf;
	}
	else if (buf[fd]->bi == NULL)
	{
		buf[fd]->fd = fd;
		buf[fd]->bi = buf[fd]->buf;
	}
	buf[fd]->len = 0;
	return (buf[fd]);
}

static int	check_read_error(t_gnl_buf *buf)
{
	char	bf[1];

	if (read(buf->fd, bf, 0) == -1)
	{
		buf->ero = 1;
		return (1);
	}
	else if (buf->byt_r == 0)
	{
		buf->eof = 1;
		return (1);
	}
	return (0);
}

void	get_line_free_tmp(t_gnl_buf *buf, char **lin, char *tmp);

// You can add this extra protection inside get_line()
// but its not needed to pass this project.
	// if (buf->len >= SIZE_MAX - ilen)
	// {
	// 	buf->ero = 1;
	// 	buf->len = 0;
	// 	if (tmp)
	// 		free(tmp);
	// 	return (NULL);
	// }
static char	*get_line(t_gnl_buf *buf, char **lin, size_t linlen, size_t ilen)
{
	char	*tmp;

	tmp = *lin;
	buf->len = ft_memjoin((const void **)lin, buf->bi, linlen, ilen);
	get_line_free_tmp(buf, lin, tmp);
	buf->linlen = buf->len;
	if (!buf->ero && buf->eol && (buf->eol - buf->bi) < BUFFER_SIZE && buf->fd)
	{
		if (BUFFER_SIZE == 1)
		{
			if (buf->bi + ilen < buf->buf + BUFFER_SIZE && ilen > 1)
				buf->bi += ilen;
		}
		else
		{
			if (buf->bi + ilen < buf->buf + BUFFER_SIZE)
				buf->bi += ilen;
			else
				buf->bi = buf->buf;
		}
	}
	else if (!buf->ero)
		buf->bi = buf->buf;
	return (*lin);
}

// You can add this as extra protection under read() in the function
// below but its not needed to pass this project.
			// if (check_read_error(buf))
			// {
			// 	if (buf->ero)
			// 		return (NULL);
			// 	else
			// 		return (*lin);
			// }
static char	*read_until_eol_or_eof(
				t_gnl_buf *buf, int fd, size_t *linlen, char **lin)
{
	while (!buf->eof && !buf->eol)
	{
		*lin = get_line(buf, lin, buf->len, buf->byt_r - (buf->bi - buf->buf));
		if (buf->ero || !(*lin))
			return (NULL);
		if (buf->bi == buf->buf)
		{
			buf->byt_r = read(fd, buf->buf, BUFFER_SIZE);
			if (check_read_error(buf))
				return (*lin);
		}
		buf->eol = ft_memchr(buf->bi, '\n', buf->byt_r - (buf->bi - buf->buf));
		if (check_read_error(buf))
			return (NULL);
		if (buf->eol || buf->byt_r < BUFFER_SIZE)
		{
			if (BUFFER_SIZE > 1 && buf->eol)
				*lin = get_line(buf, lin, buf->len, buf->eol - buf->bi + 1);
			else
				*lin = get_line(buf, lin, buf->len, buf->byt_r);
			update_linlen_at_eol(buf, linlen);
			return (*lin);
		}
	}
	return (NULL);
}

char	*get_next_line(
			int fd, char **line, size_t *linlen, t_gnl_buf ***gnl_bufers)
{
	static t_gnl_buf	*buffers[OPEN_MAX];
	t_gnl_buf			*buf;
	char				*lin;

	lin = NULL;
	*line = lin;
	*linlen = 0;
	buf = getbuffer(fd, buffers, gnl_bufers);
	if (!buf || read(fd, buf->buf, 0) == -1 || buf->ero)
		return (cleanup_buffer(buffers, fd));
	if (((buf->bi == buf->buf) || (buf->eol == buf->buf + BUFFER_SIZE - 1)))
	{
		buf->byt_r = read(fd, buf->buf, BUFFER_SIZE);
		if (check_read_error(buf))
			return (cleanup_buffer(buffers, fd));
	}
	buf->eol = ft_memchr(buf->bi, '\n', buf->byt_r - (buf->bi - buf->buf));
	if (check_read_error(buf))
		return (cleanup_buffer(buffers, fd));
	if (buf->eol)
		return (get_line(buf, &lin, buf->len, buf->eol - buf->bi + 1));
	lin = read_until_eol_or_eof(buf, fd, linlen, &lin);
	if (!lin && buf->ero)
		return (cleanup_buffer(buffers, fd));
	return (lin);
}
