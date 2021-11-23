/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:55:27 by antheven          #+#    #+#             */
/*   Updated: 2021/11/23 17:59:38 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

struct s_kb
{

};
typedef struct s_kb t_kb;

int	key_press(int keycode, t_env *env);
int	key_release(int keycode, t_env *env);

#endif