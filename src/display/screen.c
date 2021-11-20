/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:27:08 by antheven          #+#    #+#             */
/*   Updated: 2021/11/20 14:55:46 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "loop.h"

int	init_screen(t_env *env)
{
	env->display_ptr = mlx_init();
	env->window = mlx_new_window(env->display_ptr, 800, 600, "test");
}
