/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:37:58 by antheven          #+#    #+#             */
/*   Updated: 2021/11/20 14:59:05 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "loop.h"

int	load_game(t_env *env)
{
	mlx_loop_hook(env->display_ptr, loop, env);
	mlx_loop(env->display_ptr);
}
