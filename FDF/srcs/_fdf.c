/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _fdf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:29:00 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 23:11:22 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minilibx/minilibx-linux/mlx.h"

#include "fdf.h"
#include "fdf_macros.h"
#include <stdlib.h>

bool	load_map(t_meta *meta, t_map_units *map, char *path);
void	init_libix(t_meta *meta);
bool	draw_map(t_meta *meta, t_map_units *map, bool fit);
int		key_press(int key, void *parm);
int		key_release(int key, void *parm);
int		mouse_release(int button, int x, int y, void *parm);
int		mouse_press(int button, int x, int y, void *parm);
int		mouse_move(int x, int y, void *parm);
int		exit_fdf(void *ptr);
void	*clean_n_exit(t_meta *meta, int err);
void	*ft_memset(void *s, int c, size_t n);

void	fdf(int ac, char **av)
{
	t_meta	meta;

	(void) ac;
	ft_memset(&meta, 0, sizeof(meta));
	if (!load_map(&meta, &meta.map, av[1]))
		clean_n_exit(&meta, -1);
	init_libix(&meta);
	draw_map(&meta, &meta.map, 1);
	mlx_hook(meta.fdf_mlx.win, 2, 1L << 0, key_press, &meta);
	mlx_hook(meta.fdf_mlx.win, 3, 1L << 1, key_release, &meta);
	mlx_hook(meta.fdf_mlx.win, 4, 1L << 2, mouse_press, &meta);
	mlx_hook(meta.fdf_mlx.win, 5, 1L << 3, mouse_release, &meta);
	mlx_hook(meta.fdf_mlx.win, 6, 1L << 6, mouse_move, &meta);
	mlx_hook(meta.fdf_mlx.win, 17, 0, exit_fdf, &meta);
	mlx_loop(meta.fdf_mlx.mlx);
}

// This funciton handle the progrm shut down!
int	exit_fdf(void *ptr)
{
	t_meta	*meta;

	meta = (t_meta *) ptr;
	clean_n_exit(meta, -1);
	return (0);
}
