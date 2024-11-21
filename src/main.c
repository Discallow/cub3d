/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:12:51 by discallow         #+#    #+#             */
/*   Updated: 2024/11/21 19:28:28 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	game->player.x = 0;
	game->player.y = 0;
	game->exit.num = 0;
	game->wall.num = 0;
	game->floor.num = 0;
	game->enemy.x = 0;
	game->enemy.y = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (printf(RED"Invalid number of arguments"RESET"\n"));
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
