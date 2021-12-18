/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:25:34 by antheven          #+#    #+#             */
/*   Updated: 2021/12/18 02:53:47 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "display.h"
#include "util.h"
#include "game.h"
#include <stdlib.h>
#include <unistd.h>

void	check_filename(char *arg)
{
	int		arg_len;
	int		i;
	char	*file_ext;

	file_ext = "reb.";
	i = ft_strlen(file_ext);
	arg_len = ft_strlen(arg);
	while (i > 0)
	{
		if (*(arg - i) != *(file_ext + i - 1))
			error("Error\nfile extension");
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
	{
		check_filename(argv[1]);
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
