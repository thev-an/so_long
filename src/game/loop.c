/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:47:35 by antheven          #+#    #+#             */
/*   Updated: 2021/11/23 00:42:29 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "env.h"
#include "display.h"

void	draw_sprite(t_env *env, int tex_id, int x, int y)
{
	t_img	*tex;
	int		tx;
	int		ty;
	int		color;

	tex = get_tex_by_id(env, tex_id);
	tx = x + 32;
	while (tx-- > x)
	{
		ty = y + 32;
		while (ty-- > y)
		{
			color = pixel_get(tex, (tx - x) * tex->width / 32, (ty - y) * tex->height / 32);
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

	x *= 32;
	y *= 32;
	tex = get_tex_by_id(env, tex_id);
	tx = x + 32;
	while (tx-- > x)
	{
		ty = y + 32;
		while (ty-- > y)
			pixel_put(env->screen, tx, ty, pixel_get(tex, (tx - x) * tex->width / 32, (ty - y) * tex->height / 32));
	}
}

int	mouse_motion(int x, int y, t_env *env)
{
	env->mouse.x = x;
	env->mouse.y = y;
}

int	loop(t_env *env)
{
	int	x;
	int	y;

	x = 800 / 32 - 1;
	while (x-- > 0)
	{
		y = 600 / 32;
		while (y-- > 0)
			draw_tile(env, 0, x, y);
	}
	x = 800 / 32;
	y = 600 / 32;
	while (x-- > 0)
	{
		draw_tile(env, 1, x, y);
		draw_tile(env, 1, x, 0);
	}
	x = 800 / 32 - 1;
	y = 600 / 32;
	while (y-- > 0)
	{
		draw_tile(env, 1, x, y);
		draw_tile(env, 1, 0, y);
	}
	draw_tile(env, 1, 1, 1);
	//draw_sprite(env, 2, 2*32, 2*32);
	draw_sprite(env, 3, env->mouse.x - 16, env->mouse.y - 16);
	mlx_put_image_to_window(env->display_ptr, env->window, env->screen->ptr, 0, 0);
	return (0);
}
