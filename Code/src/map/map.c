/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:19:52 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/15 15:59:11 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_reserve_read_memory(char *fd)
{
	char	*tmp;
	char	i;
	int		file;

	i = 0;
	file = open(fd, O_RDONLY);
	tmp = get_next_line(file);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(file);
		i++;
	}
	close (file);
	return (i);
}

char	**ft_read_map(char *fd)
{
	char	**map;
	int		i;
	int		file;

	i = ft_reserve_read_memory(fd);
	map = malloc(sizeof(char *) * (i + 1));
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
	map = ft_remove_linesbreaks(map);
	return (map);
}

char	**ft_remove_linesbreaks(char **map)
{
	int	n;
	int	i;

	n = 0;
	while (map[n])
	{
		i = 0;
		while (map[n][i] != '\n' && map[n][i] != '\0')
			i++;
		if (map[n][i] == '\n' && map[n][i + 1] == '\0')
			map[n][i] = '\0';
		n++;
	}
	n = 0;
	return (map);
}
