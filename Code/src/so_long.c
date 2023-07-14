/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:03:04 by jariza-o          #+#    #+#             */
/*   Updated: 2023/07/14 22:23:13 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;

	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "--help")) //porque si esta mal llamado el ft _strcmp sin el ! se te va al else de sin argumentos
		{
			//LLAMAR VARIABLE PARA HELP
		}
		else
		{
			if (!ft_check_file(argv[1])) //comprueba que el fichero es .ber y que existe
				return (0);
			map = ft_read_map(argv[1]);
			if (!map_checker(map)) //si todos los demás checkers son correctos
			{
				ft_printf("%s\n", map[0]);
			}
		}
	}
	else
	{
		ft_printf("Arguments are not correct. For help run: so_long --help");
		ft_printf(" For help run: so_long --help\n");
	}
	return (0);
}
