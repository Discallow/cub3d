/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:23:57 by discallow         #+#    #+#             */
/*   Updated: 2025/01/21 21:28:06 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_enemy(t_game *game, int x, int y)
{
	if (game->map[y][(int)game->player.x] == 'X'
		|| game->map[(int)game->player.y][x] == 'X')
	{
		printf(RED"You died!"RESET"\n");
		mlx_destroy_image(game->connection, game->map2.img);
		free_everything(game);
		mlx_destroy_window(game->connection, game->window);
		mlx_destroy_display(game->connection);
		free(game->connection);
		exit (0);
	}
}

void	move_forward(t_game *game)
{
	float	next_x;
	float	next_y;

	next_x = game->player.x + game->player.dir_x / 10;
	next_y = game->player.y + game->player.dir_y / 10;
	check_enemy(game, (int)next_x, (int)next_y);
	if (game->map[(int)game->player.y][(int)next_x] != '1'
		&& check_door(game, next_x, next_y, 2) == 1)
		game->player.x = next_x;
	if (game->map[(int)next_y][(int)game->player.x] != '1'
		&& check_door(game, next_x, next_y, 0) == 2)
		game->player.y = next_y;
	next_x = (game->player.x + game->player.dir_x);
	next_y = (game->player.y + game->player.dir_y);
	if (game->player.dir_x == 0)
		next_x = game->player.x + 1;
	if (game->player.dir_y == 0)
		next_y = game->player.y + 1;
}

void	move_backwards(t_game *game)
{
	float	next_x;
	float	next_y;

	next_x = game->player.x - game->player.dir_x / 10;
	next_y = game->player.y - game->player.dir_y / 10;
	check_enemy(game, (int)next_x, (int)next_y);
	if (game->map[(int)game->player.y][(int)next_x] != '1'
		&& check_door(game, next_x, next_y, 2) == 1)
		game->player.x = next_x;
	if (game->map[(int)next_y][(int)game->player.x] != '1'
		&& check_door(game, next_x, next_y, 0) == 2)
		game->player.y = next_y;
	next_x = (game->player.x - game->player.dir_x);
	next_y = (game->player.y - game->player.dir_y);
	if (game->player.dir_x == 0)
		next_x = game->player.x - 1;
	if (game->player.dir_y == 0)
		next_y = game->player.y - 1;
}

void	move_left(t_game *game)
{
	float	next_x;
	float	next_y;

	next_x = game->player.x + game->player.dir_y / 10;
	next_y = game->player.y - game->player.dir_x / 10;
	check_enemy(game, (int)next_x, (int)next_y);
	if (game->map[(int)game->player.y][(int)next_x] != '1'
		&& check_door(game, next_x, next_y, 1) == 1)
		game->player.x = next_x;
	if (game->map[(int)next_y][(int)game->player.x] != '1'
		&& check_door(game, next_x, next_y, 0) == 2)
		game->player.y = next_y;
	next_x = (game->player.x + game->player.dir_x);
	next_y = (game->player.y - game->player.dir_y);
	if (game->player.dir_x == 0)
		next_x = game->player.x + 1;
	if (game->player.dir_y == 0)
		next_y = game->player.y - 1;
}

void	move_right(t_game *game)
{
	float	next_x;
	float	next_y;

	next_x = game->player.x - game->player.dir_y / 10;
	next_y = game->player.y + game->player.dir_x / 10;
	check_enemy(game, (int)next_x, (int)next_y);
	if (game->map[(int)game->player.y][(int)next_x] != '1'
		&& check_door(game, next_x, next_y, 1) == 1)
		game->player.x = next_x;
	if (game->map[(int)next_y][(int)game->player.x] != '1'
		&& check_door(game, next_x, next_y, 0) == 2)
		game->player.y = next_y;
	next_x = (game->player.x - game->player.dir_x);
	next_y = (game->player.y + game->player.dir_y);
	if (game->player.dir_x == 0)
		next_x = game->player.x - 1;
	if (game->player.dir_y == 0)
		next_y = game->player.y + 1;
}
