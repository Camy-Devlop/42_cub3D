/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:13:01 by alephoen          #+#    #+#             */
/*   Updated: 2025/12/06 16:37:20 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static void	cp_strings(char *str, char *s[3], size_t len[3]);

char	*ft_strjoin3(
			char **ss1,
			char *s2,
			char *s3,
			size_t len[3])
{
	char	*str;
	char	*s1;
	char	*s[3];

	if (!ss1 && !s2 && !s3)
		return (NULL);
	s1 = *ss1;
	str = (char *) malloc(sizeof(char) * (len[0] + len[1] + len[2] + 1));
	if (!str)
		return (NULL);
	s[0] = s1;
	s[1] = s2;
	s[2] = s3;
	cp_strings(str, s, len);
	free(*ss1);
	*ss1 = str;
	return (str);
}

static void	cp_strings(char *str, char *s[3], size_t len[3])
{
	char	*s1;
	char	*s2;
	char	*s3;
	size_t	i;
	size_t	j;

	s1 = s[0];
	s2 = s[1];
	s3 = s[2];
	i = -1;
	if (s1)
		while (++i < len[0])
			str[i] = s1[i];
	i = len[0] - 1;
	j = -1;
	if (s2)
		while (++j < len[1])
			str[++i] = s2[j];
	j = -1;
	if (s3)
		while (++j < len[2])
			str[++i] = s3[j];
	str[len[0] + len[1] + len[2]] = '\0';
}

// char	*ft_strjoin3(
// 			char **ss1, size_t len1,
// 			char *s2, size_t len2,
// 			char *s3, size_t len3)
// {
// 	char *str;
// 	char *s1;
// 	size_t i;
// 	size_t j;

// 	if (!ss1 && !s2 && !s3)
// 		return (NULL);
// 	s1 = *ss1;
// 	str = (char *) malloc(sizeof(char) * (len1 + len2 + len3 + 1));
// 	i = -1;
// 	if (s1)
// 		while (++i < len1)
// 			str[i] = s1[i];
// 	i = len1 - 1;
// 	j = -1;
// 	if (s2)
// 		while (++j < len2)
// 			str[++i] = s2[j];
// 	j = -1;
// 	if (s3)
// 		while (++j < len3)
// 			str[++i] = s3[j];
// 	str[len1 + len2 + len3] = '\0';
// 	free(*ss1);
// 	*ss1 = str;
// 	return (str);
// }
