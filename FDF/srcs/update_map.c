/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:20:47 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/08 16:13:23 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_macros.h"

void		update_z(t_meta *meta, t_point3d *pnts);

void		rotate_x(
				t_point3d *pnts, t_point3d *pnts_cpy,
				float ang, size_t pnts_cnt);

void		rotate_y(
				t_point3d *pnts, t_point3d *pnts_cpy,
				float ang, size_t pnts_cnt);

void		rotate_z(
				t_point3d *pnts, t_point3d *pnts_cpy,
				float ang, size_t pnts_cnt);

static void	scale_pnts(
				t_meta *meta, t_point3d *pnts, int scal, size_t pnts_cnt);

void		translate(t_point3d *pnts, t_point3d move, size_t pnts_cnt);

static void	z_division(t_point3d *pnts, float div, size_t pnts_cnt);

void	update_map(t_meta *meta, t_point3d *pnts)
{
	if (meta->map.z_scal_fix_on)
		z_division(pnts, meta->map.z_scal, meta->map.pnts_cnt);
	else if (meta->map.z_scal_on)
		update_z(meta, pnts);
	rotate_x(pnts, pnts, meta->map.rot_angs[X], meta->map.pnts_cnt);
	rotate_y(pnts, pnts, meta->map.rot_angs[Y], meta->map.pnts_cnt);
	rotate_z(pnts, pnts, meta->map.rot_angs[Z], meta->map.pnts_cnt);
	scale_pnts(meta, pnts, meta->map.zoom_scal, meta->map.pnts_cnt);
	translate(pnts, meta->map.trans_cent, meta->map.pnts_cnt);
}

static void	z_division(t_point3d *pnts, float div, size_t pnts_cnt)
{
	size_t	i;

	i = -1;
	while (++i < pnts_cnt)
		pnts[i].pnt3d[Z] = pnts[i].pnt3d[Z] / (div * 12);
}

void	update_z(t_meta *meta, t_point3d *pnts)
{
	size_t	i;

	i = -1;
	while (++i < meta->map.pnts_cnt)
	{
		if (pnts[i].z_scal_on)
		{
			pnts[i].pnt3d[Z] += meta->map.z_scal;
			meta->map.pnts[i].pnt3d[Z] = pnts[i].pnt3d[Z];
		}
	}
	meta->map.z_scal_on = 0;
}

/*
*	Iterates all the points and multiply by scale
*/

static void	scale_pnts(t_meta *meta, t_point3d *pnts, int scal, size_t pnts_cnt)
{
	size_t	i;

	i = -1;
	while (++i < pnts_cnt)
	{
		pnts[i].pnt3d[X] = pnts[i].pnt3d[X] * scal;
		pnts[i].pnt3d[Y] = pnts[i].pnt3d[Y] * scal;
		pnts[i].pnt3d[Z] = pnts[i].pnt3d[Z] * scal;
	}
	meta->map.zoom_scal_on = 0;
}

/*
*	Iterates all the points and add the "move" traslation
*/

void	translate(t_point3d *pnts, t_point3d move, size_t pnts_cnt)
{
	size_t	i;

	i = -1;
	while (++i < pnts_cnt)
	{
		pnts[i].pnt3d[X] = pnts[i].pnt3d[X] + move.pnt3d[X];
		pnts[i].pnt3d[Y] = pnts[i].pnt3d[Y] + move.pnt3d[Y];
		pnts[i].pnt3d[Z] = pnts[i].pnt3d[Z] + move.pnt3d[Z];
	}
}
