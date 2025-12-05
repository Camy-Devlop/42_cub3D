/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_event_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:52:47 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 23:23:26 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_macros.h"
#include "key_macros.h"
#include "fdf_colors.h"

static int	get_pressed_combo(int key, int *pressed_key_idx);

bool		draw_map(t_meta *meta, t_map_units *map, bool fit);

int			exit_fdf(void *ptr);

void		do_nothing(t_meta *meta, int key, int pressed_key_idx, void *extra);
void		key_combo_1(
				t_meta *meta, int key, int pressed_key_idx, void *extra);
void		key_combo_2(
				t_meta *meta, int key, int pressed_key_idx, void *extra);
void		key_combo_9(
				t_meta *meta, int key, int pressed_key_idx, void *extra);
void		key_combo_10(
				t_meta *meta, int key, int pressed_key_idx, void *extra);
void		key_combo_11(
				t_meta *meta, int key, int pressed_key_idx, void *extra);
void		key_combo_12(
				t_meta *meta, int key, int pressed_key_idx, void *extra);
void		key_combo_14(
				t_meta *meta, int key, int pressed_key_idx, void *extra);
void		key_combo_16(
				t_meta *meta, int key, int pressed_key_idx, void *extra);

void		parallel(t_meta *meta, int key, int pressed_key_idx, void *extra);
void		parallel_side(
				t_meta *meta, int key, int pressed_key_idx, void *extra);
void		isomet(t_meta *meta, int key, int pressed_key_idx, void *extra);
void		top_view(t_meta *meta, int key, int pressed_key_idx, void *extra);
void		dimetric(t_meta *meta, int key, int pressed_key_idx, void *extra);
void		trimetric(t_meta *meta, int key, int pressed_key_idx, void *extra);
void		fit_map(t_meta *meta, int key, int idx, void *extra);

void		set_new_color_scheme(
				t_meta *meta, int key, int pressed_key_idx, void *prv_colors_);

/*
*	This function handle when a key is pressed
*/

int	key_press(int key, void *parm)
{
	t_meta							*meta;
	int								pressed_key_idx;
	int								key_combo;
	int								prv_colors_;
	const t_key_combo_handler_fn	functs[17] = \
	{\
		do_nothing, key_combo_1, key_combo_2, parallel, isomet, top_view, \
		dimetric, trimetric, fit_map, key_combo_9, key_combo_10, \
		key_combo_11, key_combo_12, parallel_side, key_combo_14, \
		set_new_color_scheme, key_combo_16};

	key_combo = 0;
	prv_colors_ = -1;
	meta = (t_meta *) parm;
	pressed_key_idx = 0;
	if (key == KEY_ESC)
		exit_fdf(meta);
	key_combo = get_pressed_combo(key, &pressed_key_idx);
	if (0 < key_combo && key_combo < 17)
		functs[key_combo](meta, key, pressed_key_idx, &prv_colors_);
	if (key_combo)
		draw_map(meta, &meta->map, meta->map.fit);
	return (1);
}

static int	check_pad_arrow_keys(
				int key, int *pressed_key_idx, const int *pad_arrow_keys);
static int	check_arrow_keys(
				int key, int *pressed_key_idx, const int *arrow_keys);
void		init_keys_map_1(t_keys_map *keys_1);

static int	get_pressed_combo(int key, int *pressed_key_idx)
{
	const int	arrow_keys[] = {KEY_UP, KEY_RIGHT, KEY_DOWN, KEY_LEFT};
	const int	pad_arrow_keys[] = {KEY_W, KEY_D, KEY_S, KEY_A};
	t_keys_map	keys_1[13];
	size_t		i;

	if (check_pad_arrow_keys(key, pressed_key_idx, pad_arrow_keys))
		return (1);
	if (check_arrow_keys(key, pressed_key_idx, arrow_keys))
		return (2);
	if (key == KEY_Q || key == KEY_E)
		return (14);
	if ((KEY_6 <= key && key <= KEY_9) || key == KEY_0)
		return (15);
	init_keys_map_1(keys_1);
	i = -1;
	while (++i < 12)
		if (keys_1[i].key == key)
			return (keys_1[i].retval);
	return (0);
}

static int	check_pad_arrow_keys(
				int key, int *pressed_key_idx, const int *pad_arrow_keys)
{
	size_t		i;

	i = -1;
	while (++i < 4)
	{
		if (key == pad_arrow_keys[i])
		{
			*pressed_key_idx = i;
			return (1);
		}
	}
	return (0);
}

static int	check_arrow_keys(
				int key, int *pressed_key_idx, const int *arrow_keys)
{
	size_t	i;

	i = -1;
	while (++i < 4)
	{
		if (key == arrow_keys[i])
		{
			*pressed_key_idx = i;
			return (2);
		}
	}
	return (0);
}

/*
*	This function handle when a key is relased
*/
int	key_release(int key, void *parm)
{
	t_meta	*meta;

	(void) key;
	meta = (t_meta *) parm;
	return (0);
}
