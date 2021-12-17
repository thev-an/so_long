/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:47:06 by antheven          #+#    #+#             */
/*   Updated: 2021/12/17 14:49:18 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "util.h"

int	error(char *s)
{
	write(1, s, ft_strlen(s));
	exit(EXIT_FAILURE);
}
