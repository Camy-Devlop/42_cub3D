/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:50:29 by isadbaib          #+#    #+#             */
/*   Updated: 2025/12/25 21:05:34 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>

int	ft_nb_line_fd(int fd, t_data_file **f)
{
	bool	test;
	char	**f;
	t_gnl_buf **file;

	file = NULL;
	f = NULL;
	while (test)
	{
		f = get_next_line(fd, &f, &file);
		if (!f)
		{
			fin = true;
			break ;
		}
		ff->nb_line++;
		free(f);
	}
}

bool	is_exist_file(char *addres, t_data_file **f)
{
	int		fd;

	test = false;
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
