/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:47:35 by antheven          #+#    #+#             */
/*   Updated: 2021/12/18 03:57:50 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "env.h"
#include "display.h"
#include "keyboard.h"

void	draw_sprite(t_env *env, int tex_id, int x, int y)
{
	t_img	*tex;
	int		tx;
	int		ty;
	int		color;
	t_mouse	red_pt;

	tex = get_tex_by_id(env, tex_id);
	tx = x + 32;
	while (tx-- > x)
	{
		ty = y + 32;
		while (ty-- > y)
		{
			red_pt.x = (tx - x) * tex->width / 32;
			red_pt.y = (ty - y) * tex->height / 32;
			color = pixel_get(tex, red_pt.x, red_pt.y);
			if (color != 0xFF00FF)
				pixel_put(env->screen, tx, ty, color);
		}
	}
}

void	draw_tile(t_env *env, int tex_id, int x, int y)
{
	t_img	*tex;
	int		tx;
	int		ty;
	int		color;
	t_mouse	red_pt;

	x *= 32;
	y *= 32;
	tex = get_tex_by_id(env, tex_id);
	tx = x + 32;
	while (tx-- > x)
	{
		ty = y + 32;
		while (ty-- > y)
		{
			red_pt.x = (tx - x) * tex->width / 32;
			red_pt.y = (ty - y) * tex->height / 32;
			color = pixel_get(tex, red_pt.x, red_pt.y);
			if (color != 0xFF00FF)
				pixel_put(env->screen, tx, ty, color);
		}
	}
}

int	mouse_motion(int x, int y, t_env *env)
{
	env->mouse.x = x;
	env->mouse.y = y;
	return (1);
}

int	loop(t_env *env)
{
	int	x;
	int	y;

	x = 800 / 32;
	while (x-- > 0)
	{
		y = 600 / 32 + 1;
		while (y-- > 0)
			draw_tile(env, 0, x, y);
	}
	if (draw_level(env) == 0)
	{
		printf("Error\nparsing[mini 1 exit]\n");
		end_level(env);
	}
	key_loop(env);
	draw_tile(env, 3, env->player.x, env->player.y);
	draw_buffer(env);
	return (0);
}
