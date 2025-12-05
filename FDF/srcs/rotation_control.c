/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:37:20 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/07 17:57:42 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_macros.h"
#include "key_macros.h"

void	rotate(float *ang, float value);

void	rotation_control(int key, t_meta *meta)
{
	int	ang;

	ang = 1;
	if (meta->keys.key_ctrl)
		ang = 90;
	if (key == KEY_UP)
		rotate(&meta->map.rot_angs[X], -ang);
	else if (key == KEY_RIGHT)
		rotate(&meta->map.rot_angs[Y], ang);
	else if (key == KEY_DOWN)
		rotate(&meta->map.rot_angs[X], ang);
	else if (key == KEY_LEFT)
		rotate(&meta->map.rot_angs[Y], -ang);
	else if (key == KEY_E)
		rotate(&meta->map.rot_angs[Z], ang);
	else if (key == KEY_Q)
		rotate(&meta->map.rot_angs[Z], -ang);
}

void	rotate(float *ang, float value)
{
	*ang += value;
	if (*ang < 0)
		*ang = 360 + *ang;
	if (*ang >= 360)
		*ang = *ang - 360;
}
