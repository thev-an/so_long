/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 00:15:30 by antheven          #+#    #+#             */
/*   Updated: 2021/11/27 00:23:45 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "player.h"

void	move(t_env *env, t_dir dir)
{
	if (dir == NORTH)
		if (env->player.y > 0)
			env->player.y--;
	if (dir == EAST)
		if (env->player.x > 0)
			env->player.x--;
	if (dir == SOUTH)
		if (env->player.y < 10)
			env->player.y++;
	if (dir == WEST)
		if (env->player.x < 10)
			env->player.x++;
}
