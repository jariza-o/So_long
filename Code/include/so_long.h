/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:06:47 by jariza-o          #+#    #+#             */
/*   Updated: 2023/07/13 16:13:01 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <stdlib.h> //MALLOC
# include <fcntl.h> //OPEN

/* READ MAP */
char	**ft_read_map(char *fd);

/* ERRORS */
/* Check the pat and if the file is empty*/
int		ft_check_file(char *fd);
/* Run all checkers */
int		map_checker(char **map);
/* Check the symbols */
int		ft_check_symbols(char **map);
/* Check the exit */
int		ft_check_exit(char **map);
/* Check the objects */
int		ft_check_obj(char **map);
/* Check the start position */
int		ft_check_init(char **map);
/* Check the form */
int		ft_check_form(char **map);
/* Check the walls */
int		ft_check_walls(char **map);

#endif