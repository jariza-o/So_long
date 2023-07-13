/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:19:52 by jariza-o          #+#    #+#             */
/*   Updated: 2023/07/12 19:43:00 by jariza-o         ###   ########.fr       */
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
	while (get_next_line(file_len) != NULL) //CREO QUE LA ULTIMA ES NULL PERO NO ESTOY SEGURO
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