/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:14:12 by alephoen          #+#    #+#             */
/*   Updated: 2025/04/18 14:05:37 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char) c;
	while (*s)
	{
		if ((unsigned char) *s == uc)
			return ((char *) s);
		++s;
	}
	if (uc == '\0')
		return ((char *) s);
	return (NULL);
}

/*
#include "libft.h"
#include <stdio.h>
#include <string.h>

static void test_strchr_case(const char *s, int c)
{
	char *std_res = strchr(s, c);
	char *ft_res  = ft_strchr(s, c);
	printf(
		"ft_strchr(\"%s\", %d ('%c')): std=%p, ft=%p -> %s\n",
		s,
		c,
		(char)c,
		(void *)std_res,
		(void *)ft_res,
		(std_res == ft_res) ? "PASS" : "FAIL"
	);
}

int main(void)
{
	Basic matches
	test_strchr_case("hello world", 'h');      // first char
	test_strchr_case("hello world", 'o');      // middle char
	test_strchr_case("hello world", 'd');      // last char

	// Not found
	test_strchr_case("hello world", 'z');

	Null terminator
	test_strchr_case("hello world", '\0');

	// Empty string
	test_strchr_case("", 'a');
	test_strchr_case("", '\0');

	// Multiple occurrences
	test_strchr_case("aaaaaa", 'a');

	// Embedded null (\"abc\0def\")
	test_strchr_case("abc\0def", 'd');

	// Extended values
	test_strchr_case("\xff A", 0xFF);  // high-bit char
	test_strchr_case("\xff A", 0x1FF); // wrapped into 0xFF

	// Non-printable control
	test_strchr_case("\n\t text", '\n');

	return 0;
}
*/
