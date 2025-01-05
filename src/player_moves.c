/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:23:57 by discallow         #+#    #+#             */
/*   Updated: 2025/01/05 15:44:52 by discallow        ###   ########.fr       */
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

void	move_backwards(t_game *game)
{
/* 	if (game->player.y + 40 >= game->y)
		return ; */
	game->player.x -= game->player.dir_x / 10;
	game->player.y -= game->player.dir_y / 10;
	game->copy.x -= game->player.dir_x * game->x_len / 10;
	game->copy.y -= game->player.dir_y * game->y_len / 10;
	game->flag = true;
	//redraw_map(game);
}

void	move_left(t_game *game)
{
/* 	if (game->player.x <= 0)
		return ; */
	// game->player.x -= 0.1;
	// game->copy.x -= game->x_len / 10;
	game->player.x += game->player.dir_y / 10;
	game->player.y -= game->player.dir_x / 10;
	game->copy.x += game->player.dir_y * game->x_len / 10;
	game->copy.y -= game->player.dir_x * game->y_len / 10;
	game->flag = true;
	//redraw_map(game);
}

void	move_right(t_game *game)
{
/* 	if (game->player.x + 40 >= game->x)
		return ; */
	// game->player.x += 0.1;
	// game->copy.x += game->x_len / 10;
	game->player.x -= game->player.dir_y / 10;
	game->player.y += game->player.dir_x / 10;
	game->copy.x -= game->player.dir_y * game->x_len / 10;
	game->copy.y += game->player.dir_x * game->y_len / 10;
	game->flag = true;
	//redraw_map(game);
}

void	move_forward(t_game *game)
{
/* 	if (game->copy.y + game->delta_y <= 0 || game->copy.x + game->delta_x <= 0)
		return ; */
	// game->map[(int)game->copy.x - 1][(int)game->copy.y] = 'P';
	game->player.x += game->player.dir_x / 10;
	game->player.y += game->player.dir_y / 10;
	// game->map[(int)game->player.x][(int)game->player.y] = 'P';
	game->copy.x += game->player.dir_x * game->x_len / 10;
	game->copy.y += game->player.dir_y * game->y_len / 10;
	game->flag = true;
	//redraw_map(game);
}

void	rotate_right(t_game *game)
{
	game->player.angle += 0.1;
	if (game->player.angle > 2 * M_PI)
		game->player.angle -= 2 * M_PI;
	game->player.dir_x = cos(game->player.angle);
    game->player.dir_y = sin(game->player.angle);
	game->flag = true;
	//redraw_map(game);
}

void	rotate_left(t_game *game)
{
	game->player.angle -= 0.1;
	if (game->player.angle < 0)
		game->player.angle += 2 * M_PI;
	game->player.dir_x = cos(game->player.angle);
	game->player.dir_y = sin(game->player.angle);
	game->flag = true;
	//redraw_map(game);
}