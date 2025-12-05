/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 22:24:46 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 22:49:21 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_errors.h"

static size_t	skip_hex_nbr(t_meta *meta, const char *data, size_t *j);
void			*clean_n_exit(t_meta *meta, int err);

// Skips a negative sign and numbers; returns updated index
size_t	skip_number(t_meta *meta, const char *data, size_t i)
{
	bool	dig_fnd;

	dig_fnd = 0;
	if (data[i] == '-' && ('0' <= data[i + 1] && data[i + 1] <= '9'))
		++i;
	if ('0' <= data[i] && data[i] <= '9')
		dig_fnd = 1;
	while ('0' <= data[i] && data[i] <= '9')
		++i;
	if (dig_fnd)
		skip_hex_nbr(meta, data, &i);
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

// Handles EOLs, line and height counting
void	handle_eol(
				t_meta *meta, t_map_units *map, t_parser_ctx *ctx, char c)
{
	(void) meta;
	if (c == '\n' || c == '\0')
	{
		if (ctx->lin_pnts_cnt != (size_t) meta->map.map_limits.x_max)
			clean_n_exit(meta, ERROR_N_PARSING_5);
		ctx->lin_pnts_cnt = 0;
		map->map_limits.y_max = ++(ctx->height_cnt);
	}
}
