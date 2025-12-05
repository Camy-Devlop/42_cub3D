/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_backg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:03:48 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/07 19:32:25 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minilibx/minilibx-linux/mlx.h"

#include "fdf.h"
#include "fdf_macros.h"

void		set_color(char *buf, int endian, int color, int alpha);

/*
*	This function generate all the pixel colors and fill the img array propertly
*/

void	clear_backg(t_meta *meta, int backgclr, int menuclr)
{
	int	x;
	int	y;
	int	clr;
	int	pix;

	if (meta->map_img.pix != 32)
		backgclr = mlx_get_color_value(meta->fdf_mlx.mlx, backgclr);
	if (meta->map_img.pix != 32)
		menuclr = mlx_get_color_value(meta->fdf_mlx.mlx, menuclr);
	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			if (x < MENU_WID)
				clr = menuclr;
			else
				clr = backgclr;
			pix = (y * meta->map_img.lin_cnt) + (x * 4);
			set_color(&meta->map_img.buf[pix], meta->map_img.endian, clr, 1);
		}
	}
}

void	cpy_map(t_map_units *map)
{
	t_point3d	*src;
	t_point3d	*dst;
	size_t		i;

	src = map->pnts;
	dst = map->pnts_cpy;
	i = -1;
	while (++i < map->pnts_cnt)
		dst[i] = src[i];
}
