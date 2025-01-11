/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:23:57 by discallow         #+#    #+#             */
/*   Updated: 2025/01/10 10:33:03 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	destroy_map(t_game *game)
{
	mlx_destroy_image(game->connection, game->map2.img);
}

void	redraw_map(t_game *game)
{
	destroy_map(game);
	build_map(game);
}

void	check_door(t_game *game)
{
	float	next_x;
	float	next_y;

	next_x = game->player.x + game->player.dir_x / 9;
	next_y = game->player.y + game->player.dir_y / 9;
    if (game->map[(int)game->player.y][(int)next_x] == 'P' || game->map[(int)next_y][(int)game->player.x] == 'P')
	{
		game->map[(int)next_y][(int)next_x] = '0';
	}
	game->player.open_door = false;
	game->flag = true;
}


void move_forward(t_game *game)
{
	float	next_x;
	float	next_y;

	next_x = game->player.x + game->player.dir_x / 10;
	next_y = game->player.y + game->player.dir_y / 10;
    if (game->map[(int)game->player.y][(int)next_x] != '1' && game->map[(int)game->player.y][(int)next_x] != 'P')
		game->player.x = next_x;
	if (game->map[(int)next_y][(int)game->player.x] != '1' && game->map[(int)next_y][(int)game->player.x] != 'P')
		game->player.y = next_y;
	next_x = game->player.x + game->player.dir_x / 10;
	next_y = game->player.y + game->player.dir_y / 10;
	if (game->map[(int)game->player.y][(int)next_x] != '1' && game->map[(int)game->player.y][(int)next_x] != 'P')
		game->copy.x = game->player.x;
	if (game->map[(int)next_y][(int)game->player.x] != '1' && game->map[(int)next_y][(int)game->player.x] != 'P')
		game->copy.y = game->player.y;
	game->flag = true;
}

void move_backwards(t_game *game)
{
    float	next_x;
    float	next_y;

	next_x = game->player.x - game->player.dir_x / 10;
	next_y = game->player.y - game->player.dir_y / 10;
	if (game->map[(int)game->player.y][(int)next_x] != '1' && game->map[(int)game->player.y][(int)next_x] != 'P')
		game->player.x = next_x;
	if (game->map[(int)next_y][(int)game->player.x] != '1' && game->map[(int)next_y][(int)game->player.x] != 'P')
		game->player.y = next_y;
	next_x = game->player.x - game->player.dir_x / 10;
	next_y = game->player.y - game->player.dir_y / 10;
	if (game->map[(int)game->player.y][(int)next_x] != '1' && game->map[(int)game->player.y][(int)next_x] != 'P')
		game->copy.x = game->player.x;
	if (game->map[(int)next_y][(int)game->player.x] != '1' && game->map[(int)next_y][(int)game->player.x] != 'P')
		game->copy.y = game->player.y;
	game->flag = true;
}

void move_left(t_game *game)
{
	float	next_x;
	float	next_y;

	next_x = game->player.x + game->player.dir_y / 10;
	next_y = game->player.y - game->player.dir_x / 10;
	if (game->map[(int)game->player.y][(int)next_x] != '1' && game->map[(int)game->player.y][(int)next_x] != 'P')
		game->player.x = next_x;
	if (game->map[(int)next_y][(int)game->player.x] != '1' && game->map[(int)next_y][(int)game->player.x] != 'P')
        game->player.y = next_y;
	next_x = game->player.x + game->player.dir_y / 10;
	next_y = game->player.y - game->player.dir_x / 10;
	if (game->map[(int)game->player.y][(int)next_x] != '1' && game->map[(int)game->player.y][(int)next_x] != 'P')
		game->copy.x = game->player.x;
	if (game->map[(int)next_y][(int)game->player.x] != '1' && game->map[(int)next_y][(int)game->player.x] != 'P')
		game->copy.y = game->player.y;
	game->flag = true;
}

void move_right(t_game *game)
{
	float	next_x;
	float	next_y;

	next_x = game->player.x - game->player.dir_y / 10;
	next_y = game->player.y + game->player.dir_x / 10;
	if (game->map[(int)game->player.y][(int)next_x] != '1' && game->map[(int)game->player.y][(int)next_x] != 'P')
		game->player.x = next_x;
	if (game->map[(int)next_y][(int)game->player.x] != '1' && game->map[(int)next_y][(int)game->player.x] != 'P')
		game->player.y = next_y;
	next_x = game->player.x - game->player.dir_y / 10;
	next_y = game->player.y + game->player.dir_x / 10;
	if (game->map[(int)game->player.y][(int)next_x] != '1' && game->map[(int)game->player.y][(int)next_x] != 'P')
		game->copy.x = game->player.x;
	if (game->map[(int)next_y][(int)game->player.x] != '1' && game->map[(int)next_y][(int)game->player.x] != 'P')
		game->copy.y = game->player.y;
    game->flag = true;
}

void	rotate_right(t_game *game)
{
	game->player.angle += 0.1;
	if (game->player.angle > 2 * M_PI)
		game->player.angle -= 2 * M_PI;
	game->player.dir_x = cos(game->player.angle);
    game->player.dir_y = sin(game->player.angle);
	game->flag = true;
}

void	rotate_left(t_game *game)
{
	game->player.angle -= 0.1;
	if (game->player.angle < 0)
		game->player.angle += 2 * M_PI;
	game->player.dir_x = cos(game->player.angle);
	game->player.dir_y = sin(game->player.angle);
	game->flag = true;
}