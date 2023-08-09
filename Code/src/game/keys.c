/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:33:24 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/09 19:35:57 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_moves_counter(t_game *game)
{
	game->moves += 1;
	ft_printf("Moves: %i\n", game->moves);
}

void	ft_rm_obj(t_game *game)
{
	int	n;

	n = 0;
	while (game->n_objs > n)
	{
		if ((game->images.obj->instances[n].y == game->images.person->instances->y)	&& (game->images.obj->instances[n].x == game->images.person->instances->x))
			game->images.obj->instances[n].enabled = 0;
		n++;
	}
}

void	keys(mlx_key_data_t keydata, void *param)
{
	t_game		*game;
	
	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
	{
		if (game->map[game->person.y_position - 1][game->person.x_position] == '0')
		{
			ft_print_map(game->map);
			game->map[game->person.y_position - 1][game->person.x_position] = 'P';
			game->map[game->person.y_position][game->person.x_position] = '0';
			game->person.y_position -= 1;
			game->images.person->instances[0].y -= 64;
			ft_print_map(game->map);
			ft_moves_counter(game);
		}
		else if (game->map[game->person.y_position - 1][game->person.x_position] == 'C')
		{
			
			ft_print_map(game->map);
			game->map[game->person.y_position - 1][game->person.x_position] = 'P';
			game->map[game->person.y_position][game->person.x_position] = '0';
			// mlx_image_to_window(game->mlx, game->images.floor, game->person.y_position - 1 * SPRITE, game->person.x_position * SPRITE);
			game->person.y_position -= 1;
			game->images.person->instances[0].y -= 64;
			game->c_objs += 1;
			ft_rm_obj(game);
			ft_print_map(game->map);
			ft_moves_counter(game);
		}
		else if (game->map[game->person.y_position - 1][game->person.x_position] == 'E')
		{
			ft_print_map(game->map);
			if (game->n_objs == game->c_objs)
			{	
				game->map[game->person.y_position][game->person.x_position] = '0';
				// mlx_image_to_window(game->mlx, game->images.floor, game->person.y_position - 1 * SPRITE, game->person.x_position * SPRITE);
				game->person.y_position -= 1;
				game->images.person->instances[0].y -= 64;
				ft_moves_counter(game);
				ft_printf("YOU WIN!!\n");
				mlx_close_window(game->mlx);
			}
			else
				printf("hunts all ghosts.\n");
		}
	}
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
	{
		if (game->map[game->person.y_position + 1][game->person.x_position] == '0')
		{
			ft_print_map(game->map);
			game->map[game->person.y_position + 1][game->person.x_position] = 'P';
			game->map[game->person.y_position][game->person.x_position] = '0';
			game->person.y_position += 1;
			game->images.person->instances[0].y += 64;
			ft_print_map(game->map);
			ft_moves_counter(game);
		}
		else if (game->map[game->person.y_position + 1][game->person.x_position] == 'C')
		{
			ft_print_map(game->map);
			game->map[game->person.y_position + 1][game->person.x_position] = 'P';
			game->map[game->person.y_position][game->person.x_position] = '0';
			// mlx_image_to_window(game->mlx, game->images.floor, game->person.y_position + 1 * SPRITE, game->person.x_position * SPRITE);
			game->person.y_position += 1;
			game->images.person->instances[0].y += 64;
			game->c_objs += 1;
			ft_rm_obj(game);
			ft_print_map(game->map);
			ft_moves_counter(game);
		}
		else if (game->map[game->person.y_position + 1][game->person.x_position] == 'E')
		{
			ft_print_map(game->map);
			if (game->n_objs == game->c_objs)
			{
				game->map[game->person.y_position][game->person.x_position] = '0';
				// mlx_image_to_window(game->mlx, game->images.floor, game->person.y_position - 1 * SPRITE, game->person.x_position * SPRITE);
				game->person.y_position += 1;
				game->images.person->instances[0].y += 64;
				ft_moves_counter(game);
				ft_printf("YOU WIN!!\n");
				mlx_close_window(game->mlx);
			}
			else
				printf("Hunts all ghosts!!\n");
		}
	}
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
	{
		if (game->map[game->person.y_position][game->person.x_position - 1] == '0')
		{
			ft_print_map(game->map);
			game->map[game->person.y_position][game->person.x_position - 1] = 'P';
			game->map[game->person.y_position][game->person.x_position] = '0';
			game->person.x_position -= 1;
			game->images.person->instances[0].x -= 64;
			ft_print_map(game->map);
			ft_moves_counter(game);
		}
		else if (game->map[game->person.y_position][game->person.x_position - 1] == 'C')
		{
			ft_print_map(game->map);
			game->map[game->person.y_position][game->person.x_position - 1] = 'P';
			game->map[game->person.y_position][game->person.x_position] = '0';
			// mlx_image_to_window(game->mlx, game->images.floor, game->person.y_position - 1 * SPRITE, game->person.x_position * SPRITE);
			game->person.x_position -= 1;
			game->images.person->instances[0].x -= 64;
			game->c_objs += 1;
			ft_rm_obj(game);
			ft_print_map(game->map);
			ft_moves_counter(game);
		}
		else if (game->map[game->person.y_position][game->person.x_position - 1] == 'E')
		{
			ft_print_map(game->map);
			if (game->n_objs == game->c_objs)
			{
				game->map[game->person.y_position][game->person.x_position] = '0';
				// mlx_image_to_window(game->mlx, game->images.floor, game->person.y_position - 1 * SPRITE, game->person.x_position * SPRITE);
				game->person.x_position -= 1;
				game->images.person->instances[0].x -= 64;
				ft_moves_counter(game);
				ft_printf("YOU WIN!!\n");
				mlx_close_window(game->mlx);
			}
			else
				printf("Hunts all ghosts!!\n");
		}
	}
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
	{
		if (game->map[game->person.y_position][game->person.x_position + 1] == '0')
		{
			ft_print_map(game->map);
			game->map[game->person.y_position][game->person.x_position + 1] = 'P';
			game->map[game->person.y_position][game->person.x_position] = '0';
			game->person.x_position += 1;
			game->images.person->instances[0].x += 64;
			ft_print_map(game->map);
			ft_moves_counter(game);
		}
		else if (game->map[game->person.y_position][game->person.x_position + 1] == 'C')
		{
			ft_print_map(game->map);
			game->map[game->person.y_position][game->person.x_position + 1] = 'P';
			game->map[game->person.y_position][game->person.x_position] = '0';
			// mlx_image_to_window(game->mlx, game->images.floor, game->person.y_position - 1 * SPRITE, game->person.x_position * SPRITE);
			game->person.x_position += 1;
			game->images.person->instances[0].x += 64;
			game->c_objs += 1;
			ft_rm_obj(game);
			ft_print_map(game->map);
			ft_moves_counter(game);
		}
		else if (game->map[game->person.y_position][game->person.x_position + 1] == 'E')
		{
			ft_print_map(game->map);
			if (game->n_objs == game->c_objs)
			{
				game->map[game->person.y_position][game->person.x_position] = '0';
				// mlx_image_to_window(game->mlx, game->images.floor, game->person.y_position - 1 * SPRITE, game->person.x_position * SPRITE);
				game->person.x_position += 1;
				game->images.person->instances[0].x += 64;
				ft_moves_counter(game);
				ft_printf("YOU WIN!!\n");
				mlx_close_window(game->mlx);
			}
			else
				printf("Hunts all ghosts!!\n");
		}
	}
}
