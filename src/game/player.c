/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 00:15:30 by antheven          #+#    #+#             */
/*   Updated: 2021/12/18 01:48:59 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "env.h"
#include "player.h"

void	move(t_env *env, t_dir dir)
{
	int	x;
	int	y;

	x = env->player.x;
	y = env->player.y;
	if (dir == NORTH)
		if (y > 0)
			if (env->map->content[(y - 1) * (env->map->width + 1) + x] != '1')
				env->player.y--;
	if (dir == EAST)
		if (x > 0)
			if (env->map->content[y * (env->map->width + 1) + (x - 1)] != '1')
				env->player.x--;
	if (dir == SOUTH)
		if (y < env->map->height)
			if (env->map->content[(y + 1) * (env->map->width + 1) + x] != '1')
				env->player.y++;
	if (dir == WEST)
		if (x < env->map->width)
			if (env->map->content[y * (env->map->width + 1) + (x + 1)] != '1')
				env->player.x++;
	if (x != env->player.x || y != env->player.y)
		printf("%d moves\n", ++env->player.moves);
}
