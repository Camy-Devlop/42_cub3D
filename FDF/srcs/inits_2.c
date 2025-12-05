/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:08:51 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 22:56:04 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_macros.h"
#include "key_macros.h"
#include "fdf_errors.h"

#include <stdio.h>
#include <errno.h>

// flag = 0 -> nothing!
// flag = 1 -> new line;
// flag = 2 -> space
void	ft_put_str(int fd, char *str, int end_line_flag)
{
	size_t	strlen;

	if (!str)
		return ;
	strlen = -1;
	while (str[++strlen])
		;
	write(fd, str, strlen);
	if (end_line_flag == 1)
		write(fd, "\n", 1);
	else if (end_line_flag == 2)
		write(fd, " ", 1);
}

void	print_error(int fd, int err_n, int end_line_flag)
{
	if (err_n == ERROR_N_PARSING_0 && errno)
		ft_put_str(fd, ERROR_PARSING_0, end_line_flag);
	if (err_n == ERROR_N_PARSING_1)
		ft_put_str(fd, ERROR_PARSING_1, end_line_flag);
	else if (err_n == ERROR_N_PARSING_2)
		ft_put_str(fd, ERROR_PARSING_2, end_line_flag);
	else if (err_n == ERROR_N_PARSING_3)
		ft_put_str(fd, ERROR_PARSING_3, end_line_flag);
	else if (err_n == ERROR_N_PARSING_4)
		ft_put_str(fd, ERROR_PARSING_4, end_line_flag);
	else if (err_n == ERROR_N_PARSING_5)
		ft_put_str(fd, ERROR_PARSING_5, end_line_flag);
	else if (err_n == ERROR_N_PARSING_7)
		ft_put_str(fd, ERROR_PARSING_7, end_line_flag);
	else if (err_n == ERROR_N_SYS_CALL)
		ft_put_str(fd, ERROR_SYS_CALL, end_line_flag);
	if (errno && end_line_flag != 3)
		perror("");
	else if (end_line_flag == 2)
		write(2, "\n", 1);
}

void	init_parser_size(t_parser_ctx *ctx)
{
	ctx->i = -1;
	ctx->pnts_cnt = 0;
	ctx->lin_pnts_cnt = 0;
	ctx->height_cnt = 0;
}

void	init_keys_map_1(t_keys_map *keys_1)
{
	keys_1[0].key = KEY_1;
	keys_1[0].retval = 3;
	keys_1[1].key = KEY_2;
	keys_1[1].retval = 4;
	keys_1[2].key = KEY_3;
	keys_1[2].retval = 5;
	keys_1[3].key = KEY_4;
	keys_1[3].retval = 6;
	keys_1[4].key = KEY_5;
	keys_1[4].retval = 7;
	keys_1[5].key = KEY_C;
	keys_1[5].retval = 8;
	keys_1[6].key = KEY_PLS2;
	keys_1[6].retval = 9;
	keys_1[7].key = KEY_MIN2;
	keys_1[7].retval = 10;
	keys_1[8].key = KEY_R;
	keys_1[8].retval = 11;
	keys_1[9].key = KEY_G;
	keys_1[9].retval = 12;
	keys_1[10].key = KEY_TIK;
	keys_1[10].retval = 13;
	keys_1[11].key = KEY_Z;
	keys_1[11].retval = 16;
}
