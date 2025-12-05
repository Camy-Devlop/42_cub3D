/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:08:37 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 22:56:56 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minilibx/minilibx-linux/mlx.h"

#include "fdf.h"
#include "fdf_macros.h"
#include "fdf_colors.h"
#include "fdf_errors.h"
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <math.h>
#include <errno.h>

void		init_map(t_map_units *map, bool new);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
void		ft_put_str(int fd, char *str, int end_line_flag);
char		*get_map_data(int fd, t_map_units *map);
void		ft_close_fd(int fd);
void		print_error(int fd, int err_n, int end_line_flag);
void		parse_map(t_meta *meta, t_map_units *map);
void		set_pnts_colors(t_map_units *map);
static void	setup_polar(t_map_units *map);
void		*clean_n_exit(t_meta *meta, int err);

bool	load_map(t_meta *meta, t_map_units *map, char *path)
{
	int	fd;

	init_map(map, 1);
	fd = open(path, O_RDONLY);
	if (fd == -1 || ft_strncmp(path + ft_strlen(path) - 4, ".fdf", 4))
	{
		ft_put_str(2, "can't open file or extension .fdf is incorrect\n", 0);
		exit(1);
	}
	map->map_data = get_map_data(fd, map);
	ft_close_fd(fd);
	if (!map->map_data)
	{
		if (errno)
			print_error(2, 0, 2);
		else
			print_error(2, map->pars_err, 1);
		return (0);
	}
	parse_map(meta, map);
	set_pnts_colors(map);
	setup_polar(map);
	return (1);
}

int			parse_map_size(t_meta *meta);
int			parse_map_pnts(t_meta *meta);
static void	dup_map(t_meta *meta);

void	parse_map(t_meta *meta, t_map_units *map)
{
	(void) map;
	parse_map_size(meta);
	parse_map_pnts(meta);
	dup_map(meta);
}

void		*ft_calloc(size_t n, size_t data_size);

static void	dup_map(t_meta *meta)
{
	t_point3d	*src;
	t_point3d	*dst;
	size_t		i;

	src = meta->map.pnts;
	dst = (t_point3d *) ft_calloc(meta->map.pnts_cnt, sizeof(t_point3d));
	if (!dst)
		clean_n_exit(meta, ERROR_N_SYS_CALL);
	i = -1;
	while (++i < meta->map.pnts_cnt)
		dst[i] = src[i];
	meta->map.pnts_cpy = dst;
}

static void	setup_polar(t_map_units *map)
{
	size_t	i;
	float	stp_x;
	float	stp_y;

	stp_x = (M_PI * 2) / (map->map_limits.x_max - 1);
	stp_y = M_PI / map->map_limits.y_max;
	map->radius = map->map_limits.x_max / (M_PI * 2);
	i = -1;
	while (++i < map->pnts_cnt)
	{
		map->pnts[i].ang.lng = -(map->pnts[i].pnt3d[X]) * stp_x;
		if (map->pnts[i].pnt3d[Y] > 0)
			map->pnts[i].ang.lat = ((map->pnts[i].pnt3d[Y]
						+ (map->map_limits.y_max / 2)) * stp_y) - (0.5 * stp_y);
		else
			map->pnts[i].ang.lat = ((map->pnts[i].pnt3d[Y]
						+ (map->map_limits.y_max / 2) - 1) * stp_y)
				+ (0.5 * stp_y);
	}
}
