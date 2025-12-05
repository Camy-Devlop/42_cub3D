/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wire_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:22:15 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/07 21:10:21 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	wire_lin(t_meta *meta, t_point3d *pnts, int density, int lin);

void	wire_map(t_meta *meta, t_point3d *pnts)
{
	int	i;
	int	density;

	density = 8 / meta->map.zoom_scal;
	if (density == 0)
		density = 1;
	i = 0;
	while (i < (int) meta->map.pnts_cnt)
	{
		wire_lin(meta, &(pnts[i]), density,
			(int)(i / meta->map.map_limits.x_max));
		i += (int) meta->map.map_limits.x_max * density;
	}
}

void		draw_lin(t_meta *meta, t_point3d beg, t_point3d end);

static void	wire_lin(t_meta *meta, t_point3d *pnts, int density, int lin)
{
	int	i;
	int	x_end;
	int	y_end;

	i = 0;
	while (i < (int) meta->map.map_limits.x_max)
	{
		x_end = i + density;
		if (x_end >= (int) meta->map.map_limits.x_max)
			x_end = (int) meta->map.map_limits.x_max - 1;
		y_end = i + (int) meta->map.map_limits.x_max * density;
		if (pnts[i].b_paint)
		{
			draw_lin(meta, pnts[i], pnts[x_end]);
			if (lin + density < (int) meta->map.map_limits.y_max)
				draw_lin(meta, pnts[i], pnts[y_end]);
		}
		i += density;
	}
}
