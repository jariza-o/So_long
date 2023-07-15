/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:12:25 by jariza-o          #+#    #+#             */
/*   Updated: 2023/07/15 19:48:24 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_check_walls(t_game *game)
{
	int	len;
	int	n;

	len = 0;
	n = 1;
	while (game->map[0][len])
	{
		if (game->map[0][len] != '1')
			return (0);
		len++;
	}
	while (game->map[n])
	{
		if (game->map[n][0] != '1' || game->map[n][len - 1] != '1')
			return (0);
		n++;
	}
	len = 0;
	while (game->map[n - 1][len])
	{
		if (game->map[n - 1][len] != '1')
			return (0);
		len++;
	}
	return (1);
}

// HACER CHECKER CAMINO CON FLOOD_FILL

// void	ft_flood_fill(t_game *game, int p_y, int p_x)
// {
// 	if (p_y < 0 || p_x < 0 || p_y > game->num_row
// 		|| p_x > game->num_col || game->map_copy[p_y][p_x] == '1'
// 			|| game->map_copy[p_y][p_x] == 'F')
// 		return ;
// 	if (game->map_copy[p_y][p_x] == 'E'
// 			|| game->map_copy[p_y][p_x] == 'C')
// 		game->map_copy[p_y][p_x] = '0';
// 	game->map_copy[p_y][p_x] = 'F';
// 	ft_flood_fill(game, p_y + 1, p_x);
// 	ft_flood_fill(game, p_y - 1, p_x);
// 	ft_flood_fill(game, p_y, p_x + 1);
// 	ft_flood_fill(game, p_y, p_x - 1);
// }


// int	ft_check_path(char **map)
// {
// 	t_point
// 	flood_fill();
// }