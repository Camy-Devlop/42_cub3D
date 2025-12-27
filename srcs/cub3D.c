/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:01:18 by isadbaib          #+#    #+#             */
/*   Updated: 2025/12/27 12:11:08 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int  printf(const char *s, ...);
#include <cub3d.h>
#include <libft.h>
#include <get_next_line.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char	*get_next_line(int fd, char **line, t_gnl_buf ***gnl_bufers);
//test
bool	check_list_addres(char **list, int n);

int main(void)
{
	char 		*line;
	t_gnl_buf	**buff;


	int fd = open("asset/map/good/map.cub", O_RDONLY);
	
	while (1)
	{
		line = get_next_line(fd, &line, &buff);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}


	//t_gnl_buf **buff = calloc(1,sizeof(t_gnl_buf**));
	//t_data_file *ff = calloc(1, sizeof(t_data_file));
	//(void)buff;
	//(void)ff;
	//size_t linlen;
	//(void)linlen;

/*	char **files = calloc(2,sizeof(char*));
	files[0]=strdup("asset/map/good/map.cub");
	files[1]=strdup("asset/map/good/map.cub11111111111");

	if (check_list_addres(files, 2))
		printf("ok\n");
	else
		printf("no ok\n");

*/
	//int fd = open("asset/map/good/map.cub", O_RDONLY);
	//	
	//char	*f;
	//bool	fin = false;

   	//while (!fin)
	//{
	//	f = get_next_line(fd, &f, &buff);
	//	if (!f)
	//	{
	//		fin = true;
	//		break ;
	//	}
	//	ff->nb_line++;
	//	free(f);
	//}
	//printf("nombre de ligne = %d\n",ff->nb_line);
	//close(fd);
	////printf("string = %s\n",f);
	//free(ff);
///	//free(file);
	//return (0);
}
