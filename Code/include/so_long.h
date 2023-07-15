/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:06:47 by jariza-o          #+#    #+#             */
/*   Updated: 2023/07/15 19:55:20 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h> //MALLOC
# include <fcntl.h> //OPEN

typedef struct s_position
{
	int	x_position;
	int	y_position;
}	t_position;

typedef struct s_game
{
	t_position	*map_size;
	char	**map;
	int		n_objs;
	t_position	*person;
}	t_game;

/* Utils */
/* Print Map*/
void	ft_print_map(char **map);

/* READ MAP */
/* Read the map file */
char	**ft_read_map(char *fd);
/* Delete the \n from the map */
char	**ft_remove_linesbreaks(char **map);

/* ERRORS */
/* Check the pat and if the file is empty*/
int		ft_check_file(char *fd);
/* Run all checkers */
int		map_checker(t_game *game);
/* Check the symbols */
int		ft_check_symbols(t_game *game);
/* Check the exit */
int		ft_check_exit(t_game *game);
/* Check the objects */
int		ft_check_obj(t_game *game);
/* Check the start position */
int		ft_check_init(t_game *game);
/* Check the form */
int		ft_check_form(t_game *game);
/* Check the walls */
int		ft_check_walls(t_game *game);

#endif