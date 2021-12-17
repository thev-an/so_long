/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:39:56 by antheven          #+#    #+#             */
/*   Updated: 2021/12/17 20:54:37 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "util.h"
#include "level.h"

t_map	*init_map(char *lvl)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	map->content = lvl;
	map->width = 0;
	map->height = 0;
	map->max_points = 0;
	return (map);
}

t_map	*parse_level(char *lvl)
{
	int		len;
	int		i;
	t_map	*map;

	map = init_map(lvl);
	while (*lvl && *lvl != '\n')
	{
		write(1, lvl, 1);
		if (*lvl != '1')
			error("Error\nparsing[first line]\n");
		map->width++;
		lvl++;
	}
	write(1, "\n", 1);
	len = ft_strlen(lvl);
		write(1, lvl, len);
	write(1, "\n", 1);
	i = 0;
	while (*(lvl + --len) != '\n')
	{
		write(1, lvl + len, 1);
		if (*(lvl + len) != '1')
			error("Error\nparsing[last line]\n");
		i++;
	}
	write(1, "\n", 1);
	while (len > 0)
	{
		if (!(*(lvl + len) == '0' || *(lvl + len) == '1' || *(lvl + len) == 'C'
				|| *(lvl + len) == 'E' || *(lvl + len) == 'P'))
		{
			if (*(lvl + len) != '\n')
			{
				error("Error\nparsing[block invalid]\n");
			}
			else
			{
			}
		}
		if (*(lvl + len) == 'C')
			map->max_points++;
		if (*(lvl + len) == '\n')
		{
			if (!(*(lvl + len - 1) == '1' && *(lvl + len + 1) == '1'))
				error("Error\nparsing[wall invalid]\n");
			//printf("map=%d\ni=%d\n", map->width, i);
			if (i != map->width)
				error("Error\nparsing[invalid size]\n");
			i = 0;
			len--;
		}
		i++;
		len--;
	}
	map->height = ft_strlen(map->content) / map->width;
	printf("%d\n", map->height);
	return (map);
}

t_map	*load_level(char *lvl_file)
{
	int		fd;
	char	*buffer;
	char	*map;
	char	*swap;

	fd = open(lvl_file, O_RDONLY);
	buffer = malloc(2);
	*(buffer + 1) = 0;
	map = malloc(1);
	*map = 0;
	if (fd > 0)
	{
		while (read(fd, buffer, 1) > 0)
		{
			//write(1, lvl_file, ft_strlen(lvl_file));
			//printf("%s", buffer);
			swap = append(map, buffer);
			free(map);
			map = swap;
		}
		return (parse_level(map));
	}
	return (NULL);
}
