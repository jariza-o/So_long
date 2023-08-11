/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:03:04 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/09 16:16:56 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_so_long(t_game *game)
{
	mlx_set_setting(MLX_MAXIMIZED, true); //nose si esto iría aquí
	game->mlx = mlx_init(game->map_size.x_position * SPRITE, game->map_size.y_position * SPRITE, "so_long", false);
	if (!game->mlx)
	{
		ft_printf("Graphic error\n"); //ELIMINAR
		exit(1); //porque???
		// CREAR FUNCIÖN ERROR
	}
	//Load MAP TEXTURE
	ft_load_textures(game);
	
	//Render MAP
	ft_render_floor(game);
	ft_render_others(game);
	ft_render_person(game);
	mlx_key_hook(game->mlx, keys, game);
	mlx_loop(game->mlx); // mantener abierto el juego
	mlx_terminate(game->mlx); // cerrar el juego
}

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
				ft_so_long(&game);
			ft_free(game); // HAY QUE LIBERAR ALGO DE LA LIBRERIA??
		}
	}
	else
		ft_printf("Arguments are not correct. For help run: so_long --help\n");
	return (0);
}
