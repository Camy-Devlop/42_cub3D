/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:01:18 by isadbaib          #+#    #+#             */
/*   Updated: 2025/12/25 18:39:19 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int  printf(const char *s, ...);
#include <libft.h>
#include <get_next_line.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool	check_list_addres(char **list, int n);

int main(void)
{
	t_gnl_buf **file = calloc(1,sizeof(t_gnl_buf*));
	t_data_file *f = calloc(1, sizeof(t_data_file));
	(void)file;
	size_t linlen;
	(void)linlen;

/*	char **files = calloc(2,sizeof(char*));
	files[0]=strdup("asset/map/good/map.cub");
	files[1]=strdup("asset/map/good/map.cub11111111111");

	if (check_list_addres(files, 2))
		printf("ok\n");
	else
		printf("no ok\n");

*/
	int fd = open("asset/map/good/map.cub", O_RDONLY);
		
	char	*f;
	bool	fin = false;
   	while (!fin)
	{
		f = get_next_line(fd, &f, &file);
		if (!f)
		{
			fin = true;
		}

	}	
	close(fd);
	printf("string = %s\n",f);
	free(file);
	return (0);
}
