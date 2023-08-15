/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:26:52 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/15 15:40:56 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_load_textures(t_game *game)
{
	t_textures	*textures;

	textures = malloc(sizeof(t_textures));
	textures->floor = mlx_load_png("textures/floor.png");
	textures->walls = mlx_load_png("textures/wall.png");
	textures->obj = mlx_load_png("textures/object.png");
	textures->exit = mlx_load_png("textures/exit.png");
	textures->person = mlx_load_png("textures/player.png");
	if (!textures->person || !textures->floor || !textures->walls
		|| !textures->exit || !textures->obj)
		exit(1);
	game->images.floor = mlx_texture_to_image(game->mlx, textures->floor);
	game->images.walls = mlx_texture_to_image(game->mlx, textures->walls);
	game->images.obj = mlx_texture_to_image(game->mlx, textures->obj);
	game->images.exit = mlx_texture_to_image(game->mlx, textures->exit);
	game->images.person = mlx_texture_to_image(game->mlx, textures->person);
	mlx_delete_texture(textures->walls);
	mlx_delete_texture(textures->floor);
	mlx_delete_texture(textures->person);
	mlx_delete_texture(textures->obj);
	mlx_delete_texture(textures->exit);
	free(textures);
}

void	ft_render_floor(t_game *game)
{
	int	n;
	int	i;

	n = 0;
	while (game->map[n])
	{
		i = 0;
		while (game->map[n][i])
		{
			if (mlx_image_to_window(game->mlx, game->images.floor,
					i * SPRITE, n * SPRITE) < 0)
				exit(1);
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
	while (game->map[n])
	{
		i = 0;
		while (game->map[n][i])
		{
			if (game->map[n][i] == '1')
			{
				if (mlx_image_to_window(game->mlx, game->images.walls,
						i * SPRITE, n * SPRITE) < 0)
					exit(1);
			}
			else if (game->map[n][i] == 'E')
			{
				if (mlx_image_to_window(game->mlx, game->images.exit,
						i * SPRITE, n * SPRITE) < 0)
					exit(1);
			}
			i++;
		}
		n++;
	}
}

void	ft_render_obj(t_game *game)
{
	int	n;
	int	i;

	n = 0;
	while (game->map[n])
	{
		i = 0;
		while (game->map[n][i])
		{
			if (game->map[n][i] == 'C')
			{
				if (mlx_image_to_window(game->mlx, game->images.obj,
						i * SPRITE, n * SPRITE) < 0)
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
	while (game->map[n])
	{
		i = 0;
		while (game->map[n][i])
		{
			if (game->map[n][i] == 'P')
			{
				if (mlx_image_to_window(game->mlx, game->images.person,
						i * SPRITE, n * SPRITE) < 0)
					exit(1);
			}
			i++;
		}
		n++;
	}
}
