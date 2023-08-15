/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:06:47 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/15 15:45:12 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h> //MALLOC
# include <fcntl.h> //OPEN
# define SPRITE 64

typedef struct s_position
{
	int	x_position;
	int	y_position;
}	t_position;

typedef struct s_textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*walls;
	mlx_texture_t	*person;
	mlx_texture_t	*obj;
	mlx_texture_t	*enemy;
	mlx_texture_t	*exit;
}	t_textures;

typedef struct s_images
{
	mlx_image_t	*floor;
	mlx_image_t	*walls;
	mlx_image_t	*person;
	mlx_image_t	*obj;
	mlx_image_t	*enemy;
	mlx_image_t	*exit;
}	t_images;

typedef struct s_game
{
	mlx_t		*mlx;
	t_position	map_size;
	char		**map;
	char		**map_copy;
	int			n_objs;
	int			c_objs;
	t_position	person;
	t_images	images;
	int			moves;
}	t_game;

/* Utils */
/* Print Map*/
void	ft_print_map(char **map);

/* HELP */
void	help(void);

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
/* Check the path */
void	ft_flood_fill(t_game *game, int p_y, int p_x);
int		ft_check_path(t_game *game);

/* GAME FUCTIONS */
void	ft_so_long(t_game *game);

/* MAP GAME */
/* Load MAP textures */
void	ft_load_textures(t_game *game);
void	ft_render_floor(t_game *game);
void	ft_render_others(t_game *game);
void	ft_render_obj(t_game *game);
void	ft_render_person(t_game *game);

/* Keys */
void	keys(mlx_key_data_t keydata, void *param);
void	w_key(t_game *game);
void	s_key(t_game *game);
void	a_key(t_game *game);
void	d_key(t_game *game);

/* Game Utils */
void	ft_moves_counter(t_game *game);
void	ft_rm_obj(t_game *game);

/* Free */
void	ft_free(t_game *game);

#endif