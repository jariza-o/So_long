/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:57:07 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/11 10:57:07 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	w_key(t_game *game)
{
	if (game->map[game->person.y_position - 1][game->person.x_position] == '1')
		return ;
	if (game->map[game->person.y_position - 1][game->person.x_position] == 'E')
	{
		if (game->n_objs == game->c_objs)
		{
			game->images.person->instances[0].y -= 64;
			ft_printf("YOU WIN!!\n");
			mlx_close_window(game->mlx);
		}
		else
			printf("Hunts all ghosts.\n");
	}
	else
		game->images.person->instances[0].y -= 64;
	if (game->map[game->person.y_position - 1][game->person.x_position] == 'C')
	{
		game->c_objs += 1;
		ft_rm_obj(game);
	}
	game->map[game->person.y_position - 1][game->person.x_position] = 'P';
	game->map[game->person.y_position][game->person.x_position] = '0';
	game->person.y_position -= 1;
	ft_moves_counter(game);
}

void	s_key(t_game *game)
{
	if (game->map[game->person.y_position + 1][game->person.x_position] == '1')
		return ;
	if (game->map[game->person.y_position + 1][game->person.x_position] == 'E')
	{
		if (game->n_objs == game->c_objs)
		{
			game->images.person->instances[0].y += 64;
			ft_printf("YOU WIN!!\n");
			mlx_close_window(game->mlx);
		}
		else
			printf("Hunts all ghosts.\n");
	}
	else
		game->images.person->instances[0].y += 64;
	if (game->map[game->person.y_position + 1][game->person.x_position] == 'C')
	{
		game->c_objs += 1;
		ft_rm_obj(game);
	}
	game->map[game->person.y_position + 1][game->person.x_position] = 'P';
	game->map[game->person.y_position][game->person.x_position] = '0';
	game->person.y_position += 1;
	ft_moves_counter(game);
}

void	a_key(t_game *game)
{
	if (game->map[game->person.y_position][game->person.x_position - 1] == '1')
		return ;
	if (game->map[game->person.y_position][game->person.x_position - 1] == 'E')
	{
		if (game->n_objs == game->c_objs)
		{
			game->images.person->instances[0].x -= 64;
			ft_printf("YOU WIN!!\n");
			mlx_close_window(game->mlx);
		}
		else
			printf("Hunts all ghosts.\n");
	}
	else
		game->images.person->instances[0].x -= 64;
	if (game->map[game->person.y_position][game->person.x_position - 1] == 'C')
	{
		game->c_objs += 1;
		ft_rm_obj(game);
	}
	game->map[game->person.y_position][game->person.x_position - 1] = 'P';
	game->map[game->person.y_position][game->person.x_position] = '0';
	game->person.x_position -= 1;
	ft_moves_counter(game);
}

void	d_key(t_game *game)
{
	if (game->map[game->person.y_position][game->person.x_position + 1] == '1')
		return ;
	if (game->map[game->person.y_position][game->person.x_position + 1] == 'E')
	{
		if (game->n_objs == game->c_objs)
		{
			game->images.person->instances[0].x += 64;
			ft_printf("YOU WIN!!\n");
			mlx_close_window(game->mlx);
		}
		else
			printf("Hunts all ghosts.\n");
	}
	else
		game->images.person->instances[0].x += 64;
	if (game->map[game->person.y_position][game->person.x_position - 1] == 'C')
	{
		game->c_objs += 1;
		ft_rm_obj(game);
	}
	game->map[game->person.y_position][game->person.x_position + 1] = 'P';
	game->map[game->person.y_position][game->person.x_position] = '0';
	game->person.x_position += 1;
	ft_moves_counter(game);
}
