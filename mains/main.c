/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:39:48 by thakala           #+#    #+#             */
/*   Updated: 2021/12/21 17:37:19 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strcat(char *s1, const char *s2);

static int	ft_test(const char *s1, const char *s2)
{
	char	*std_catted_str;
	char	*ft_catted_str;
	size_t	catted_len;
	int		result;

	catted_len = strlen(s1) + strlen(s2) + 1;
	std_catted_str = (char *)malloc(sizeof(char) * catted_len);
	ft_catted_str = (char *)malloc(sizeof(char) * catted_len);
	if (!std_catted_str || !ft_catted_str)
	{
		printf("Memory allocation error!\n");
		return (1);
	}
	strcpy(std_catted_str, s1);
	memcpy(ft_catted_str, std_catted_str, catted_len);
	result = strcmp(strcat(std_catted_str, s2), ft_strcat(ft_catted_str, s2));
	free(std_catted_str);
	free(ft_catted_str);
	return (result);
}

int	main(void)
{
	if (ft_test("ft_", "strcat")
		|| ft_test("man", " strcat")
		|| ft_test("", "")
		|| ft_test("\0", "\1"))
	{
		printf("KO: ft_strcat\n");
		return (1);
	}
	printf("OK: ft_strcat\n");
}
