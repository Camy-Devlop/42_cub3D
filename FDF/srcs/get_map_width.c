/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:55:11 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 12:47:25 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool		get_map_width_cnt_dig(
					t_map_units *map, size_t *j, size_t *wid, bool *wid_on);

void			*clean_n_exit(t_meta *meta, int err);

static size_t	skip_hex_nbr(t_meta *meta, const char *data, size_t *i);

bool			check_char_err_2(t_map_units *map, size_t i);

static size_t	skip_space_n_minus(t_map_units *map, size_t i);

size_t	get_map_width(t_meta *meta, t_map_units *map)
{
	size_t	width;
	size_t	i;
	bool	width_on;
	bool	nbr_fnd;

	if (!map || !map->map_data)
		return (0);
	width_on = 0;
	width = 0;
	i = -1;
	while (map->map_data[++i])
	{
		nbr_fnd = 0;
		if (map->map_data[i] == '\n' || map->map_data[i + 1] == '\0')
			break ;
		i = skip_space_n_minus(map, i);
		nbr_fnd = get_map_width_cnt_dig(map, &i, &width, &width_on);
		if (nbr_fnd)
			skip_hex_nbr(meta, map->map_data, &i);
		if (map->pars_err || check_char_err_2(map, i))
			clean_n_exit(meta, map->pars_err);
		if (map->map_data[i] == '\n' || map->map_data[i + 1] == '\0')
			break ;
	}
	return (width);
}

static size_t	skip_space_n_minus(t_map_units *map, size_t i)
{
	while (map->map_data[i] == ' ')
		++i;
	if (map->map_data[i] == '-'
		&& ('0' <= map->map_data[i + 1] && map->map_data[i + 1] <= '9'))
		++i;
	return (i);
}

static size_t	skip_hex_dig(const char *data, size_t i, bool *b);

static size_t	skip_hex_nbr(t_meta *meta, const char *data, size_t *j)
{
	bool	b;
	size_t	i;

	b = 0;
	i = *j;
	while (data[i] == ' ')
		++i;
	if (data[i] == ',')
	{
		++i;
		while (data[i] == ' ')
			++i;
		if (data[i] != '0')
			clean_n_exit(meta, 3);
		if (data[i] == '0' && data[i + 1]
			&& (data[i + 1] == 'x' || (data[i + 1] == 'X')))
			i = skip_hex_dig(data, i, &b);
		else if (data[i] != ',' && '0' <= data[i] && data[i] <= '9')
			--i;
	}
	else if (data[i - 1] == ' ')
		--i;
	*j = i;
	return (b);
}

static size_t	skip_hex_dig(const char *data, size_t i, bool *b)
{
	*b = 1;
	i += 2;
	while (data[i]
		&& (('0' <= data[i] && data[i] <= '9')
			|| ('a' <= data[i] && data[i] <= 'f')
			|| ('A' <= data[i] && data[i] <= 'F')))
		++i;
	return (i);
}

bool			check_char_err(t_map_units *map, size_t i);

static bool	get_map_width_cnt_dig(
				t_map_units *map, size_t *j, size_t *wid, bool *wid_on)
{
	size_t	i;
	size_t	width;
	bool	width_on;

	i = *j;
	width = *wid;
	width_on = *wid_on;
	if ('0' <= map->map_data[i] && map->map_data[i] <= '9')
	{
		while ('0' <= map->map_data[i] && map->map_data[i] <= '9')
			++i;
		if (!width_on && (map->map_data[i] == ' '
				|| map->map_data[i] == ',' || map->map_data[i] == '\n'))
			++width;
		if (map->map_data[i] == '\n' || map->map_data[i] == '\0')
			width_on = 1;
		if (!check_char_err(map, i))
			return (0);
		*j = i;
		*wid = width;
		*wid_on = width_on;
	}
	else
		return (0);
	return (1);
}
