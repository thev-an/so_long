/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:51:57 by antheven          #+#    #+#             */
/*   Updated: 2021/11/22 22:50:59 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

int				init_screen(t_env *env);
void			pixel_put(t_img *data, int x, int y, int color);
unsigned int	pixel_get(t_img *data, int x, int y);

#endif