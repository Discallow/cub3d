/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:12:51 by discallow         #+#    #+#             */
/*   Updated: 2025/01/21 22:49:34 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_struct_2(t_game *game)
{
	game->player.move_a = false;
	game->player.move_d = false;
	game->player.move_s = false;
	game->player.move_w = false;
	game->door.open_door = false;
	game->door.close_door = true;
	game->player.flag = false;
	game->player.rotate_left = false;
	game->player.rotate_right = false;
	game->player.shoot = false;
	game->tex_buff = NULL;
	game->elapsed = 0;
	game->enemy_data.enemy_type = ENEMY;
}

void	init_struct(t_game *game)
{
	game->east.path = NULL;
	game->west.path = NULL;
	game->north.path = NULL;
	game->south.path = NULL;
	game->floor.path = NULL;
	game->ceiling.path = NULL;
	game->map = NULL;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->door.flag = false;
	game->copy.elements_filled = false;
	game->ceiling.color = 0;
	game->floor.color = 0;
	game->ceiling.rgb = NULL;
	game->floor.rgb = NULL;
	game->copy.line_index = 0;
	game->copy.map_read = false;
	game->copy.map_joined = NULL;
	game->copy.player_num = 0;
	game->copy.enemy_num = 0;
	game->copy.max_width = 0;
	game->copy.max_height = 0;
	game->player.angle = 0.0;
	init_struct_2(game);
}

/*to try untextured version, set BONUS do 0 and 
*change ft_raycasting(game) to ft_raycasting_untextured(game)*/
void	build_map(t_game *game)
{
	game->len = game->x / SCALE ;
	game->map2.img = mlx_new_image(game->connection, game->x, game->y);
	game->map2.addr = mlx_get_data_addr(game->map2.img,
			&game->map2.bits_per_pixel, &game->map2.line_len,
			&game->map2.endian);
	ft_raycasting(game);
	if (BONUS)
	{
		draw_minimap(game);
		draw_crosshair(game);
	}
	mlx_put_image_to_window(game->connection,
		game->window, game->map2.img, 0, 0);
}

int	display_map(t_game *game)
{
	if (game->player.move_w)
		move_forward(game);
	if (game->player.move_a)
		move_left(game);
	if (game->player.move_s)
		move_backwards(game);
	if (game->player.move_d)
		move_right(game);
	if (game->player.rotate_left)
		rotate_left(game);
	if (game->player.rotate_right)
		rotate_right(game);
	redraw_map(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (printf(RED "Introduce a mapfile as argument" RESET "\n"));
	display_big_cub3d();
	display_controls();
	init_struct(&game);
	check_map(&game, argv[1]);
	init_connection(&game);
	load_all_textures(&game);
	build_map(&game);
	mlx_hook(game.window, KeyPress, KeyPressMask, key_pressed, &game);
	mlx_hook(game.window, KeyRelease, KeyReleaseMask, key_released, &game);
	if (BONUS)
		check_mouse_hooks(&game);
	mlx_hook(game.window, DestroyNotify, NoEventMask, window_closed, &game);
	mlx_loop_hook(game.connection, display_map, &game);
	mlx_loop(game.connection);
	return (0);
}
