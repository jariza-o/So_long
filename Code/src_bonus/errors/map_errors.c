/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:22:02 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/13 16:15:35 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	map_checker(t_game *game)
{
	if (!ft_check_symbols(game))
		return (ft_printf("Error: The map has incorrect symbols. \
		For help run: so_long --help\n"), 0);
	else if (!ft_check_exit(game))
		return (ft_printf("Error: The map has no or several exits. \
		For help run: so_long --help\n"), 0);
	else if (!ft_check_obj(game))
		return (ft_printf("Error: The map is missing objects. \
		For help run: so_long --help\n"), 0);
	else if (!ft_check_init(game))
		return (ft_printf("Error: The map entry is missing or has several entries. \
		For help run: so_long --help\n"), 0);
	else if (!ft_check_form(game))
		return (ft_printf("Error: The map shape is not correct. \
		For help run: so_long --help\n"), 0);
	else if (!ft_check_walls(game))
		return (ft_printf("Error: The map does not have the correct walls. \
		For help run: so_long --help\n"), 0);
	else if (!ft_check_path(game))
		return (ft_printf("Error: The map path isn't correct. \
		For help run: so_long --help\n"), 0);
	return (1);
}

int	ft_check_file(char *fd)
{
	int	n;
	int	file;

	n = 0;
	while (fd[n])
		n++;
	n -= 4;
	if (fd[n] != '.' || fd[n + 1] != 'b' || fd[n + 2] != 'e'
		|| fd[n + 3] != 'r')
	{
		ft_printf("Error: The file path or file format is incorrect.");
		ft_printf(" For help run: so_long --help\n");
		return (0);
	}
	file = open(fd, O_RDONLY);
	if (file == -1)
	{
		ft_printf("Error: File not found.");
		ft_printf(" For help run: so_long --help\n");
		close(file);
		return (0);
	}
	close (file);
	return (1);
}
