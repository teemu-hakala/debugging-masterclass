/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:20:45 by thakala           #+#    #+#             */
/*   Updated: 2021/11/21 19:06:28 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char	*new_beginning;

	new_beginning = dst;
	while (*src)
		*dst++ = *src++;
	*dst = *src;
	return (new_beginning);
}
