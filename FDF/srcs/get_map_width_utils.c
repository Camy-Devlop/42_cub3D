/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_width_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:45:34 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 12:46:03 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	check_char_err(t_map_units *map, size_t i)
{
	if (!(map->map_data[i] == ','
			|| map->map_data[i] == ' '
			|| map->map_data[i] == '\n'
			|| map->map_data[i] == '\0'))
	{
		map->pars_err = 3;
		return (0);
	}
	return (1);
}

bool	check_char_err_2(t_map_units *map, size_t i)
{
	if (!(('0' <= map->map_data[i] && map->map_data[i] <= '9')
			|| map->map_data[i] == ' '
			|| map->map_data[i] == '\n'
			|| map->map_data[i] == '\0'))
	{
		map->pars_err = 3;
		return (1);
	}
	return (0);
}
