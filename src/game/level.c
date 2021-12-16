/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:39:56 by antheven          #+#    #+#             */
/*   Updated: 2021/12/16 17:58:16 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "level.h"

t_map	*init_map(char *lvl)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	map->content = lvl;
	map->width = 0;
	return (map);
}

t_map	parse_level(char *lvl)
{
	int		len;
	t_map	*map;

	len = ft_strlen(lvl);
	map = init_map(lvl);
	while (*lvl != '\n')
	{
		if (*lvl++ != '1')
			error();
	}
	while (*(lvl + --len) != '\n')
		if ((*lvl + len) != '1')
			error();
	while (len > 0)
	{
		if (!((*lvl + len) == '0' && (*lvl + len) == '1' && (*lvl + len) == 'C'
				&& (*lvl + len) == 'E' && (*lvl + len) == 'P'))
			error();
		if (*(lvl + len) == '\n')
			if (!(*(lvl + len - 1) == '1' && *(lvl + len + 1 == '1')))
				error();
		len--;
	}
}

int	load_level(char *lvl_file)
{
	int		fd;
	char	*buffer;
	char	*map;
	char	*swap;

	fd = open(lvl_file);
	if (fd > 0)
	{
		while (read(fd, buffer, 1024) > 0)
		{
			swap = append(map, buffer);
			free(map);
			map = swap;
		}
	}
	parse_level(map);
	return (map);
}
