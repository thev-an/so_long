/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:31:08 by antheven          #+#    #+#             */
/*   Updated: 2021/11/22 22:56:13 by antheven         ###   ########.fr       */
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
