/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:31:24 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 22:45:36 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_errors.h"

#include <stdio.h>

void			init_parser_size(t_parser_ctx *ctx);

size_t			get_map_width(t_meta *meta, t_map_units *map);

static size_t	skip_spaces(const char *data, size_t i);

static size_t	handle_point(
					t_meta *meta, const char *data,
					size_t i, t_parser_ctx *ctx);

void			handle_eol(
					t_meta *meta, t_map_units *map,
					t_parser_ctx *ctx, char c);

void			*clean_n_exit(t_meta *meta, int err);

int	parse_map_size(t_meta *meta)
{
	t_parser_ctx	ctx;
	t_map_units		*map;

	map = &meta->map;
	init_parser_size(&ctx);
	map->map_limits.x_max = get_map_width(meta, map);
	while (map->map_data[++ctx.i])
	{
		if (map->map_data[ctx.i] == '\n' && map->map_data[ctx.i + 1] == '\0')
			break ;
		if (map->map_data[ctx.i] == ' ')
			ctx.i = skip_spaces(map->map_data, ctx.i);
		ctx.i = handle_point(meta, map->map_data, ctx.i, &ctx);
		handle_eol(meta, map, &ctx, map->map_data[ctx.i]);
	}
	map->pnts_cnt
		= (size_t) map->map_limits.x_max * (size_t) map->map_limits.y_max;
	return (1);
}

// Skips consecutive spaces; returns updated index
static size_t	skip_spaces(const char *data, size_t i)
{
	while (data[i] == ' ')
		++i;
	return (i);
}

size_t			skip_number(t_meta *meta, const char *data, size_t i);

// Processes a numeric point and updates counters; returns updated index
static size_t	handle_point(
					t_meta *meta, const char *data,
					size_t i, t_parser_ctx *ctx)
{
	size_t	start;

	(void) meta;
	start = i;
	i = skip_number(meta, data, i);
	if (i != start)
	{
		if (data[i] == ' ' || data[i] == '\n' || data[i] == '\0')
		{
			++ctx->pnts_cnt;
			++ctx->lin_pnts_cnt;
		}
	}
	return (i);
}
