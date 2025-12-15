/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:01:18 by isadbaib          #+#    #+#             */
/*   Updated: 2025/12/15 12:25:35 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int  printf(const char *s, ...);
#include "../libs/libft/incs/libft.h"
int main()
{
	char *s="Adbaibi";
	printf("string = %s, longeur =%zu\n",s,ft_strlen(s));
	return (0);
}
