/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:12:25 by jariza-o          #+#    #+#             */
/*   Updated: 2023/07/15 01:02:51 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_check_walls(char **map)
{
	int	len;
	int	n;

	len = 0;
	n = 1;
	while (map[0][len])
	{
		if (map[0][len] != '1')
		{
			ft_printf("%c MAL1 %d\n", map[0][len], len); //BORRAR
			return (0);
		}
		len++;
	}
	// VER PORQUE SI HAGO LEN-- ME DA SEGMENTATION FAULT Y ASI NO PUEDO VER LOS MUROS FINALES
	while (map[n])
	{
		if (map[n][0] != '1' || map[n][len] != '1')
		{
			ft_printf("%s MAL2 %d\n", map[n], len - 1); //BORRAR
			return (0);
		}
		n++;
	}
	len = 0;
	while (map[n - 1][len])
	{
		if (map[n][len] != '1')
		{
			ft_printf("MAL3\n"); //BORRAR
			return (0);
		}
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