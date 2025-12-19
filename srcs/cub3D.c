/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:01:18 by isadbaib          #+#    #+#             */
/*   Updated: 2025/12/19 17:13:29 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int  printf(const char *s, ...);
#include <libft.h>
#include <get_next_line.h>
#include <fcntl.h>
#include <stdio.h>

void f(vooid);

int main()
{
	t_gnl_buf **file = calloc(1,sizeof(t_gnl_buf*));
	(void)file;
	size_t linlen;
	(void)linlen;
	int fd = open("asset/map/good/map.cub", O_RDONLY);
	
	char *f;
   	f	= get_next_line(fd,&f, &linlen, &file);
	
	close(fd);

	printf("string = %s\n",f);
	

	return (0);
}
