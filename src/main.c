/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:12:51 by discallow         #+#    #+#             */
/*   Updated: 2024/12/02 23:48:23 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	init_struct(t_game *game)
{
	game->east.path = NULL;
	game->west.path = NULL;
	game->north.path = NULL;
	game->south.path = NULL;
	game->floor.path = NULL;
	game->ceiling.path = NULL;
	game->x = 0;
	game->y = 0;
	game->map = NULL;
	game->copy.exit = 0;
	game->player.num = 0;
	game->exit.num = 0;
	game->wall.num = 0;
	game->floor.num = 0;
	game->copy.elements_filled = false;
	game->ceiling.color = 0;
	game->floor.color = 0;
	game->ceiling.rgb = NULL;
	game->floor.rgb = NULL;
	game->copy.line_index = 0;
	game->copy.map_read = false;
	game->copy.start_line = 0;
	game->copy.last_line = 0;
	game->copy.map_joined = NULL;
	game->copy.player_num = 0;
}

void	display_big_cub3d(void)
{
	printf(CYAN BOLD"===============================================\n"RESET);
	printf("\n\n");
	printf(GREEN BOLD"   ██████╗║██╗   ██╗║██████╗ ██████╗   █████╗\n"RESET);
	printf(CYAN BOLD"  ██╔════╝║██║   ██║║██╔══██╗ ╚════██╗ ██╔══██╗\n"RESET);
	printf(YELLOW BOLD"  ██║     ║██║   ██║║██████╔╝  █████╔╝ ██║  ██║\n"RESET);
	printf(MAGENTA BOLD"  ██║     ║██║   ██║║██╔══██╗  ╚═══██╗ ██║"RESET);
	printf(MAGENTA BOLD"  ██║\n"RESET);
	printf(RED BOLD"  ╚██████ ║████████║║██████╔╝ ██████╔╝ ██████╔╝ \n"RESET);
	printf(BLUE BOLD"   ╚════╝ ╚════════╝╚══════╝  ╚═════╝  ╚═════╝\n"RESET);
	printf("\n");
}

void	display_controls(void)
{
	printf(CYAN BOLD"===============================================\n"RESET);
	printf(YELLOW BOLD"                        Controls\n"RESET);
	printf(MAGENTA"-----------------------------------------------\n"RESET);
	printf(GREEN BOLD"  Movement:\n"RESET);
	printf("    "CYAN"W"RESET" - Move forward\n");
	printf("    "CYAN"S"RESET" - Move backward\n");
	printf("    "CYAN"A"RESET" - Move left\n");
	printf("    "CYAN"D"RESET" - Move right\n\n");
	printf(GREEN BOLD"  Camera:\n"RESET);
	printf("    "CYAN"Left Arrow"RESET"  - Rotate view left\n");
	printf("    "CYAN"Right Arrow"RESET" - Rotate view right\n\n");
	printf(GREEN BOLD"  Actions:\n"RESET);
	printf("    "RED"ESC"RESET" - Exit the game\n\n");
	printf(MAGENTA"------------------------------------------------\n"RESET);
	printf(BLUE BOLD"       Enjoy exploring the 3D world of Cub3D!\n"RESET);
	printf(CYAN BOLD"=============================================="RESET);
	printf("\n\n");
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (printf(RED"Invalid number of arguments"RESET"\n"));
	display_big_cub3d();
	display_controls();
	init_struct(&game);
	//get_path(&game);
	check_map(&game, argv[1]);
	/*init_connection(&game);
	build_map(&game);
	mlx_hook(game.window, KeyPress, KeyPressMask, &key_pressed, &game);
	mlx_hook(game.window, DestroyNotify, NoEventMask, &window_closed, &game);
	mlx_loop(game.connection); */
	return (0);
}
