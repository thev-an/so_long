/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:27:08 by antheven          #+#    #+#             */
/*   Updated: 2021/12/18 02:46:29 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "loop.h"

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (!(x >= 0 && x < data->width))
		return ;
	if (!(y >= 0 && y < data->height))
		return ;
	dst = data->data + (y * data->sl + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	pixel_get(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->data + (y * data->sl + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

int	init_screen(t_env *env)
{
	env->display_ptr = mlx_init();
	if (!env->display_ptr)
		return (0);
	env->window = mlx_new_window(env->display_ptr, 800, 600, "test");
	return (1);
}

int	draw_buffer(t_env *env)
{
	void	*disp;
	void	*win;
	void	*buf;

	disp = env->display_ptr;
	win = env->window;
	buf = env->screen->ptr;
	mlx_put_image_to_window(disp, win, buf, 0, 0);
	return (1);
}
