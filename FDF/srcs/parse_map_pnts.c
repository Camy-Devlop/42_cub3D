/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_pnts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:21:36 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 23:29:42 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_colors.h"
#include "fdf_macros.h"
#include "fdf_errors.h"

void			*ft_calloc(size_t n, size_t data_size);
size_t			ft_strlen_2(const char *s, char c);
char			**ft_split_n(const char *str, char c, size_t len);
void			load_pnts(t_map_units *map);
void			*ft_free2dstr(char ***s);
static void		*free_pnts_str(char ****pnts_str);
void			*clean_n_exit(t_meta *meta, int err);

char			**ft_split2_n(const char *str, const char *deli, size_t len);
char			**ft_split(char const *s, char c, size_t len);

static void		allocate_pnts(t_meta *meta, char ****pnts_str);

static size_t	parse_line(t_meta *meta, char ***pnts_str,
					t_idx *idx, char *map_data);

int	parse_map_pnts(t_meta *meta)
{
	t_idx			idx;
	size_t			lin_len;
	char			*map_data;
	char			***pnts_str;

	allocate_pnts(meta, &pnts_str);
	map_data = meta->map.map_data;
	idx.pnt_idx = -1;
	idx.i = -1;
	while (*map_data)
	{
		lin_len = parse_line(meta, pnts_str, &idx, map_data);
		if (*(map_data + lin_len))
			map_data += lin_len + 1;
		else
			map_data += lin_len;
	}
	pnts_str[idx.i + 1] = NULL;
	load_pnts(&meta->map);
	free_pnts_str(&pnts_str);
	return (1);
}

static size_t	parse_line(t_meta *meta, char ***pnts_str,
						t_idx *idx, char *map_data)
{
	size_t	lin_len;

	lin_len = ft_strlen_2(map_data, '\n');
	pnts_str[++(idx->i)] = ft_split2_n(map_data, " ,", lin_len);
	idx->j = -1;
	while (pnts_str[idx->i][++(idx->j)])
	{
		if (++idx->pnt_idx >= meta->map.pnts_cnt)
			break ;
		meta->map.pnts[(idx->pnt_idx)].z_str = pnts_str[idx->i][idx->j];
		if (pnts_str[idx->i][idx->j] &&
			pnts_str[idx->i][idx->j + 1] &&
			pnts_str[idx->i][idx->j + 1][0] == '0' &&
			(pnts_str[idx->i][idx->j + 1][1] == 'x' ||
				pnts_str[idx->i][idx->j + 1][1] == 'X'))
		{
			meta->map.pnts[idx->pnt_idx].hex_str
				= &pnts_str[idx->i][idx->j + 1][0];
			++(idx->j);
		}
	}
	return (lin_len);
}

static void	allocate_pnts(t_meta *meta, char ****pnts_str)
{
	meta->map.pnts = ft_calloc(meta->map.pnts_cnt, sizeof(t_point3d));
	*pnts_str = ft_calloc(meta->map.pnts_cnt + 1, sizeof(char ***));
	if (!meta->map.pnts || !(*pnts_str))
	{
		free_pnts_str(pnts_str);
		clean_n_exit(meta, ERROR_N_SYS_CALL);
	}
}

// This function to free a 3d table!
static void	*free_pnts_str(char ****pnts_str)
{
	size_t	i;

	i = -1;
	while ((*pnts_str)[++i])
		ft_free2dstr(&((*pnts_str)[i]));
	free(*pnts_str);
	*pnts_str = NULL;
	return (NULL);
}
