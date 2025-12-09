/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:40:22 by isadbaib          #+#    #+#             */
/*   Updated: 2025/12/09 18:58:46 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_tex {
	char *no; 
	char *so;
	char *we;
	char *ea;
} t_tex;
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

typedef struct s_cub3d_mlx
{
	void	*mlx;
	void	*win;
}	t_cub3d_mlx;
	
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
