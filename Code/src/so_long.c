/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:03:04 by jariza-o          #+#    #+#             */
/*   Updated: 2023/07/12 19:41:16 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;

	if (argc == 2)
	{
		if (argv[1] == "--help")
		{
			//LLAMAR VARIABLE PARA HELP
			return (0);
		}
		else
		{
			if (!ft_check_file(argv[1])) //comprueba que el fichero es .ber y que existe
				return (0);
			map = ft_read_map(argv[1]);
			if (!map_checker(map)) //si todos los demás checkers son correctos
			{
				//SO_LONG
			}
		}
	}
	else
	{
		ft_printf("Arguments are not correct. For help run: so_long --help\n");
		ft_printf(" For help run: so_long --help\n");
	}
	return (0);
}
