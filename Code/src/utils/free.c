/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:48:46 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/15 15:47:00 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_free(t_game *game)
{
	ft_free_doublepointer(game->map);
	ft_free_doublepointer(game->map_copy);
	free(game);
	exit(1);
}
