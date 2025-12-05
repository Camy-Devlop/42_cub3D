/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:32:35 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 23:12:49 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "fdf.h"
#include "fdf_errors.h"
#include "../libs/libft/gnl/get_next_line.h"

char		*ft_strjoin(char const *s1, char const *s2);

static void	*clean_get_map_data(
				char *tmp1, char *lin, t_gnl_buf **buf, int fd);

static char	*end_of_reading(t_map_units *map, char *lin, int flag);

void		*ft_free(void **ptr);

size_t		ft_strlen(const char *s);

static void	free_tmp_data(char **tmp1, char **tmp2);

static void	init_get_map_data(t_get_map_data *data);

char	*get_map_data(int fd, t_map_units *map)
{
	t_get_map_data	data;

	init_get_map_data(&data);
	while (1)
	{
		data.tmp1 = get_next_line(fd, &data.tmp1, &data.tmp1_len, &data.buf);
		if (data.tmp1 && data.tmp1[0] == '\n')
		{
			map->pars_err = ERROR_N_PARSING_2;
			return (clean_get_map_data(data.tmp1, data.lin, data.buf, fd));
		}
		if (data.tmp1 && data.tmp1[data.buf[fd]->linlen - 1] != '\n')
		{
			end_of_reading(map, data.tmp1, 3);
			return (clean_get_map_data(data.tmp1, data.lin, data.buf, fd));
		}
		if (!data.tmp1)
			return (end_of_reading(map, data.lin, 1));
		data.tmp2 = data.lin;
		data.lin = ft_strjoin(data.tmp2, data.tmp1);
		free_tmp_data(&data.tmp1, &data.tmp2);
		if (!data.lin)
			return (end_of_reading(map, data.lin, 2));
	}
	return (data.lin);
}

static void	init_get_map_data(t_get_map_data *data)
{
	data->lin = NULL;
	data->tmp1 = NULL;
	data->tmp2 = NULL;
	data->tmp1_len = 0;
}

static void	free_tmp_data(char **tmp1, char **tmp2)
{
	tmp1 = ft_free((void **) tmp1);
	tmp2 = ft_free((void **) tmp2);
}

static char	*end_of_reading(t_map_units *map, char *lin, int flag)
{
	if (flag == 1)
	{
		if (errno)
			map->pars_err = ERROR_N_PARSING_0;
		if (!lin)
			map->pars_err = ERROR_N_PARSING_1;
		return (lin);
	}
	if (flag == 2)
	{
		if (errno)
			map->pars_err = ERROR_N_PARSING_0;
		return (lin);
	}
	if (flag == 3)
	{
		map->pars_err = ERROR_N_PARSING_7;
		return (NULL);
	}
	return (NULL);
}

static void	*clean_get_map_data(
				char *tmp1, char *lin, t_gnl_buf **buf, int fd)
{
	free(tmp1);
	free(lin);
	free(buf[fd]);
	return (NULL);
}
