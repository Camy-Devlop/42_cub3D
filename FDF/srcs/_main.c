/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:28:49 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/04 12:48:54 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

void	fdf(int ac, char **av);

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "incorrect number of arguments!", 30);
		exit(EXIT_FAILURE);
	}
	fdf(ac, av);
	return (0);
}
