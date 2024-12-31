/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:23:57 by discallow         #+#    #+#             */
/*   Updated: 2024/12/31 10:06:39 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	destroy_map(t_game *game)
{
	mlx_destroy_image(game->connection, game->map2.img);
	//mlx_destroy_image(game->connection, game->player.img);
	// mlx_destroy_image(game->connection, game->wall.img);
	// mlx_destroy_image(game->connection, game->floor.img);
}

void	redraw_map(t_game *game)
{
	destroy_map(game);
	build_map(game);
}

void	move_down(t_game *game)
{
	//printf("game->player.x:%f, game->x:%d\n", game->player.x, game->x);
/* 	if (game->player.y + 40 >= game->y)
		return ; */
	game->player.x -= game->delta_x;
	game->player.y -= game->delta_y;
	game->copy.x -= game->delta_x;
	game->copy.y -= game->delta_y;
	redraw_map(game);
}

void	move_left(t_game *game)
{
/* 	if (game->player.x <= 0)
		return ; */
	game->player.x -= 0.1;
	game->copy.x -= game->x_len / 10;
	redraw_map(game);
}

void	move_right(t_game *game)
{
/* 	if (game->player.x + 40 >= game->x)
		return ; */
	game->player.x += 0.1;
	game->copy.x += game->x_len / 10;
	redraw_map(game);
}

void	move_up(t_game *game)
{
	//printf("x:%.1f, y:%.1f\n", game->player.x + game->delta_x, game->player.y + game->delta_y);
	if (game->copy.y + game->delta_y <= 0 || game->copy.x + game->delta_x <= 0)
		return ;
	// game->map[(int)game->copy.x - 1][(int)game->copy.y] = 'P';
	if (game->delta_x == cos(0))
	{
		game->delta_x += 0.1;
		game->delta_y += 0.1;
	}
	game->player.x += game->delta_x;
	game->player.y += game->delta_y;
	game->copy.x += game->delta_x;
	game->copy.y += game->delta_y;
	redraw_map(game);
}

void	rotate_right(t_game *game)
{
	game->player.angle += 0.1;
	if (game->player.angle > 2 * M_PI)
		game->player.angle -= 2 * M_PI;
	game->player.dir_x = cos(game->player.angle);
    game->player.dir_y = sin(game->player.angle);
	game->delta_x = game->player.dir_x;
	game->delta_y = game->player.dir_y;
	redraw_map(game);
}

void	rotate_left(t_game *game)
{
	game->player.angle -= 0.1;
	if (game->player.angle < 0)
		game->player.angle += 2 * M_PI;
	game->player.dir_x = cos(game->player.angle);
	game->player.dir_y = sin(game->player.angle);
	game->delta_x = game->player.dir_x;
	game->delta_y = game->player.dir_y;
	redraw_map(game);
}