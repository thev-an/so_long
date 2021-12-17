/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:18:49 by antheven          #+#    #+#             */
/*   Updated: 2021/12/17 20:53:59 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_H
# define LEVEL_H

typedef struct s_map
{
	char	*content;
	int		width;
	int		height;
	int		max_points;
}		t_map;

t_map	*load_level(char *lvl_file);

#endif