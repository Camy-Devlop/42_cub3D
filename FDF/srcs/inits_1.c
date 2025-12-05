/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:08:08 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/08 14:08:30 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minilibx/minilibx-linux/mlx.h"

#include "fdf.h"
#include "fdf_macros.h"
#include "key_macros.h"
#include "fdf_colors.h"
#include <unistd.h>
#include <stdlib.h>

void	init_map_new(t_map_units *map);
void	init_map_clrs(t_map_units *map);
void	init_logo(t_meta *meta);

void	init_map(t_map_units *map, bool new)
{
	if (new)
		init_map_new(map);
	map->lins_on = 1;
	map->dots_on = 0;
	map->extra_projct = 0;
	map->rotate_on = 0;
	map->trans_on = 0;
	map->z_scal = 0;
	map->z_scal_on = 0;
	map->z_scal_fix_on = 0;
	map->zoom_scal = 1;
	map->zoom_scal_on = 0;
	map->bend_scal = 0;
	map->glob_on = 0;
	map->pars_err = 0;
	map->trans_cent.pnt3d[X] = ((WIN_W - MENU_WID) / 2) + WIN_W;
	map->trans_cent.pnt3d[Y] = WIN_H / 2;
	map->trans_cent.pnt3d[Z] = 0;
	map->rot_angs[X] = 0;
	map->rot_angs[Y] = 0;
	map->rot_angs[Z] = 0;
	init_map_clrs(map);
}

void	init_map_new(t_map_units *map)
{
	map->pnts_cnt = 0;
	map->map_limits.x_max = 0;
	map->map_limits.y_max = 0;
	map->map_limits.z_max = 0;
	map->z_min_4_colrs = 0;
	map->z_scal_on = 0;
}

void	init_map_clrs(t_map_units *map)
{
	map->clr_schem = 0;
	map->colrs.bakrdcolr = BACK_COLOR;
	map->colrs.menucolr = MENU_COLOR;
	map->colrs.bottmcolr = BOTTOM_COLOR;
	map->colrs.grundcolr = GROUND_COLOR;
	map->colrs.topcolr = TOP_COLOR;
}

void	*ft_memset(void *s, int c, size_t n);

void	init_libix(t_meta *meta)
{
	meta->map.rendrin_cnt = 0;
	meta->map.z_x_ratio
		= meta->map.map_limits.z_max / meta->map.map_limits.x_max;
	meta->keys.key_ctrl = 0;
	meta->keys.mouse_l = 0;
	meta->keys.mouse_r = 0;
	meta->fdf_mlx.mlx = mlx_init();
	meta->fdf_mlx.win = mlx_new_window(
			meta->fdf_mlx.mlx, WIN_W, WIN_H, "FDF - Alex Phoenix -");
	meta->map_img.img = mlx_new_image(meta->fdf_mlx.mlx, WIN_W, WIN_H);
	meta->map_img.buf = mlx_get_data_addr(
			meta->map_img.img, &meta->map_img.pix,
			&meta->map_img.lin_cnt, &meta->map_img.endian);
	ft_memset(meta->map_img.buf, 0, WIN_W * WIN_H * 4);
}

void	print_error(int fd, int err_n, int end_line_flag);

void	*clean_n_exit(t_meta *meta, int err)
{
	if (err != -1)
		print_error(2, err, 1);
	free(meta->map.map_data);
	meta->map.map_data = NULL;
	free(meta->map.pnts);
	meta->map.pnts = NULL;
	free(meta->map.pnts_cpy);
	meta->map.pnts_cpy = NULL;
	if (meta->fdf_mlx.mlx && meta->fdf_mlx.win)
	{
		mlx_destroy_window(meta->fdf_mlx.mlx, meta->fdf_mlx.win);
		if (meta->map_img.img)
			mlx_destroy_image(meta->fdf_mlx.mlx, meta->map_img.img);
		mlx_destroy_display(meta->fdf_mlx.mlx);
		free(meta->fdf_mlx.mlx);
		meta->fdf_mlx.mlx = NULL;
	}
	if (err)
		exit(1);
	else
		return (NULL);
}
