/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_color_scheme.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:44:50 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 22:58:43 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_macros.h"
#include "fdf_colors.h"

static void	color_scheme_1(t_meta *meta);
static void	color_scheme_2(t_meta *meta);
static void	color_scheme_3(t_meta *meta);
static void	color_scheme_4(t_meta *meta);

void		update_colors(t_map_units *map);

/*
*	This function handle the colorscheme dependig the key pressed
*/
void	set_new_color_scheme(
			t_meta *meta, int key, int pressed_key_idx, void *prv_colors_)
{
	int	prv_colors;

	prv_colors = *((int *) prv_colors_);
	(void) pressed_key_idx;
	if (key == KEY_0 || prv_colors == 0)
	{
		meta->map.colrs.bakrdcolr = CARBON;
		meta->map.colrs.bottmcolr = BLUE;
		meta->map.colrs.grundcolr = SAFFRON;
		meta->map.colrs.topcolr = BRICK_RED;
		meta->map.clr_schem = 0;
	}
	else if (key == KEY_9 || prv_colors == 9)
		color_scheme_1(meta);
	else if (key == KEY_8 || prv_colors == 8)
		color_scheme_2(meta);
	else if (key == KEY_7 || prv_colors == 7)
		color_scheme_3(meta);
	else if (key == KEY_6 || prv_colors == 6)
		color_scheme_4(meta);
	meta->map.clr_schem = 0;
	update_colors(&meta->map);
}

static void	color_scheme_1(t_meta *meta)
{
	meta->map.colrs.bakrdcolr = WHITE;
	meta->map.colrs.bottmcolr = CARBON;
	meta->map.colrs.grundcolr = CARBON;
	meta->map.colrs.topcolr = CARBON;
	meta->map.clr_schem = 9;
}

static void	color_scheme_2(t_meta *meta)
{
	meta->map.colrs.bakrdcolr = CARBON;
	meta->map.colrs.bottmcolr = WHITE;
	meta->map.colrs.grundcolr = WHITE;
	meta->map.colrs.topcolr = WHITE;
	meta->map.clr_schem = 8;
}

static void	color_scheme_3(t_meta *meta)
{
	meta->map.colrs.bakrdcolr = CARBON;
	meta->map.colrs.bottmcolr = BLUE;
	meta->map.colrs.grundcolr = BLUE;
	meta->map.colrs.topcolr = BLUE;
	meta->map.clr_schem = 7;
}

static void	color_scheme_4(t_meta *meta)
{
	meta->map.colrs.bakrdcolr = CARBON;
	meta->map.colrs.bottmcolr = SUPERBLUE;
	meta->map.colrs.grundcolr = PURPLE;
	meta->map.colrs.topcolr = PINK;
	meta->map.clr_schem = 6;
}
