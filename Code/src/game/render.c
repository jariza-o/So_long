/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:26:52 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/09 16:16:45 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_load_textures(t_game *game)
{
	game->textures.floor = mlx_load_png("/Users/jariza-o/Desktop/so_long/Code/src/textures/floor.png");
	game->textures.walls = mlx_load_png("/Users/jariza-o/Desktop/so_long/Code/src/textures/wall_1.png"); // VER PORQUE HAY QUE PONER RUTA COMPLETA
	game->textures.obj = mlx_load_png("/Users/jariza-o/Desktop/so_long/Code/src/textures/object_2.png");
	game->textures.exit = mlx_load_png("/Users/jariza-o/Desktop/so_long/Code/src/textures/exit_1.png");
	game->textures.person = mlx_load_png("/Users/jariza-o/Desktop/so_long/Code/src/textures/player_2.png");
	// PONER FUNCION DE SI NO EXISTE ALGUNO QUE DE FALLO Y LIBERE
	game->images.floor = mlx_texture_to_image(game->mlx, game->textures.floor);
	game->images.walls = mlx_texture_to_image(game->mlx, game->textures.walls);
	game->images.obj = mlx_texture_to_image(game->mlx, game->textures.obj);
	game->images.exit = mlx_texture_to_image(game->mlx, game->textures.exit);
	game->images.person = mlx_texture_to_image(game->mlx, game->textures.person);
	mlx_delete_texture(game->textures.walls);
	mlx_delete_texture(game->textures.floor);
	mlx_delete_texture(game->textures.person);
	mlx_delete_texture(game->textures.obj);
	mlx_delete_texture(game->textures.exit);
	// tengo que liberar game->textures porque ya no se hace, pero puedo hacer free(game->textures) ??
}

void	ft_render_floor(t_game *game)
{
	int	n;
	int	i;

	n = 0;
	while(game->map[n])
	{
		i = 0;
		while (game->map[n][i])
		{
			// game->images.floor = mlx_texture_to_image(game->mlx, game->textures.floor); //nose si se puede poner al principio, a lo mejor ocupa menos mememoria
			if (mlx_image_to_window(game->mlx, game->images.floor, i * SPRITE, n * SPRITE) < 0) // La función mlx_image_to_windows como la llamas en el if se ejecuta hay
				exit(1); //Al principio se pone exit(1) y libera toda la memoria, despues no se aconseja ponerlo.
			i++;
		}
		n++;
	}
}

void	ft_render_others(t_game *game)
{
	int	n;
	int	i;

	n = 0;
	while(game->map[n])
	{
		i = 0;
		while (game->map[n][i])
		{
			if (game->map[n][i] == '1')
			{
				// game->images.walls = mlx_texture_to_image(game->mlx, game->textures.walls);
				if (mlx_image_to_window(game->mlx, game->images.walls, i * SPRITE, n * SPRITE) < 0) // La función mlx_image_to_windows como la llamas en el if se ejecuta hay
					exit(1); //Al principio se pone exit(1) y libera toda la memoria, despues no se aconseja ponerlo.
			}
			else if (game->map[n][i] == 'C')
			{
				// game->images.obj = mlx_texture_to_image(game->mlx, game->textures.obj);
				if (mlx_image_to_window(game->mlx, game->images.obj, i * SPRITE, n * SPRITE) < 0) // La función mlx_image_to_windows como la llamas en el if se ejecuta hay
					exit(1);
			}
			else if (game->map[n][i] == 'E')
			{
				// game->images.exit = mlx_texture_to_image(game->mlx, game->textures.exit);
				if (mlx_image_to_window(game->mlx, game->images.exit, i * SPRITE, n * SPRITE) < 0) // La función mlx_image_to_windows como la llamas en el if se ejecuta hay
					exit(1);
			}
			i++;
		}
		n++;
	}
}

void	ft_render_person(t_game *game)
{
	int	n;
	int	i;

	n = 0;
	while(game->map[n])
	{
		i = 0;
		while(game->map[n][i])
		{
			if (game->map[n][i] == 'P')
				{
					if (mlx_image_to_window(game->mlx, game->images.person, i * SPRITE, n * SPRITE) < 0) // La función mlx_image_to_windows como la llamas en el if se ejecuta hay
						exit(1);
				}
			i++;
		}
		n++;
	}
}