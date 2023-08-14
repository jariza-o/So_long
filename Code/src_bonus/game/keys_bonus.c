/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:57:07 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/14 23:52:51 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	w_key_bonus(t_game *game)
{
	if (game->map[game->person.y_position - 1][game->person.x_position] == 'A')
	{
		game->images.person->instances[0].y -= 64;
		ft_moves_counter(game);
		ft_printf("YOU LOSE!!\n");
		mlx_close_window(game->mlx);
	}
	else
		w_key(game);
}

void	s_key_bonus(t_game *game)
{
	if (game->map[game->person.y_position + 1][game->person.x_position] == 'A')
	{
		game->images.person->instances[0].y += 64;
		ft_moves_counter(game);
		ft_printf("YOU LOSE!!\n");
		mlx_close_window(game->mlx);
	}
	else
		s_key(game);
}

void	a_key_bonus(t_game *game)
{
	if (game->map[game->person.y_position][game->person.x_position - 1] == 'A')
	{
		game->images.person->instances[0].x -= 64;
		ft_moves_counter(game);
		ft_printf("YOU LOSE!!\n");
		mlx_close_window(game->mlx);
	}
	else
		a_key(game);
}

void	d_key_bonus(t_game *game)
{
	if (game->map[game->person.y_position][game->person.x_position + 1] == 'A')
	{
		game->images.person->instances[0].x += 64;
		ft_moves_counter(game);
		ft_counter_bonus(game);
		ft_printf("YOU LOSE!!\n");
		mlx_close_window(game->mlx);
	}
	else
		d_key(game);
}
