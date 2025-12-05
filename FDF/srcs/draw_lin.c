/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:11:43 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/07 21:01:51 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minilibx/minilibx-linux/mlx.h"

#include "fdf.h"
#include "fdf_macros.h"
#include <math.h>

static bool	is_pix_valid(t_point3d pix);
int			generate_pix_color(int begclr, int endclr, int pix_cnt, int pix);
static bool	draw_pix(t_meta *meta, t_point3d pix);

/*
*	This function checks if the whole line is out of the window to avoid the
*	operations and getting better the performance.
*	Then calculate all the point of the line with the Bresenham's line algorithm
*/

void	draw_lin(t_meta *meta, t_point3d beg, t_point3d end)
{
	t_point3d	delta;
	t_point3d	pix;
	int			pixs;
	int			pix_cnt;

	if (is_pix_valid(beg) == 0 && is_pix_valid(end) == 0)
		return ;
	delta.pnt3d[X] = end.pnt3d[X] - beg.pnt3d[X];
	delta.pnt3d[Y] = end.pnt3d[Y] - beg.pnt3d[Y];
	pixs = (int) sqrt((delta.pnt3d[X] * delta.pnt3d[X])
			+ (delta.pnt3d[Y] * delta.pnt3d[Y]));
	pix_cnt = pixs;
	delta.pnt3d[X] /= pix_cnt;
	delta.pnt3d[Y] /= pix_cnt;
	pix.pnt3d[X] = beg.pnt3d[X];
	pix.pnt3d[Y] = beg.pnt3d[Y];
	pix.clr = 21845;
	while (pixs > 0)
	{
		pix.clr = generate_pix_color(beg.clr, end.clr, pix_cnt, pix_cnt - pixs);
		draw_pix(meta, pix);
		pix.pnt3d[X] += delta.pnt3d[X];
		pix.pnt3d[Y] += delta.pnt3d[Y];
		--pixs;
	}
}

/*
*	This function checks if the point is in the windows limit to avoid draw it
*/

static bool	is_pix_valid(t_point3d pix)
{
	if (pix.pnt3d[X] < 0 || pix.pnt3d[X] > WIN_W)
		return (0);
	if (pix.pnt3d[Y] < 0 || pix.pnt3d[Y] > WIN_H)
		return (0);
	return (1);
}

void		set_color(char *buf, int endian, int color, int alpha);

/*
*	This function calculate the position of the pixel in the img array:
*		array_pixe_position = pixel.axis[y] * WINX * 4 + 4 * pixel.axis[y]
*	and fill the 4 colorbytes calling the set_color function
*/
static bool	draw_pix(t_meta *meta, t_point3d pix)
{
	int	pix_val;
	int	alpha;

	alpha = 0;
	if (pix.pnt3d[X] < MENU_WID)
		alpha = -10;
	if (pix.pnt3d[X] >= WIN_W || pix.pnt3d[Y] >= WIN_H
		|| pix.pnt3d[X] < 0 || pix.pnt3d[Y] < 0)
		return (0);
	pix_val = ((int) pix.pnt3d[Y] * WIN_W * 4) + ((int) pix.pnt3d[X] * 4);
	if (meta->map_img.pix != 32)
		pix.clr = mlx_get_color_value(meta->fdf_mlx.mlx, pix.clr);
	set_color(&meta->map_img.buf[pix_val],
		meta->map_img.endian, pix.clr, alpha);
	return (1);
}
