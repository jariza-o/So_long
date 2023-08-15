/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:33:24 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/15 15:49:09 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	keys(mlx_key_data_t keydata, void *param)
{
	t_game		*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		w_key(game);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		s_key(game);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		a_key(game);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		d_key(game);
}

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
		if ((game->images.obj->instances[n].y == \
			game->images.person->instances->y)
			&& (game->images.obj->instances[n].x == \
			game->images.person->instances->x))
			game->images.obj->instances[n].enabled = 0;
		n++;
	}
}
