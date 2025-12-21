/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_round.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:49:27 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/12 12:52:06 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_int_round(double x)
{
	int	rounded;

	rounded = (int) x;
	if (x - rounded >= 0.5)
		++rounded;
	return (rounded);
}
