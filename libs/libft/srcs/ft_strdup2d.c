/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:00:46 by alephoen          #+#    #+#             */
/*   Updated: 2025/11/16 16:26:52 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// /*
#include "libft.h"

static char	*pv_ft_strdup(const char *src);
static void	*pv_ft_free2dstr(char ***s);

char	**ft_strdup2d(const char **src)
{
	char	**des;
	size_t	srclen;
	size_t	j;

	if (!src || !(*src))
		return (NULL);
	srclen = -1;
	while (src[++srclen])
		;
	des = (char **) malloc(sizeof(char *) * (srclen + 1));
	if (!des)
		return (NULL);
	j = -1;
	while (src[++j])
	{
		des[j] = pv_ft_strdup(src[j]);
		if (!des[j])
			return (pv_ft_free2dstr(&des));
	}
	des[j] = NULL;
	return (des);
}

static char	*pv_ft_strdup(const char *src)
{
	char	*des;
	size_t	srclen;
	size_t	i;

	srclen = -1;
	while (src[++srclen])
		;
	des = (char *) malloc(sizeof(char) * (srclen + 1));
	if (!des)
		return (NULL);
	i = -1;
	while (++i < srclen)
		des[i] = src[i];
	des[i] = '\0';
	return (des);
}

static void	*pv_ft_free2dstr(char ***s)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	while ((*s)[++i])
	{
		free((*s)[i]);
		(*s)[i] = NULL;
	}
	free(*s);
	*s = NULL;
	return (NULL);
}

// */

		// srclen = -1;
		// while (src[++srclen])
		// 	;
		// des[j] = (char **) malloc(sizeof(char *) * (srclen + 1));
		// if (!des)
		// 	return (NULL);
		// i = -1;
		// while (++i < srclen)
		// 	des[j][i] = src[j][i];
		// des[j][i] = '\0';
