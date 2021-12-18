/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:37:28 by antheven          #+#    #+#             */
/*   Updated: 2021/12/18 02:35:16 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "env.h"

int	check_collectible(t_env *env, int *t, int x, int y)
{
	if (*t == 'C')
	{
		*t = '2';
		if (env->player.x == x && env->player.y == y)
		{
			env->map->content[y * (env->map->width + 1) + x] = '0';
			env->player.points++;
			return (1);
		}
	}
	return (0);
}

int	check_exit(t_env *env, int *t, int x, int y)
{
	if (*t == 'E')
	{
		*t = '4';
		if (env->player.x == x && env->player.y == y)
		{
			if (env->player.points >= env->map->max_points)
			{
				printf("You won the game in %d moves\n", env->player.moves);
				end_level(env);
			}
			return (1);
		}
	}
	return (0);
}

int	draw_level(t_env *env)
{
	int	x;
	int	y;
	int	i;

	y = env->map->height;
	while (y-- > 0)
	{
		x = env->map->width;
		while (x-- > 0)
		{
			i = env->map->content[y * (env->map->width + 1) + x];
			check_collectible(env, &i, x, y);
			check_exit(env, &i, x, y);
			if (i == 'P')
				i = '0';
			i -= '0';
			draw_tile(env, i, x, y);
		}
	}
	return (1);
}
