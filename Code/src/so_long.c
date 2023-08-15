/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:03:04 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/15 15:58:25 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_so_long(t_game *game)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	game->mlx = mlx_init(game->map_size.x_position * SPRITE,
			game->map_size.y_position * SPRITE, "so_long", false);
	if (!game->mlx)
	{
		ft_printf("Graphic error\n");
		exit(1);
	}
	ft_load_textures(game);
	ft_render_floor(game);
	ft_render_others(game);
	ft_render_obj(game);
	ft_render_person(game);
	mlx_key_hook(game->mlx, keys, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	ft_free_doublepointer(game->map);
	ft_free_doublepointer(game->map_copy);
	free(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "--help"))
			help();
		else
		{
			if (!ft_check_file(argv[1]))
				exit(1);
			game = (t_game *)malloc(sizeof(t_game));
			game->map = ft_read_map(argv[1]);
			game->map_copy = ft_read_map(argv[1]);
			if (map_checker(game))
				ft_so_long(game);
			else
				ft_free(game);
		}
	}
	else
	{
		ft_printf("Arguments are not correct. For help run: so_long --help\n");
		exit(1);
	}
	return (0);
}
