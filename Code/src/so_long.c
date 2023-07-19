/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:03:04 by jariza-o          #+#    #+#             */
/*   Updated: 2023/07/19 21:23:18 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game; //porque es t_game game y no t_game *game
	//char	**map;

	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "--help")) //porque si esta mal llamado el ft _strcmp sin el ! se te va al else de sin argumentos
		{
			//LLAMAR VARIABLE PARA HELP
		}
		else
		{
			if (!ft_check_file(argv[1])) //comprueba que el fichero es .ber y que existe
				return (0);
			game.map = ft_read_map(argv[1]);
			game.map_copy = ft_read_map(argv[1]);
			if (!map_checker(&game)) //si todos los demás checkers son correctos
			{
				ft_printf("GOOD %s\n", game.map[0]);
			}
			// if (!ft_check_symbols(&game))
			// 	ft_printf("Error: The map has incorrect symbols.");
			// if (!ft_check_exit(&game))
			// 	ft_printf("Error: The map has no or several exits.");
			// if (!ft_check_obj(&game))
			// 	ft_printf("Error: The map is missing objects.");
			// if (!ft_check_init(&game))
			// 	ft_printf("Error: The map is missing or has several entries");
			// if (!ft_check_form(&game))
			// 	ft_printf("Error: The map shape is not correct.");
			// if (!ft_check_walls(&game))
			// 	ft_printf("Error: The map does not have the correct walls.");
		}
	}
	else
	{
		ft_printf("Arguments are not correct. For help run: so_long --help");
		ft_printf(" For help run: so_long --help\n");
	}
	return (0);
}
