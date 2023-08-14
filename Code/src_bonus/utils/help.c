/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:48:45 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/13 19:35:26 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	map_help(void)
{
	ft_printf("MAP ITEMS: \n");
	ft_printf("  - '1' for the walls. \n");
	ft_printf("  - 'P' for the player, only one. \n");
	ft_printf("  - 'E' for the exit, only one. \n");
	ft_printf("  - 'C' for the collectibles, at least one. \n");
	ft_printf("MAP FILE: \n");
	ft_printf("  - The format file is .ber \n");
	ft_printf("  - The game only work with a correct path. \n");
	ft_printf("  - The map must be rectangular. \n");
}

void	game_keys(void)
{
	ft_printf("MOVE KEYS: \n");
	ft_printf("  - 'W' for up. \n");
	ft_printf("  - 'S' for down. \n");
	ft_printf("  - 'A' for left. \n");
	ft_printf("  - 'D' for right. \n");
	ft_printf("EXIT KEYS: \n");
	ft_printf("  - Press 'ESC' or close the windows.. \n");
}

void	help(void)
{
	ft_printf("  █████████     ███████              █████");
	ft_printf("          ███████    ██████   █████   █████████ \n");
	ft_printf(" ███░░░░░███  ███░░░░░███           ░░███");
	ft_printf("         ███░░░░░███ ░░██████ ░░███   ███░░░░░███\n");
	ft_printf("░███    ░░░  ███     ░░███           ░███");
	ft_printf("        ███     ░░███ ░███░███ ░███  ███     ░░░ \n");
	ft_printf("░░█████████ ░███      ░███           ░███");
	ft_printf("       ░███      ░███ ░███░░███░███ ░███         \n");
	ft_printf(" ░░░░░░░░███░███      ░███           ░███");
	ft_printf("       ░███      ░███ ░███ ░░██████ ░███    █████\n");
	ft_printf(" ███    ░███░░███     ███            ░███");
	ft_printf("      █░░███     ███  ░███  ░░█████ ░░███  ░░███ \n");
	ft_printf("░░█████████  ░░░███████░   █████████ ████");
	ft_printf("███████ ░░░███████░   █████  ░░█████ ░░█████████ \n");
	ft_printf(" ░░░░░░░░░     ░░░░░░░    ░░░░░░░░░ ░░░░░");
	ft_printf("░░░░░░    ░░░░░░░    ░░░░░    ░░░░░   ░░░░░░░░░  \n\n");
	map_help();
	game_keys();
}
