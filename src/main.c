/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:25:34 by antheven          #+#    #+#             */
/*   Updated: 2021/12/17 14:45:47 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "display.h"
#include "game.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
	{
		write(1, "Error\nmap file\n", 15);
		return (EXIT_FAILURE);
	}
	if (!init_screen(&env))
	{
		write(1, "Error\ninit_screen();\n", 21);
		return (EXIT_FAILURE);
	}
	env.map_file = argv[1];
	load_game(&env);
	return (EXIT_SUCCESS);
}
