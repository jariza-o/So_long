/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:11:08 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/13 17:22:09 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_check_symbols(t_game *game)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (game->map[n])
	{
		while (game->map[n][i])
		{
			if (game->map[n][i] != '0' && game->map[n][i] != '1' && game->map[n][i] != 'C' &&
			game->map[n][i] != 'E' && game->map[n][i] != 'P')
				return (0);
			i++;
		}
		i = 0;
		n++;
	}
	return (1);
}

int	ft_check_exit(t_game *game)
{
	int	n;
	int	i;
	int	check_e;

	n = 0;
	i = 0;
	check_e = 0;
	while (game->map[n])
	{
		while (game->map[n][i])
		{
			if (game->map[n][i] == 'E' && check_e != 1)
				check_e = 1;
			else if (game->map[n][i] == 'E' && check_e == 1)
				return (0);
			i++;
		}
		i = 0;
		n++;
	}
	if (check_e == 0)
		return (0);
	return (1);
}

int	ft_check_obj(t_game *game)
{
	int	n;
	int	i;

	game->n_objs = 0;
	game->c_objs = 0;
	n = 0;
	i = 0;
	while (game->map[n])
	{
		while (game->map[n][i])
		{
			if (game->map[n][i] == 'C')
				game->n_objs += 1;
			i++;
		}
		i = 0;
		n++;
	}
	if (game->n_objs == 0)
		return (0);
	return (1);
}

int	ft_check_init(t_game *game)
{
	int	n;
	int	i;
	int	check_i;

	n = 0;
	while (game->map[n])
	{
		i = 0;
		while (game->map[n][i])
		{
			if (game->map[n][i] == 'P' && check_i == 1)
				return (0);
			else if (game->map[n][i] == 'P')
			{
				game->person.y_position = n;
				game->person.x_position = i;
				check_i = 1;
			}
			i++;
		}
		n++;
	}
	if (check_i == 0)
		return (0);
	return (1);
}

int	ft_check_form(t_game *game)
{
	int	len;
	int	n;
	int	i;

	if (game->map[0] == NULL || game->map[1] == NULL || game->map[2] == NULL)
		return (0);
	len = 0;
	n = 1;
	while (game->map[0][len])
		len++;
	game->map_size.x_position = len;
	while (game->map[n])
	{
		i = 0;
		while (game->map[n][i])
			i++;
		if (len != i)
			return (0);
		n++;
	}
	game->map_size.y_position = n;
	if (game->map_size.x_position == game->map_size.y_position)
		return (0);
	return (1);
}
