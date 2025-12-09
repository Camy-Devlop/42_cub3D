/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:17:52 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 21:28:34 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <limits.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 5000000
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# if (BUFFER_SIZE < 0)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

typedef struct s_gnl_buf
{
	int			fd;
	int			ero;
	int			eof;
	size_t		len;
	size_t		linlen;
	ssize_t		byt_r;
	char		buf[BUFFER_SIZE];
	char		*eol;
	char		*bi;
}				t_gnl_buf;

// char	*get_next_line(int fd);
// char	*get_next_line(int fd, char **line, t_gnl_buf ***gnl_bufers);
char	*get_next_line(
			int fd, char **line, size_t *linlen, t_gnl_buf ***gnl_bufers);
size_t	ft_memjoin(void const **s1, void const *s2, size_t s1len, size_t s2len);
void	*ft_memchr(const void *byt, int c, size_t n);
void	*ft_memcpy(void *des, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*cleanup_buffer(t_gnl_buf **buffers, int fd);
void	update_linlen_at_eol(t_gnl_buf *buf, size_t *linlen);

#endif
