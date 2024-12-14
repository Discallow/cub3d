/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:23:57 by discallow         #+#    #+#             */
/*   Updated: 2024/12/13 15:18:47 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	get_pixel_color(t_game *game, int x, int y)
{
	// Get the map image pixel data
	char	*map_data;

	map_data = mlx_get_data_addr(game->wall.img, &game->wall.bits_per_pixel, &game->wall.line_len, &game->wall.endian);

	// Calculate the offset for the pixel at (x, y)
	int pixel_offset = (y * game->wall.line_len) + (x * (game->wall.bits_per_pixel / 8));

	// Extract the color (considering endianess)
	printf("pixel_offset:%x ,pixel_color: %#010x\n",(unsigned int)pixel_offset, *(unsigned int *)(map_data + pixel_offset));

	return (*(unsigned int *)(map_data + pixel_offset));
}

void	destroy_map(t_game *game)
{
	//mlx_destroy_image(game->connection, game->player.img);
	mlx_destroy_image(game->connection, game->wall.img);
	mlx_destroy_image(game->connection, game->floor.img);
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
	//mlx_put_image_to_window(game->connection, game->window, game->player.img, game->player.x, game->player.y);
	draw_square(&game->player, game->x_len / 4, game->y_len / 4, 0x00000000);
	mlx_put_image_to_window(game->connection, game->window, game->player.img, game->player.x, game->player.y);
	game->player.y += 10;
	redraw_map(game);
}

void	move_left(t_game *game)
{
	if (game->player.x - 20 <= 0)
		return ;
	draw_square(&game->player, game->x_len / 4, game->y_len / 4, 0x00000000);
	mlx_put_image_to_window(game->connection, game->window, game->player.img, game->player.x, game->player.y);
	game->player.x -= 10;
	redraw_map(game);
}

void	move_right(t_game *game)
{
	if (game->player.x + 40 >= game->x)
		return ;
	draw_square(&game->player, game->x_len / 4, game->y_len / 4, 0x00000000);
	mlx_put_image_to_window(game->connection, game->window, game->player.img, game->player.x, game->player.y);
	game->player.x += 10;
	redraw_map(game);
}

void	move_up(t_game *game)
{
	if (game->player.y - 20 <= 0)
		return ;
	draw_square(&game->player, game->x_len / 4, game->y_len / 4, 0x00000000);
	mlx_put_image_to_window(game->connection, game->window, game->player.img, game->player.x, game->player.y);
	game->player.y -= 10;
	redraw_map(game);
}
