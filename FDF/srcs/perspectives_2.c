/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspectives_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:30:23 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/07 17:55:16 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_macros.h"

/*
*	Set the values to draw DIMETRIC view
*/

void	dimetric(t_meta *meta, int key, int idx, void *extra)
{
	(void) key;
	(void) idx;
	(void) extra;
	meta->map.fit = 1;
	meta->map.fit = 1;
	meta->map.rot_angs[X] = 20;
	meta->map.rot_angs[Y] = 45;
	meta->map.rot_angs[Z] = 0;
	meta->map.bend_scal = 0;
}

/*
*	Set the values to draw TRIMETRIC view
*/

void	trimetric(t_meta *meta, int key, int idx, void *extra)
{
	(void) key;
	(void) idx;
	(void) extra;
	meta->map.fit = 1;
	meta->map.fit = 1;
	meta->map.rot_angs[X] = 15;
	meta->map.rot_angs[Y] = 30;
	meta->map.rot_angs[Z] = 45;
	meta->map.bend_scal = 0;
}

void	fit_map(t_meta *meta, int key, int idx, void *extra)
{
	(void) key;
	(void) idx;
	(void) extra;
	meta->map.fit = 1;
}
