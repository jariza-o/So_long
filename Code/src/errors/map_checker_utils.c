/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:11:08 by jariza-o          #+#    #+#             */
/*   Updated: 2023/07/15 00:12:55 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_check_symbols(char **map)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (map[n])
	{
		while (map[n][i])
		{
			if (map[n][i] != '0' && map[n][i] != '1' && map[n][i] != 'C' &&
			map[n][i] != 'E' && map[n][i] != 'P')
				return (0);
			i++;
		}
		i = 0;
		n++;
	}
	return (1);
}

int	ft_check_exit(char **map)
{
	int	n;
	int	i;
	int	check_e;

	n = 0;
	i = 0;
	check_e = 0;
	while (map[n])
	{
		while (map[n][i])
		{
			if (map[n][i] == 'E' && check_e != 1)
				check_e = 1;
			else if (map[n][i] == 'E' && check_e == 1)
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

int	ft_check_obj(char **map)
{
	int	n;
	int	i;
	int	check_o;

	n = 0;
	i = 0;
	check_o = 0;
	while (map[n])
	{
		while (map[n][i])
		{
			if (map[n][i] == 'C')
				check_o = 1;
			i++;
		}
		i = 0;
		n++;
	}
	if (check_o == 0)
		return (0);
	return (1);
}

int	ft_check_init(char **map)
{
	int	n;
	int	i;
	int	check_i;

	n = 0;
	i = 0;
	check_i = 0;
	while (map[n])
	{
		while (map[n][i])
		{
			if (map[n][i] == 'P')
				check_i = 1;
			else if (map[n][i] == 'P' && check_i == 1)
				return (0);
			i++;
		}
		i = 0;
		n++;
	}
	if (check_i == 0)
		return (0);
	return (1);
}

int	ft_check_form(char **map)
{
	int	len;
	int	n;
	int	i;

	len = 0;
	n = 1;
	while (map[0][len])
		len++;
	if (map[n] == NULL)
		return (0);
	while (map[n])
	{
		i = 0;
		while (map[n][i])
			i++;
		if (len != i)
			return (0);
		n++;
	}
	if (len == n)
		return (0);
	return (1);
}
