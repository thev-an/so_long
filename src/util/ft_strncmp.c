/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:59:13 by antheven          #+#    #+#             */
/*   Updated: 2021/12/18 03:26:34 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	if (n == 0)
		return (0);
	while (--n && *s1 && *s2)
		if (*s1++ != *s2++)
			return (*(unsigned char *)(s1 - 1) - *(unsigned char *)(s2 - 1));
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
