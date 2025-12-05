/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:54:36 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 23:31:06 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_point3d	multiply_matrix(float matrix[3][3], t_point3d pnt);

/*
*	This function add grades to the control structure depends the key pressed
*/

void	rotate_x(
			t_point3d *pnts, t_point3d *pnts_cpy, float ang, size_t pnts_cnt)
{
	size_t	i;
	float	rad;
	float	pnt_cpy_matrix[3][3];

	rad = ang * M_PI / 180;
	ft_memset(pnt_cpy_matrix, 0, sizeof(pnt_cpy_matrix));
	pnt_cpy_matrix[0][0] = 1;
	pnt_cpy_matrix[1][1] = cos(rad);
	pnt_cpy_matrix[1][2] = -sin(rad);
	pnt_cpy_matrix[2][1] = sin(rad);
	pnt_cpy_matrix[2][2] = cos(rad);
	i = -1;
	while (++i < pnts_cnt)
		pnts_cpy[i] = multiply_matrix(pnt_cpy_matrix, pnts[i]);
}

/*
*   Calculate len "points" of the array with the "ang" rotation in Y axis
*   and store in "proyection" array.
*/

void	rotate_y(
			t_point3d *pnts, t_point3d *pnts_cpy, float ang, size_t pnts_cnt)
{
	size_t	i;
	float	rad;
	float	pnt_cpy_matrix[3][3];

	rad = ang * M_PI / 180;
	ft_memset(pnt_cpy_matrix, 0, sizeof(pnt_cpy_matrix));
	pnt_cpy_matrix[0][0] = cos(rad);
	pnt_cpy_matrix[0][2] = sin(rad);
	pnt_cpy_matrix[1][1] = 1;
	pnt_cpy_matrix[2][0] = -sin(rad);
	pnt_cpy_matrix[2][2] = cos(rad);
	i = -1;
	while (++i < pnts_cnt)
		pnts_cpy[i] = multiply_matrix(pnt_cpy_matrix, pnts[i]);
}

/*
*   Calculate len "points" of the array with the "ang" rotation in Z axis
*   and store in "proyection" array.
*/

void	rotate_z(
			t_point3d *pnts, t_point3d *pnts_cpy, float ang, size_t pnts_cnt)
{
	size_t	i;
	float	rad;
	float	pnt_cpy_matrix[3][3];

	rad = ang * M_PI / 180;
	ft_memset(pnt_cpy_matrix, 0, sizeof(pnt_cpy_matrix));
	pnt_cpy_matrix[0][0] = cos(rad);
	pnt_cpy_matrix[0][1] = -sin(rad);
	pnt_cpy_matrix[1][0] = sin(rad);
	pnt_cpy_matrix[1][1] = cos(rad);
	pnt_cpy_matrix[2][2] = 1;
	i = -1;
	while (++i < pnts_cnt)
		pnts_cpy[i] = multiply_matrix(pnt_cpy_matrix, pnts[i]);
}

/*
*   Multiply a 3 points coordinate "point" by Matrix [3][3]
*   and return the result.
*/

t_point3d	multiply_matrix(float matrix[3][3], t_point3d pnt)
{
	size_t		i;
	size_t		j;
	t_point3d	result;

	result = pnt;
	i = -1;
	while (++i < 3)
	{
		result.pnt3d[i] = 0;
		result.clr = pnt.clr;
		j = -1;
		while (++j < 3)
			result.pnt3d[i] += matrix[i][j] * pnt.pnt3d[j];
	}
	return (result);
}
