/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:25:34 by antheven          #+#    #+#             */
/*   Updated: 2021/11/20 14:54:58 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "display.h"
#include "game.h"

int	main(int argc, char **argv)
{
	t_env	env;

	init_screen(&env);
	load_game(&env);
}
