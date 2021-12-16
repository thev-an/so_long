/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:24:55 by antheven          #+#    #+#             */
/*   Updated: 2021/12/16 13:41:58 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*append(char *s1, char *s2)
{
	int	s1s;
	int	s2s;
	int	s3;
	int	i;

	i = 0;
	s1s = ft_strlen(s1);
	s2s = ft_strlen(s2);
	s3 = malloc(s1s + s2s + 1);
	if (!s3)
		return (0);
	*(s3 + s2s + s1s) = '\0';
	while (*s1)
		*(s3 + i) = *s1++;
	while (*s2)
		*(s3 + i) = *s2++;
	return (s3);
}
