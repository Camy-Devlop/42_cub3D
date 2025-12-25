/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 02:12:48 by alephoen          #+#    #+#             */
/*   Updated: 2025/12/25 18:27:47 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stddef.h>
# include <get_next_line.h>

typedef struct s_idx
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	x;
	size_t	y;
	size_t	pnt_idx;
}	t_idx;

typedef struct s_get_map_data
{
	char		*lin;
	char		*tmp1;
	char		*tmp2;
	t_gnl_buf	**buf;
	size_t		tmp1_len;

}	t_get_map_data;

typedef struct s_colrs
{

}	t_colrs;

typedef struct s_point3d
{
	float		pnt3d[3];
}	t_point3d;

typedef struct s_keys
{
	bool		upp;
	bool		rit;
	bool		dwn;
	bool		lef;
	bool		mouse_l;
	bool		mouse_r;
	bool		key_ctrl;
	t_point3d	last_click_l;
	t_point3d	last_click_r;
}	t_keys;

typedef struct s_keys_map
{
	int	key;
	int	retval;
}	t_keys_map;

typedef struct s_map_units
{

}	t_map_units;

typedef struct s_map_img
{
	void	*img;
	char	*buf;
}	t_map_img;

typedef struct s_cub3d_mlx
{
	void	*mlx;
	void	*win;
}	t_cub3d_mlx;

typedef struct s_meta
{
	t_cub3d_mlx		cub3d_mlx;
	t_map_img		map_img;
	t_map_units		map;
	t_keys			keys;
	int				err;
}	t_meta;
typedef struct s_line
{
	int		size;
	char	*string;
}
typedef struct s_data_file
{
	char	*name_file;
	int		nb_line;
	int		max_colums;
	t_line	*config;
	t_line	*map;
}	t_data_file;
#endif
