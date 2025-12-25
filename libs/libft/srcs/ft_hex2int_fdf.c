/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex2int_fdf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:54:24 by alephoen          #+#    #+#             */
/*   Updated: 2025/12/25 17:45:08 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include <ctype.h>

// #include <stdio.h>

static int	hex2uint(const char *hex, size_t i);

int	ft_hex2uint(const char *hex)
{
	int		i;
	int		result;

	if (!hex)
		return (0);
	i = -1;
	while (hex[++i] && hex[i] != ' ')
		;
	if (hex[i] && hex[++i] && hex[i] == ',')
	{}
	while (hex[i] && hex[++i] && hex[i] != ' ')
		;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		hex += 2;
	i = -1;
	result = hex2uint(hex, i);
	return (result);
}

static int	hex2uint(const char *hex, size_t i)
{
	int	result;
	int	value;

	result = 0;
	while (hex[++i])
	{
		if (isdigit((unsigned char)hex[i]))
			value = hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			value = 10 + (hex[i] - 'a');
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			value = 10 + (hex[i] - 'A');
		else
			break ;
		if (result > (INT_MAX - value) / 16)
			return (INT_MAX);
		result = result * 16 + value;
	}
	return (result);
}
