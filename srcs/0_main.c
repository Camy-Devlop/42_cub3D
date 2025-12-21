/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 02:03:55 by alephoen          #+#    #+#             */
/*   Updated: 2025/12/21 02:10:44 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	cub3d(int ac, const char **av);

int	main(int ac, char **av)
{
	// check if the number of arguments is correct!
	cub3d(ac - 1, (const char **)(av + 1));
	return (0);
}
