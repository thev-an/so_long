/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:32:52 by antheven          #+#    #+#             */
/*   Updated: 2021/12/17 16:10:40 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "level.h"

enum e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};
typedef enum e_dir t_dir;

struct s_kb
{
    char    key_press[65535];
};
typedef struct s_kb t_kb;
struct s_img
{
	void	*ptr;
	char	*data;
	char	*name;
	char	*tex_path;
	int		width;
	int		height;
	int		bpp;
	int		sl;
	int		e;
};
typedef struct s_img	t_img;
struct s_list
{
	void	*data;
	void	*next;
};
typedef struct s_list	t_list;
struct s_mouse
{
	int	x;
	int	y;
};
typedef struct s_mouse	t_mouse;
struct s_player
{
	int		x;
	int		y;
	char	alive;
};
typedef struct s_player	t_plr;

struct s_env
{
	void	*display_ptr;
	void	*window;
	t_img	*screen;
	t_kb	keyboard;
	t_plr	player;
	t_list	*tex;
	t_mouse	mouse;
	char	*map_file;
	t_map	*map;
};
typedef struct s_env	t_env;

t_img	*get_new_image(t_env *env, int w, int h, int color);
t_img	*get_tex_by_id(t_env *env, int id);

#endif