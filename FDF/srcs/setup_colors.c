/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:53:44 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/09 17:33:10 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_macros.h"
#include "fdf_colors.h"
#include "key_macros.h"

void	load_color(int max, int min, t_point3d *pnt, t_colrs clrs);

void	set_pnts_colors(t_map_units *map)
{
	size_t	i;

	i = -1;
	while (++i < map->pnts_cnt)
		load_color(
			(int) map->map_limits.z_max,
			map->z_min_4_colrs, &map->pnts[i], map->colrs);
}

/*
*	Acording the z value of the point and de max and min values of the map
*	this function set the color needed of the point received.
*	All the colors are defined in fdf.h
*/
void	load_color(int max, int min, t_point3d *pnt, t_colrs clrs);

void	update_colors(t_map_units *map)
{
	size_t	i;

	i = -1;
	while (++i < map->pnts_cnt)
		load_color(
			(int) map->map_limits.z_max,
			map->z_min_4_colrs, &map->pnts[i], map->colrs);
}

int		generate_pix_color(int begclr, int endclr, int pix_cnt, int pix);

void	load_color(int max, int min, t_point3d *pnt, t_colrs clrs)
{
	pnt->b_paint = 1;
	pnt->clr = DEFAULT_COLOR;
	if (pnt->hex_clr > 0)
	{
		pnt->clr = pnt->hex_clr;
		return ;
	}
	if (pnt->pnt3d[Z] == max)
		pnt->clr = clrs.topcolr;
	else if (pnt->pnt3d[Z] == 0)
		pnt->clr = clrs.grundcolr;
	else if (pnt->pnt3d[Z] == min && min != 0)
		pnt->clr = clrs.bottmcolr;
	else if (pnt->pnt3d[Z] > 0)
		pnt->clr = generate_pix_color(
				clrs.grundcolr, clrs.topcolr, max, pnt->pnt3d[Z]);
	else
		pnt->clr = generate_pix_color(
				clrs.bottmcolr, clrs.grundcolr,
				-min, -(min - pnt->pnt3d[Z]));
}

/*
*	This function fills 4 bytes of the given address whith the values of colors
*	depending the andian
*      endian = 1 --> Most significant (Alpha) byte first
*      endian = 0 --> Least significant (Blue) byte first
*/
void	set_color(char *buf, int endian, int color, int alpha)
{
	if (endian == 1)
	{
		buf[0] = alpha;
		buf[1] = (color >> 16) & 0xFF;
		buf[2] = (color >> 8) & 0xFF;
		buf[3] = (color) & 0xFF;
	}
	else
	{
		buf[0] = (color) & 0xFF;
		buf[1] = (color >> 8) & 0xFF;
		buf[2] = (color >> 16) & 0xFF;
		buf[3] = alpha;
	}
}

int		ft_int_round(double x);

int	generate_pix_color(int begclr, int endclr, int pix_cnt, int pix)
{
	double	incrmt[3];
	int		new[3];
	int		newclr;

	incrmt[0] = (double)((endclr >> 16) - ((begclr >> 16))) / (double) pix_cnt;
	incrmt[1] = (double)(((endclr >> 8) & 0xFF)
			- ((begclr >> 8) & 0xFF)) / (double) pix_cnt;
	incrmt[2] = (double)((endclr & 0xFF) - (begclr & 0xFF)) / (double) pix_cnt;
	new[0] = (begclr >> 16) + ft_int_round(pix * incrmt[0]);
	new[1] = ((begclr >> 8) & 0xFF) + ft_int_round(pix * incrmt[1]);
	new[2] = (begclr & 0xFF) + ft_int_round(pix * incrmt[2]);
	newclr = (new[0] << 16) + (new[1] << 8) + new[2];
	return (newclr);
}
