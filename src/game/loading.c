/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:37:58 by antheven          #+#    #+#             */
/*   Updated: 2021/12/17 16:09:57 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "env.h"
#include "loop.h"
#include "keyboard.h"
#include "level.h"

int	get_new_texture(t_env *env)
{
	t_list	*gl;
	t_list	*l;
	t_img	*img;
	int		i;

	gl = env->tex;
	i = 0;
	if (gl)
	{
		i++;
		while (gl->next)
		{
			gl = gl->next;
			i++;
		}
	}
	l = malloc(sizeof(t_list));
	if (!l)
		return (0);
	if (gl)
		gl->next = l;
	else
		env->tex = l;
	l->next = 0;
	img = malloc(sizeof(t_img));
	if (!img)
	{
		free(l);
		return (0);
	}
	l->data = img;
	return (i);
}

int	load_texture(t_env *env, char *name, char *path)
{
	void	*img;
	int		w;
	int		h;
	t_img	*current_tex;

	img = mlx_xpm_file_to_image(env->display_ptr, path, &w, &h);
	current_tex = get_tex_by_id(env, get_new_texture(env));
	current_tex->ptr = img;
	current_tex->width = w;
	current_tex->height = h;
	current_tex->name = name;
	current_tex->tex_path = path;
	current_tex->data = mlx_get_data_addr(img, &current_tex->bpp, &current_tex->sl, &current_tex->e);
	return (1);
}

int	load_game(t_env *env)
{
	int	i;

	env->tex = 0;
	env->mouse.x = 0;
	env->mouse.y = 0;
	env->player.x = 1;
	env->player.y = 1;

	i = -1;
	while (++i < 65535)
		env->keyboard.key_press[i] = 0;
	load_texture(env, "floor", "./floor.xpm");
	load_texture(env, "wall", "./wall.xpm");
	load_texture(env, "key", "./key.xpm");
	load_texture(env, "player", "./player.xpm");
	env->map = load_level(env->map_file);
	env->screen = get_new_image(env, 800, 600, 0x00FF00);
	mlx_loop_hook(env->display_ptr, loop, env);
	mlx_hook(env->window, 6, 1L<<6, mouse_motion, env);
	mlx_hook(env->window, 2, 1L<<0, key_press, env);
	mlx_hook(env->window, 3, 1L<<1, key_release, env);
	mlx_loop(env->display_ptr);
	return (1);
}
