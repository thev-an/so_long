/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:56:59 by antheven          #+#    #+#             */
/*   Updated: 2021/11/26 15:19:34 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "env.h"
#include "keyboard.h"

int	key_press(int keycode, t_env *env)
{
	env->keyboard.key_press[keycode] = 1;
	return (1);
}

int	key_release(int keycode, t_env *env)
{
	env->keyboard.key_press[keycode] = 0;
	return (1);
}

void	key_loop(t_env *env)
{
	int	i;

	i = -1;
	while (++i < 65535)
		if (env->keyboard.key_press[i])
		{
			printf("key_pressed=%i\n", i);
			if (i == KEY_W)
				env->player.y--;
			if (i == KEY_A)
				env->player.x--;
			if (i == KEY_S)
				env->player.y++;
			if (i == KEY_D)
				env->player.x++;
		}
}
