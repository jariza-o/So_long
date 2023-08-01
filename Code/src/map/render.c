/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:26:52 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/01 17:08:34 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_load_textures(t_game *game)
{
	game->textures.walls = mlx_load_png("../../textures/wall.png");
	game->textures.floor = mlx_load_png("../../textures/floor.png");
	game->textures.person = mlx_load_png("../../textures/player.png");
	game->textures.obj = mlx_load_png("../../textures/object.png");
	game->textures.exit = mlx_load_png("../../textures/enemy.png");
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
			game->images.floor = mlx_texture_to_image(game->mlx, game->textures.floor); //nose si se puede poner al principio, a lo mejor ocupa menos mememoria
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
				game->images.walls = mlx_texture_to_image(game->mlx, game->textures.walls);
				if (mlx_image_to_window(game->mlx, game->images.walls, i * SPRITE, n * SPRITE) < 0) // La función mlx_image_to_windows como la llamas en el if se ejecuta hay
					exit(1); //Al principio se pone exit(1) y libera toda la memoria, despues no se aconseja ponerlo.
			}
			i++;
		}
		n++;
	}
}