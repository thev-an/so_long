/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:25:34 by antheven          #+#    #+#             */
/*   Updated: 2021/12/18 03:28:35 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "display.h"
#include "util.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	check_filename(char *arg)
{
	int		arg_len;

	arg_len = ft_strlen(arg);
	printf("%s\n", arg + arg_len - 4);
	if (ft_strncmp(arg + arg_len - 4, ".ber", 4))
		error("Error\nfile extension\n");
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
	{
		write(1, "Error\nmap file\n", 15);
		return (EXIT_FAILURE);
	}
	check_filename(argv[1]);
	if (!init_screen(&env))
	{
		write(1, "Error\ninit_screen();\n", 21);
		return (EXIT_FAILURE);
	}
	env.map_file = argv[1];
	load_game(&env);
	return (EXIT_SUCCESS);
}
