/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:39:56 by antheven          #+#    #+#             */
/*   Updated: 2021/12/18 02:34:41 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"
#include "util.h"
#include "env.h"
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

int	parse_blocks(t_map *map, char *lvl, int len, int i)
{
	while (len >= 0)
	{
		if (!(*(lvl + len) == '0' || *(lvl + len) == '1' || *(lvl + len) == 'C'
				|| *(lvl + len) == 'E' || *(lvl + len) == 'P'))
		{
			if (*(lvl + len) != '\n')
			{
				error("Error\nparsing[block invalid]\n");
			}
		}
		if (*(lvl + len) == 'C')
			map->max_points++;
		if (*(lvl + len) == '\n' || len == 0)
		{
			if (!(*(lvl + len - 1) == '1' && *(lvl + len + 1) == '1'))
				error("Error\nparsing[wall invalid]\n");
			if (i != map->width)
				error("Error\nparsing[invalid size]\n");
			i = 0;
			len--;
		}
		i++;
		len--;
	}
	return (1);
}

t_map	*parse_level(char *lvl)
{
	int		len;
	int		i;
	t_map	*map;

	map = init_map(lvl);
	while (*lvl && *lvl != '\n')
	{
		if (*lvl != '1')
			error("Error\nparsing[first line]\n");
		map->width++;
		lvl++;
	}
	len = ft_strlen(lvl);
	i = 0;
	while (*(lvl + --len) != '\n')
	{
		if (*(lvl + len) != '1')
			error("Error\nparsing[last line]\n");
		i++;
	}
	parse_blocks(map, lvl, len, i);
	map->height = ft_strlen(map->content) / map->width;
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
			swap = append(map, buffer);
			free(map);
			map = swap;
		}
		free(buffer);
		return (parse_level(map));
	}
	return (NULL);
}

int	end_level(t_env *env)
{
	free(env->map->content);
	free(env->map);
	mlx_destroy_image(env->display_ptr, env->screen->ptr);
	free(env->screen);
	unload_textures(env);
	mlx_destroy_window(env->display_ptr, env->window);
	mlx_destroy_display(env->display_ptr);
	mlx_loop_end(env->display_ptr);
	free(env->display_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}
