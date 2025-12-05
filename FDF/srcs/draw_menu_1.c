/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 21:14:22 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/08 16:52:03 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_macros.h"
#include "fdf_colors.h"

void		print_str_mlx(t_meta *meta, t_idx idx, int clr, char *str);
void		print_nbr_mlx(t_meta *meta, t_idx idx, int nbr);

static void	draw_info(t_meta *meta);
static void	draw_mapinfo(t_meta *meta);
static void	draw_colorscheme(t_meta *meta);

void		draw_controls(t_meta *meta);

void	draw_menu(t_meta *meta)
{
	draw_info(meta);
	draw_mapinfo(meta);
	draw_colorscheme(meta);
	draw_controls(meta);
}

static void	draw_info(t_meta *meta)
{
	t_idx	idx;

	idx.x = MENU_TAB;
	idx.y = DRAWINFO_BOX;
	print_str_mlx(meta, idx, RED, "//// DRAW INFO ////");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "Reenders:");
	idx.x = MENU_TAB + 100;
	print_nbr_mlx(meta, idx, meta->map.rendrin_cnt);
	idx.x = MENU_TAB;
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "(X, Y):");
	idx.x = MENU_TAB + 100;
	print_nbr_mlx(meta, idx, meta->map.rot_angs[X]);
	idx.x = MENU_TAB + 160;
	print_nbr_mlx(meta, idx, meta->map.rot_angs[Y]);
	idx.x = MENU_TAB;
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "Zoom:");
	idx.x = MENU_TAB + 100;
	print_nbr_mlx(meta, idx, meta->map.zoom_scal);
}

static void	draw_mapinfo_2(t_meta *meta, t_idx idx);

static void	draw_mapinfo(t_meta *meta)
{
	t_idx	idx;

	idx.x = MENU_TAB;
	idx.y = MAPINFO_BOX;
	print_str_mlx(meta, idx, RED, "//// MAP INFO ////");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "Size:");
	idx.x = MENU_TAB + 80;
	print_nbr_mlx(meta, idx, meta->map.pnts_cnt);
	idx.x = MENU_TAB;
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "Xmax:");
	idx.x = MENU_TAB + 80;
	print_nbr_mlx(meta, idx, meta->map.map_limits.x_max);
	idx.x = MENU_TAB;
	idx.y += LINE_SIZE;
	draw_mapinfo_2(meta, idx);
}

static void	draw_mapinfo_2(t_meta *meta, t_idx idx)
{
	print_str_mlx(meta, idx, TEXT_COLOR, "Ymax:");
	idx.x = MENU_TAB + 80;
	print_nbr_mlx(meta, idx, meta->map.map_limits.y_max);
	idx.x = MENU_TAB;
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "Zmax:");
	idx.x = MENU_TAB + 80;
	print_nbr_mlx(meta, idx, meta->map.map_limits.z_max);
	idx.x = MENU_TAB;
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "Zmin:");
	idx.x = MENU_TAB + 80;
	print_nbr_mlx(meta, idx, meta->map.z_min_4_colrs);
}

static void	draw_colorscheme(t_meta *meta)
{
	t_idx	idx;

	idx.x = MENU_TAB;
	idx.y = COLORSCHEME_BOX;
	print_str_mlx(meta, idx, RED, "//// COLORSCHEME ////");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "0: DEFAULT");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "9: BLACK & WHITE");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "8: WHITE & BLACK");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "7: BLUE & BLACK");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "6: PINK & PURPLE & BLACK");
	idx.y += LINE_SIZE;
}
