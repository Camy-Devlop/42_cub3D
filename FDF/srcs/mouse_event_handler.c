/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:06:09 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/08 16:12:05 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_macros.h"

#include <stdio.h>

bool		draw_map(t_meta *meta, t_map_units *map, bool fit);

/*
*	This function handle every time a mouse button is pressed
*/
int	mouse_press(int button, int x, int y, void *parm)
{
	t_meta	*meta;

	meta = (t_meta *) parm;
	if (button == 1)
	{
		meta->keys.mouse_l = 1;
		meta->keys.last_click_l.pnt3d[X] = x;
		meta->keys.last_click_l.pnt3d[Y] = y;
	}
	if (button == 2 || button == 3)
	{
		meta->keys.mouse_r = 1;
		meta->keys.last_click_r.pnt3d[X] = x;
		meta->keys.last_click_r.pnt3d[Y] = y;
	}
	if (button == 5)
		meta->map.zoom_scal /= 1.5;
	if (button == 4)
		meta->map.zoom_scal *= 1.5;
	draw_map(meta, &meta->map, 0);
	return (0);
}

/*
*	This function handle every time a mouse button is relased
*/

int	mouse_release(int button, int x, int y, void *parm)
{
	t_meta	*meta;

	(void) x;
	(void) y;
	meta = (t_meta *) parm;
	if (button == 1)
		meta->keys.mouse_l = 0;
	if (button == 2 || button == 3)
		meta->keys.mouse_r = 0;
	return (0);
}

static void	mouse_move_r(t_meta *meta, int x, int y);
static void	mouse_move_l(t_meta *meta, int x, int y);

int	mouse_move(int x, int y, void *parm)
{
	t_meta	*meta;

	meta = (t_meta *) parm;
	if (x > WIN_W || x < 0 || y > WIN_H || y < 0)
		return (0);
	if (meta->keys.mouse_r)
		mouse_move_r(meta, x, y);
	if (meta->keys.mouse_l)
		mouse_move_l(meta, x, y);
	return (0);
}

static void	mouse_move_r(t_meta *meta, int x, int y)
{
	meta->map.trans_cent.pnt3d[X]
		-= ((int) meta->keys.last_click_r.pnt3d[X] - x);
	meta->map.trans_cent.pnt3d[Y]
		-= ((int) meta->keys.last_click_r.pnt3d[Y] - y);
	meta->map.trans_cent.pnt3d[Z] = 0;
	meta->keys.last_click_r.pnt3d[X] = x;
	meta->keys.last_click_r.pnt3d[Y] = y;
	meta->map.rotate_on = 1;
	draw_map(meta, &meta->map, 0);
}

void		rotate(float *ang, float value);

static void	mouse_move_l(t_meta *meta, int x, int y)
{
	float	dx;
	float	dy;

	dx = ((int) meta->keys.last_click_l.pnt3d[X] - x) * 0.08F;
	dy = ((int) meta->keys.last_click_l.pnt3d[Y] - y) * 0.08F;
	rotate(&meta->map.rot_angs[X], -dy);
	rotate(&meta->map.rot_angs[Y], dx);
	meta->keys.last_click_l.pnt3d[X] = x;
	meta->keys.last_click_l.pnt3d[Y] = y;
	draw_map(meta, &meta->map, 0);
}
