/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:28:34 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 12:49:49 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stddef.h>
# include <stdbool.h>
# include "../libs/libft/gnl/get_next_line.h"

typedef struct s_colrs
{
	int	topcolr;
	int	grundcolr;
	int	bottmcolr;
	int	bakrdcolr;
	int	menucolr;
}	t_colrs;

// Spherical Coordinates:
// latitude;   // θ (polar angle)
// longitude;  // φ (azimuthal angle)
// https://en.wikipedia.org/wiki/Spherical_coordinate_system
typedef struct s_spheric
{
	float	lat;
	float	lng;
}	t_spheric;

typedef struct s_point3d
{
	float		pnt3d[3];
	float		z_origin;
	int			clr;
	int			hex_clr;
	char		*z_str;
	char		*hex_str;
	bool		hex_on;
	bool		b_paint;
	bool		z_scal_on;
	t_spheric	ang;
}	t_point3d;

typedef struct s_fdf_mlx
{
	void	*mlx;
	void	*win;
}	t_fdf_mlx;

typedef struct s_map_limits
{
	float	x_max;
	float	y_max;
	float	z_max;
}	t_map_limits;

typedef struct s_map_img
{
	void	*img;
	char	*buf;
	int		pix;
	int		lin_cnt;
	int		endian;
}	t_map_img;

typedef struct s_hexcrl	t_hexclr;

typedef struct s_hexcrl
{
	char		*hexclr;
	t_hexclr	*nxt;
}	t_hexclr;

typedef struct s_map_units
{
	t_point3d		*pnts;
	t_point3d		*pnts_cpy;
	t_map_limits	map_limits;
	t_point3d		trans_cent;
	t_hexclr		*hexclr;
	t_colrs			colrs;
	int				clr_schem;
	char			*map_data;
	char			**map_lins;
	int				z_min_4_colrs;
	float			rot_angs[3];
	float			z_scal;
	bool			z_scal_on;
	bool			z_scal_fix_on;
	float			zoom_scal;
	bool			zoom_scal_on;
	size_t			pnts_cnt;
	float			bend_scal;
	int				rendrin_cnt;
	bool			lins_on;
	bool			dots_on;
	bool			extra_projct;
	bool			glob_on;
	bool			rotate_on;
	bool			trans_on;
	float			radius;
	float			z_x_ratio;
	int				pars_err;
	bool			fit;
}	t_map_units;

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

typedef struct s_meta
{
	t_fdf_mlx	fdf_mlx;
	t_map_img	map_img;
	t_map_units	map;
	t_keys		keys;
	int			err;
}	t_meta;

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

typedef struct s_parser_ctx
{
	size_t	i;
	size_t	pnts_cnt;
	size_t	lin_pnts_cnt;
	size_t	height_cnt;
}	t_parser_ctx;

#endif
