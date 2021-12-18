/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:31:08 by antheven          #+#    #+#             */
/*   Updated: 2021/12/18 02:05:29 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "env.h"
#include "display.h"

t_img	*get_new_image(t_env *env, int w, int h, int color)
{
	t_img	*img;
	int		y;

	img = malloc(sizeof(t_img));
	if (!img)
		return (0);
	img->ptr = mlx_new_image(env->display_ptr, w, h);
	img->width = w;
	img->height = h;
	img->data = mlx_get_data_addr(img->ptr, &img->bpp, &img->sl, &img->e);
	while (w-- > 0)
	{
		y = h;
		while (y-- > 0)
			pixel_put(img, w, y, color);
	}
	return (img);
}

t_img	*get_tex_by_id(t_env *env, int id)
{
	t_list	*tex_list;

	tex_list = env->tex;
	while (id-- > 0)
	{
		if (tex_list->next)
			tex_list = tex_list->next;
		else
			return (0);
	}
	return (tex_list->data);
}

t_list	*new_image_list(void)
{
	t_list	*l;
	t_img	*img;

	l = malloc(sizeof(t_list));
	if (!l)
		return (NULL);
	l->next = 0;
	img = malloc(sizeof(t_img));
	if (!img)
	{
		free(l);
		return (NULL);
	}
	l->data = img;
	return (l);
}

int	get_new_texture(t_env *env)
{
	t_list	*gl;
	t_list	*l;
	int		i;

	gl = env->tex;
	i = 0;
	l = new_image_list();
	if (!l)
		return (0);
	if (gl)
	{
		i++;
		while (gl->next)
		{
			gl = gl->next;
			i++;
		}
		gl->next = l;
	}
	else
		env->tex = l;
	return (i);
}

int	unload_textures(t_env *env)
{
	t_list	*tex;
	t_list	*next;

	tex = env->tex;
	while (tex)
	{
		mlx_destroy_image(env->display_ptr, ((t_img *)(tex->data))->ptr);
		next = tex->next;
		free(tex->data);
		free(tex);
		tex = next;
	}
	return (1);
}
