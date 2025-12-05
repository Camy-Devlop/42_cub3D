/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspectives_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:59:31 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/07 17:55:24 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_macros.h"
#include <math.h>

/*
*	Set the values to draw PARALLEL view
*/

void	parallel(t_meta *meta, int key, int idx, void *extra)
{
	(void) key;
	(void) idx;
	(void) extra;
	meta->map.fit = 1;
	meta->map.rot_angs[X] = 90;
	meta->map.rot_angs[Y] = 0;
	meta->map.rot_angs[Z] = 0;
	meta->map.bend_scal = 0;
}

/*
*	Set the values to draw PARALLEL side view
*/

void	parallel_side(t_meta *meta, int key, int idx, void *extra)
{
	(void) key;
	(void) idx;
	(void) extra;
	meta->map.fit = 1;
	meta->map.rot_angs[X] = 90;
	meta->map.rot_angs[Y] = 90;
	meta->map.rot_angs[Z] = 0;
	meta->map.bend_scal = 0;
}
/*
*	Set the values to draw ISOMETRIC view
*/

void	isomet(t_meta *meta, int key, int idx, void *extra)
{
	(void) key;
	(void) idx;
	(void) extra;
	meta->map.fit = 1;
	meta->map.fit = 1;
	meta->map.rot_angs[X] = 30;
	meta->map.rot_angs[Y] = 330;
	meta->map.rot_angs[Z] = 30;
	meta->map.bend_scal = 0;
}

/*
*	Set the values to draw ISOMETRIC view
*/

void	top_view(t_meta *meta, int key, int idx, void *extra)
{
	(void) key;
	(void) idx;
	(void) extra;
	meta->map.fit = 1;
	meta->map.fit = 1;
	meta->map.rot_angs[X] = 0;
	meta->map.rot_angs[Y] = 0;
	meta->map.rot_angs[Z] = 0;
	meta->map.bend_scal = 0;
}
