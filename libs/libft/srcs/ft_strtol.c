/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 04:14:51 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/09 17:00:48 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>

static int		parse_space_nd_sign(
					const char **str,
					const char **endptr, int base, int *sign);
static long	int	return_me(
					const char *str,
					const char **endptr, long long nb, int sign);

/*
** This version only accepts 1 as base for base 10;
** This version of ft_strtol() handles only base 10;
** ERRNO is not used here to stay flexible with the 42 norms;
*/
long int	ft_strtol(const char *str, const char **endptr, int base)
{
	long long	nb;
	int			sign;

	if (!parse_space_nd_sign(&str, endptr, base, &sign))
		return (0);
	nb = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (nb > LONG_MAX / 10
			|| (nb == LONG_MAX / 10 && (*str - '0' > LONG_MAX % 10)))
		{
			if (endptr)
				*endptr = str;
			if (sign == 1)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		nb = (nb * 10) + (*str - '0');
		++str;
	}
	return (return_me(str, endptr, nb, sign));
}

static int	parse_space_nd_sign(
				const char **str, const char **endptr, int base, int *sign)
{
	if (!str || !(*str) || base <= 0 || base > 1)
	{
		if (endptr)
			*endptr = NULL;
		return (0);
	}
	while (*(*str) == 32 || (9 <= *(*str) && *(*str) <= 13))
		++(*str);
	*sign = 1;
	if (*(*str) == '-')
		*sign = -1;
	if (*(*str) == '-' || *(*str) == '+')
		++(*str);
	return (1);
}

static long int	return_me(
					const char *str,
					const char **endptr, long long nb, int sign)
{
	if (endptr)
		*endptr = str;
	return ((long int)(sign * nb));
}
