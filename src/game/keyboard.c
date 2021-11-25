/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:56:59 by antheven          #+#    #+#             */
/*   Updated: 2021/11/25 18:14:43 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
