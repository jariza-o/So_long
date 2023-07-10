/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:22:02 by jariza-o          #+#    #+#             */
/*   Updated: 2023/07/10 19:38:29 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_read_map(char *fd)
{
	char	**map;
	int		i;
	int		file;
	int		file_len;

	i = 0;
	file_len = open(fd, O_RDONLY);
	while (get_next_line(file_len) != NULL)
		i++;
	close (file_len);
	map = malloc(sizeof(char *) * (i + 1)); //SE SUMA +1??
	if (map == NULL)
		return (NULL);
	i = 0;
	file = open(fd, O_RDONLY);
	map[i] = get_next_line(file);
	while (map[i] != NULL)
	{
		i++;
		map[i] = get_next_line(file);
	}
	close (file);
	return (map);
}

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
			if (map[n][i] != '0' || map[n][i] != '1' || map[n][i] != 'C' ||
			map[n][i] != 'E' || map[n][i] != 'P' || map[n][i] != '\n')
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
	check_e = 0;
	while (map[n])
	{
		while (map[n][i])
		{
			if (map[n][i] == 'C')
				check_e = 1;
			i++;
		}
		i = 0;
		n++;
	}
	if (check_e == 0)
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
