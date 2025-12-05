/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:18:36 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 22:54:07 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minilibx/minilibx-linux/mlx.h"

#include "fdf.h"
#include "fdf_macros.h"
#include <time.h>

static void	render_map(t_meta *meta, t_point3d *pnts, bool fit);

void		cpy_map(t_map_units *map);

static void	fit_screen(t_meta *meta, t_point3d *pnts);
void		update_map(t_meta *meta, t_point3d *pnts);
static bool	is_pnt_out_of_bound(t_point3d *pnts, size_t pnts_cnt);

/*
*	This function draw the proyection of map->points acording all
*	the modifiers (x,y,z, scale..). If fit = 1, will caculate the
*	scale needed to fit the screen.
*/

void		*ft_calloc(size_t n, size_t data_size);

void		clear_backg(t_meta *meta, int backgclr, int menuclr);
void		update_map(t_meta *meta, t_point3d *pnts);

void		draw_menu(t_meta *meta);

bool	draw_map(t_meta *meta, t_map_units *map, bool fit)
{
	t_point3d	*pts_src;
	t_point3d	*pts_cpy;
	clock_t		time;

	time = clock();
	pts_src = map->pnts;
	pts_cpy = map->pnts_cpy;
	++(meta->map.rendrin_cnt);
	clear_backg(meta, meta->map.colrs.bakrdcolr, meta->map.colrs.menucolr);
	cpy_map(map);
	update_map(meta, map->pnts_cpy);
	render_map(meta, pts_cpy, fit);
	mlx_put_image_to_window(
		meta->fdf_mlx.mlx, meta->fdf_mlx.win, meta->map_img.img, 0, 0);
	draw_menu(meta);
	time = clock() - time;
	return (1);
}

void		wire_map(t_meta *meta, t_point3d *pnts);

static void	render_map(t_meta *meta, t_point3d *pnts, bool fit)
{
	(void) fit;
	if (fit)
		fit_screen(meta, meta->map.pnts_cpy);
	if (meta->map.lins_on)
		wire_map(meta, pnts);
}

/*
*	This function iterate n times until get the scale needed
*	to fit the screen.
*/
static void	fit_screen(t_meta *meta, t_point3d *pnts)
{
	meta->map.trans_cent.pnt3d[X] = ((WIN_W - MENU_WID) / 2) + MENU_WID;
	meta->map.trans_cent.pnt3d[Y] = WIN_H / 2;
	meta->map.trans_cent.pnt3d[Z] = 0;
	meta->map.zoom_scal = 1;
	cpy_map(&(meta->map));
	update_map(meta, pnts);
	while (!(is_pnt_out_of_bound(pnts, meta->map.pnts_cnt)))
	{
		cpy_map(&(meta->map));
		update_map(meta, pnts);
		meta->map.zoom_scal += 0.2;
	}
}

/*
*	This function checks if any point is out of the limits of the screen
*/
static bool	is_pnt_out_of_bound(t_point3d *pnts, size_t pnts_cnt)
{
	size_t	i;

	i = -1;
	while (++i < pnts_cnt)
	{
		if (pnts[i].pnt3d[X] < (MENU_WID + FIT_MARG)
			|| pnts[i].pnt3d[X] > (WIN_W - FIT_MARG))
			return (1);
		if (pnts[i].pnt3d[Y] < FIT_MARG
			|| pnts[i].pnt3d[Y] > (WIN_H - FIT_MARG))
			return (1);
	}
	return (0);
}
