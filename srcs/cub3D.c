/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:01:18 by isadbaib          #+#    #+#             */
/*   Updated: 2025/12/18 13:02:57 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int  printf(const char *s, ...);
#include <libft.h>
#include <gnl.h>
int main()
{
	t_gnl_buf *file = calloc(1sizeof(t_gnl_buf));

	
	char *s="Adbaibi";
	printf("string = %s, longeur =%zu\n",s,ft_strlen(s));
	

	return (0);
}
