/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 02:03:55 by alephoen          #+#    #+#             */
/*   Updated: 2025/12/21 03:24:18 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	cub3d(int ac, const char **av);

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Only 1 argument is acceptable!\n", 31);
		return (1);
	}
	cub3d(ac - 1, (const char **)(av + 1));
	return (0);
}
