/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:48:42 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/08 16:10:42 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_macros.h"

static bool	key_move(int key, t_meta *meta, int pressed_key_idx);
void		rotation_control(int key, t_meta *meta);

void	key_combo_1(t_meta *meta, int key, int pressed_key_idx, void *extra)
{
	(void) extra;
	meta->map.fit = 0;
	key_move(key, meta, pressed_key_idx);
}

bool		draw_map(t_meta *meta, t_map_units *map, bool fit);

static bool	key_move(int key, t_meta *meta, int pressed_key_idx)
{
	static int	delta_x;
	static int	delta_y;

	(void) key;
	delta_x = 0;
	delta_y = 0;
	meta->map.fit = 0;
	if (pressed_key_idx == UPP)
		delta_y += -5;
	if (pressed_key_idx == RIT)
		delta_x += 5;
	if (pressed_key_idx == DWN)
		delta_y += 5;
	if (pressed_key_idx == LFT)
		delta_x += -5;
	meta->map.trans_cent.pnt3d[X] += delta_x;
	meta->map.trans_cent.pnt3d[Y] += delta_y;
	meta->map.trans_cent.pnt3d[Z] = 0;
	return (1);
}

void	key_combo_2(t_meta *meta, int key, int pressed_key_idx, void *extra)
{
	(void) pressed_key_idx;
	(void) extra;
	meta->map.fit = 0;
	meta->map.rotate_on = 1;
	rotation_control(key, meta);
}

void	key_combo_9(t_meta *meta, int key, int pressed_key_idx, void *extra)
{
	(void) key;
	(void) pressed_key_idx;
	(void) extra;
	meta->map.fit = 0;
	meta->map.z_scal_on = 1;
	if (!meta->map.z_scal_fix_on)
		meta->map.z_scal = 1;
}

void	key_combo_10(t_meta *meta, int key, int pressed_key_idx, void *extra)
{
	(void) key;
	(void) pressed_key_idx;
	(void) extra;
	meta->map.fit = 0;
	meta->map.z_scal_on = 1;
	if (!meta->map.z_scal_fix_on)
		meta->map.z_scal = -1;
}
