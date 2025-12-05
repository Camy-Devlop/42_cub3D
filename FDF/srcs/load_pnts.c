/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_pnts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:40:19 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 23:30:00 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_macros.h"
#include "fdf_colors.h"

long int		ft_strtol(const char *str, const char **endptr, int base);
static void		setup_pnts(t_map_units *map, size_t *pnt_idx, t_idx idx);
int				ft_hex2uint(const char *hex);

void	load_pnts(t_map_units *map)
{
	t_idx		idx;
	size_t		pnt_idx;
	const char	*endptr;

	pnt_idx = 0;
	idx.j = -1;
	while (++idx.j < map->map_limits.y_max)
	{
		idx.i = -1;
		while (++idx.i < map->map_limits.x_max)
		{
			map->pnts[pnt_idx].pnt3d[Z]
				= ft_strtol(map->pnts[pnt_idx].z_str, &endptr, 1);
			map->pnts[pnt_idx].z_origin = map->pnts[pnt_idx].pnt3d[Z];
			if (map->pnts[pnt_idx].hex_str)
				map->pnts[pnt_idx].hex_clr
					= ft_hex2uint(map->pnts[pnt_idx].hex_str);
			setup_pnts(map, &pnt_idx, idx);
		}
	}
}

static void	setup_pnts(t_map_units *map, size_t *pnt_idx, t_idx idx)
{
	map->pnts[*pnt_idx].pnt3d[X] = idx.i - (map->map_limits.x_max / 2);
	map->pnts[*pnt_idx].pnt3d[Y] = idx.j - (map->map_limits.y_max / 2);
	map->pnts[*pnt_idx].b_paint = 1;
	map->pnts[*pnt_idx].clr = DEFAULT_COLOR;
	if (map->map_limits.z_max < map->pnts[*pnt_idx].pnt3d[Z])
		map->map_limits.z_max = map->pnts[*pnt_idx].pnt3d[Z];
	if (map->z_min_4_colrs > map->pnts[*pnt_idx].pnt3d[Z])
		map->z_min_4_colrs = map->pnts[*pnt_idx].pnt3d[Z];
	if (map->pnts[*pnt_idx].pnt3d[Z])
		map->pnts[*pnt_idx].z_scal_on = 1;
	++(*pnt_idx);
}
