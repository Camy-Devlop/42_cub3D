/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:08:18 by isadbaib          #+#    #+#             */
/*   Updated: 2025/12/25 20:55:54 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_exist_file(char *addres, t_data_file f);

bool ft_check(char *addres, t_data_file **f)
{
	 if (!is_exist_file(addres, f))
	 	return (false);

	 return (true);
}
