/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:37:58 by antheven          #+#    #+#             */
/*   Updated: 2021/12/18 03:54:04 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "util.h"
#include "env.h"
#include "loop.h"
#include "keyboard.h"
#include "level.h"

int	load_texture(t_env *env, char *name, char *path)
{
	void	*img;
	int		w;
	int		h;
	t_img	*c;

	img = mlx_xpm_file_to_image(env->display_ptr, path, &w, &h);
	if (!img)
	{
		unload_textures(env);
		mlx_destroy_window(env->display_ptr, env->window);
		mlx_destroy_display(env->display_ptr);
		free(env->display_ptr);
		error("Error\ncannot load texture\n");
	}
	c = get_tex_by_id(env, get_new_texture(env));
	c->ptr = img;
	c->width = w;
	c->height = h;
	c->name = name;
	c->tex_path = path;
	c->data = mlx_get_data_addr(img, &c->bpp, &c->sl, &c->e);
	return (1);
}

int	load_textures(t_env *env)
{
	load_texture(env, "floor", "./floor.xpm");
	load_texture(env, "wall", "./wall.xpm");
	load_texture(env, "key", "./key.xpm");
	load_texture(env, "player", "./player.xpm");
	load_texture(env, "door", "./door.xpm");
	return (1);
}

int	load_screen(t_env *env)
{
	if (env->map->max_points == 0)
	{
		printf("Error\nparsing[mini 1 collectible]\n");
		end_level(env);
	}
	mlx_loop_hook(env->display_ptr, loop, env);
	mlx_hook(env->window, 6, 1L << 6, mouse_motion, env);
	mlx_hook(env->window, 2, 1L << 0, key_press, env);
	mlx_hook(env->window, 3, 1L << 1, key_release, env);
	mlx_hook(env->window, 17, 0L, end_level, env);
	mlx_loop(env->display_ptr);
	return (1);
}

int	init_env(t_env *env)
{
	int	i;

	env->tex = 0;
	env->mouse.x = 0;
	env->mouse.y = 0;
	env->player.points = 0;
	env->player.moves = 0;
	env->player.x = -1;
	env->player.y = -1;
	i = -1;
	while (++i < 65535)
		env->keyboard.key_press[i] = 0;
	load_textures(env);
	env->map = load_level(env->map_file);
	env->screen = get_new_image(env, 800, 600, 0x00FF00);
	return (1);
}

int	load_game(t_env *env)
{
	int	x;
	int	y;

	init_env(env);
	y = env->map->height;
	while (y-- > 0)
	{
		x = env->map->width;
		while (x-- > 0)
		{
			if (env->map->content[y * (env->map->width + 1) + x] == 'P')
			{
				env->player.x = x;
				env->player.y = y;
				break ;
			}
		}
	}
	if (env->player.x == -1 && env->player.y == -1)
	{
		printf("Error\nparsing[need player]\n");
		end_level(env);
	}
	load_screen(env);
	return (1);
}
