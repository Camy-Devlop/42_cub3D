/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:56:49 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 23:23:08 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_macros.h"

void	rotation_control(int key, t_meta *meta);

void	key_combo_11(t_meta *meta, int key, int pressed_key_idx, void *extra)
{
	size_t	i;

	(void) pressed_key_idx;
	(void) key;
	(void) extra;
	meta->map.fit = 1;
	i = -1;
	while (++i < meta->map.pnts_cnt)
		meta->map.pnts[i].pnt3d[Z] = meta->map.pnts[i].z_origin;
}

void	key_combo_12(t_meta *meta, int key, int pressed_key_idx, void *extra)
{
	(void) key;
	(void) pressed_key_idx;
	(void) extra;
	meta->map.glob_on = !meta->map.glob_on;
	meta->map.fit = 0;
}

void	key_combo_14(t_meta *meta, int key, int pressed_key_idx, void *extra)
{
	(void) pressed_key_idx;
	(void) extra;
	meta->map.fit = 0;
	rotation_control(key, meta);
}

void	key_combo_16(t_meta *meta, int key, int pressed_key_idx, void *extra)
{
	float	prop;

	(void) key;
	(void) pressed_key_idx;
	(void) extra;
	meta->map.z_scal = 0;
	meta->map.z_scal_fix_on = !meta->map.z_scal_fix_on;
	prop = meta->map.map_limits.z_max / meta->map.map_limits.x_max;
	meta->map.z_scal = 2.5;
}

void	do_nothing(t_meta *meta, int key, int pressed_key_idx, void *extra)
{
	(void) meta;
	(void) key;
	(void) pressed_key_idx;
	(void) extra;
}
