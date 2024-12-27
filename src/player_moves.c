/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:23:57 by discallow         #+#    #+#             */
/*   Updated: 2024/12/27 21:23:54 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	destroy_map(t_game *game)
{
	mlx_destroy_image(game->connection, game->map2.img);
	//mlx_clear_window(game->connection, game->window);
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
	if (game->player.y + 40 >= game->y /* || get_pixel_color(game, game->player.x + 40, game->player.y + 40) == 0x0000FF00 */)
		return ;
	game->player.x -= game->delta_x;
	game->player.y -= game->delta_y;
	//mlx_put_image_to_window(game->connection, game->window, game->player.img, game->player.x, game->player.y);
	// draw_square(&game->player, game->x_len / 4, game->y_len / 4, 0x00000000);
	// mlx_put_image_to_window(game->connection, game->window, game->player.img, game->player.x, game->player.y);
	//game->player.y += 10;
	redraw_map(game);
}

void	move_left(t_game *game)
{
	if (game->player.x <= 0)
		return ;
	game->player.angle -= 0.1;
	if (game->player.angle < 0)
		game->player.angle += 2 * M_PI;
	game->player.dir_x = cos(game->player.angle);
	game->player.dir_y = sin(game->player.angle);
	game->delta_x = game->player.dir_x * 5;
	game->delta_y = game->player.dir_y * 5;
	// draw_square(&game->player, game->x_len / 4, game->y_len / 4, 0x00000000);
	// mlx_put_image_to_window(game->connection, game->window, game->player.img, game->player.x, game->player.y);
	//game->player.x -= 10;
	redraw_map(game);
}

void	move_right(t_game *game)
{
	if (game->player.x + 40 >= game->x)
		return ;
	game->player.angle += 0.1;
	if (game->player.angle > 2 * M_PI)
		game->player.angle -= 2 * M_PI;
	game->player.dir_x = cos(game->player.angle);
    game->player.dir_y = sin(game->player.angle);
	game->delta_x = game->player.dir_x * 5;
	game->delta_y = game->player.dir_y * 5;
	// draw_square(&game->player, game->x_len / 4, game->y_len / 4, 0x00000000);
	// mlx_put_image_to_window(game->connection, game->window, game->player.img, game->player.x, game->player.y);
	//game->player.x += 10;
	redraw_map(game);
}

void	move_up(t_game *game)
{
	if (game->player.y - 20 <= 0)
		return ;
	game->player.x += game->delta_x;
	game->player.y += game->delta_y;
	// draw_square(&game->player, game->x_len / 4, game->y_len / 4, 0x00000000);
	// mlx_put_image_to_window(game->connection, game->window, game->player.img, game->player.x, game->player.y);
	//game->player.y -= 10;
	redraw_map(game);
}
