/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:28:16 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/08 16:55:20 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minilibx/minilibx-linux/mlx.h"

#include "fdf.h"
#include "fdf_macros.h"
#include "fdf_colors.h"

char		*ft_itoa(int nbr);

void	print_nbr_mlx(t_meta *meta, t_idx idx, int nbr)
{
	char	*str;

	str = ft_itoa(nbr);
	mlx_string_put(meta->fdf_mlx.mlx, meta->fdf_mlx.win,
		idx.x, idx.y, NUMBER_COLOR, str);
	free (str);
}

void	print_str_mlx(t_meta *meta, t_idx idx, int clr, char *str)
{
	mlx_string_put(meta->fdf_mlx.mlx, meta->fdf_mlx.win,
		idx.x, idx.y, clr, str);
}

static void	draw_controls_2(t_meta *meta, t_idx idx);

void	draw_controls(t_meta *meta)
{
	t_idx	idx;

	idx.x = MENU_TAB;
	idx.y = CONTROL_BOX;
	print_str_mlx(meta, idx, RED, "//// CONTROLS ////");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "Scroll: Zom In/Out");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "Left Click: Rotate X/Y axis");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "Right Click Move: Translate");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "W,D,S,A: Translate");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "Arrows: Rotate X/Y axis");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "Q/E: Rotate Z axis");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "+/-: Altitude");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "C: Fit & Center");
	idx.y += LINE_SIZE;
	draw_controls_2(meta, idx);
}

static void	draw_controls_2(t_meta *meta, t_idx idx)
{
	print_str_mlx(meta, idx, TEXT_COLOR, "Z: Lock ON/OFF ALT");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "`/~: Pespective 0");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "1: Pespective 1");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "2: Pespective 2");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "3: Pespective 3");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "4: Pespective 4");
	idx.y += LINE_SIZE;
	print_str_mlx(meta, idx, TEXT_COLOR, "5: Pespective 5");
	idx.y += LINE_SIZE;
}
