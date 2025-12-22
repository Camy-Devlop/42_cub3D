/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:50:29 by isadbaib          #+#    #+#             */
/*   Updated: 2025/12/22 23:28:23 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>

bool	is_exist_file(char *addres)
{
	int	fd;

	if (!addres)
		return (printf("Error : not adddress\n"), false);
	fd = open(addres, O_RDONLY);
	if (fd < 0)
		return (printf("Error : file not exist or not permission\n"), false);
	close(fd);
	return (true);
}

bool	check_list_addres(char **list, int n)
{
	int	i;

	if (n < 1)
		return (printf("Error : Asset not complet\n"), false);
	i = -1;
	while (++i < n)
	{
		if (!is_exist_file(list[i]))
			return (false);
	}
	return (true);
}
