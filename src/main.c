/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:12:51 by discallow         #+#    #+#             */
/*   Updated: 2025/01/05 16:03:04 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void init_struct(t_game *game)
{
	game->east.path = NULL;
	game->west.path = NULL;
	game->north.path = NULL;
	game->south.path = NULL;
	game->floor.path = NULL;
	game->ceiling.path = NULL;
	game->x = 0;
	game->y = 0;
	game->player.size = 0;
	game->map = NULL;
	game->copy.exit = 0;
	game->player.num = 0;
	game->player.dir = "N";//não inicializar, tem que se ler do mapa
	game->player.dir_x = 0.0;
	game->player.dir_y = 0.0;
	game->player.flag_pos = 0;
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
	game->copy.max_width = 0;
	game->copy.max_height = 0;
	game->x_len = 0;
	game->y_len = 0;
	game->player.angle = 0.0;
	game->player.move_a = false;
	game->player.move_d = false;
	game->player.move_s = false;
	game->player.move_w = false;
	game->player.rotate_left = false;
	game->player.rotate_right = false;
}

void display_big_cub3d(void)
{
	printf(CYAN BOLD "===============================================\n" RESET);
	printf("\n\n");
	printf(GREEN BOLD "   ██████╗║██╗   ██╗║██████╗ ██████╗   █████╗\n" RESET);
	printf(CYAN BOLD "  ██╔════╝║██║   ██║║██╔══██╗ ╚════██╗ ██╔══██╗\n" RESET);
	printf(YELLOW BOLD "  ██║     ║██║   ██║║██████╔╝  █████╔╝ ██║  ██║\n" RESET);
	printf(MAGENTA BOLD "  ██║     ║██║   ██║║██╔══██╗  ╚═══██╗ ██║" RESET);
	printf(MAGENTA BOLD "  ██║\n" RESET);
	printf(RED BOLD "  ╚██████ ║████████║║██████╔╝ ██████╔╝ ██████╔╝ \n" RESET);
	printf(BLUE BOLD "   ╚════╝ ╚════════╝╚══════╝  ╚═════╝  ╚═════╝\n" RESET);
	printf("\n");
}

void display_controls(void)
{
	printf(CYAN BOLD "===============================================\n" RESET);
	printf(YELLOW BOLD "                        Controls\n" RESET);
	printf(MAGENTA "-----------------------------------------------\n" RESET);
	printf(GREEN BOLD "  Movement:\n" RESET);
	printf("    " CYAN "W" RESET " - Move forward\n");
	printf("    " CYAN "S" RESET " - Move backward\n");
	printf("    " CYAN "A" RESET " - Move left\n");
	printf("    " CYAN "D" RESET " - Move right\n\n");
	printf(GREEN BOLD "  Camera:\n" RESET);
	printf("    " CYAN "Left Arrow" RESET "  - Rotate view left\n");
	printf("    " CYAN "Right Arrow" RESET " - Rotate view right\n\n");
	printf(GREEN BOLD "  Actions:\n" RESET);
	printf("    " RED "ESC" RESET " - Exit the game\n\n");
	printf(MAGENTA "------------------------------------------------\n" RESET);
	printf(BLUE BOLD "       Enjoy exploring the 3D world of Cub3D!\n" RESET);
	printf(CYAN BOLD "==============================================" RESET);
	printf("\n\n");
}

void init_connection(t_game *game)
{
	game->connection = mlx_init();
	if (!game->connection)
	{
		printf(RED "Error:Couldn't start connection." RESET "\n");
		free_everything(game);
		exit(1);
	}
	mlx_get_screen_size(game->connection, &game->x, &game->y);
	game->x = 800;
	game->y = 800;
	game->window = mlx_new_window(game->connection, (game->x),
								  (game->y), "CUB");
	if (!game->window)
	{
		mlx_destroy_display(game->connection);
		printf(RED "Error:Couldn't open window." RESET "\n");
		free(game->connection);
		free_everything(game);
		exit(1);
	}
}

int window_closed(t_game *game)
{
	write(1, "Window closed!\n", 15);
	mlx_destroy_window(game->connection, game->window);
	mlx_destroy_display(game->connection);
	free(game->connection);
	free_everything(game);
	exit(0);
}

void draw_square(t_position *data, int width, int height, int start_x, int start_y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			my_mlx_pixel_put(data, j + start_x, i + start_y, color);
			j++;
		}
		i++;
	}
}

int	key_released(int keysim, t_game *game)
{
	if (keysim == XK_w || keysim == XK_Up)
		game->player.move_w = false;
	if (keysim == XK_Right)
		game->player.rotate_right = false;
	if (keysim == XK_a)
		game->player.move_a = false;
	if (keysim == XK_s || keysim == XK_Down)
		game->player.move_s = false;
	if (keysim == XK_d)
		game->player.move_d = false;
	if (keysim == XK_Left)
		game->player.rotate_left = false;
	return (0);
}

int key_pressed(int keysim, t_game *game)
{
	if (keysim == XK_w || keysim == XK_Up)
		game->player.move_w = true;
	if (keysim == XK_Right)
		game->player.rotate_right = true;
	if (keysim == XK_a)
		game->player.move_a = true;
	if (keysim == XK_s || keysim == XK_Down)
		game->player.move_s = true;
	if (keysim == XK_d)
		game->player.move_d = true;
	if (keysim == XK_Left)
		game->player.rotate_left = true;
	if (keysim == XK_Escape)
	{
		write(1, "Couldn't you kill all the enemies? Are you afraid?\n", 51);
		destroy_map(game);
		mlx_destroy_window(game->connection, game->window);
		mlx_destroy_display(game->connection);
		free(game->connection);
		free_everything(game);
		exit(0);
	}
	return (0);
}

void draw_line(t_position *data, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx, sy;
	int err;

	// Determine step direction for x and y
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;

	if (y0 < y1)
		sy = 1;
	else
		sy = -1;

	err = dx - dy;

	while (1)
	{
		my_mlx_pixel_put(data, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break;

		int e2 = err * 2;

		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

/* void draw_player_direction(t_game *game, t_position *data)
{
	int line_length = 5; // Length of the line
	int start_x = (int)game->copy.x;
	int start_y = (int)game->copy.y;
	int end_x = start_x + game->delta_x * line_length;
	int end_y = start_y + game->delta_y * line_length;

	// Use the draw_line function to draw the line
	draw_line(data, start_x, start_y, end_x, end_y, 0x00FF0000); // Red color
} */

void	draw_minimap(t_game *game)
{
	static int	flag = 0;
	int			i;
	int			j;
	
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				draw_square(&game->map2, game->x_len - 1, game->y_len - 1, j * game->x_len, i * game->y_len, 0x0000FF00);
			else if (game->map[i][j] != '1')
				draw_square(&game->map2, game->x_len - 1, game->y_len - 1, j * game->x_len, i * game->y_len, 0x00808080);
			if (!flag && game->map[i][j] == 'N')
			{
				game->copy.x = j * game->x_len + game->x_len / 2;
				game->copy.y = i * game->y_len + game->y_len / 2;
				flag = 1;
			}
/* 			if (game->map[i][j] == 'P')
			{
				printf("x:%d, y:%d\n", j, i);
			} */
			j++;
		}
		i++;
	}
	draw_square(&game->map2, game->x_len / 4 - 1, game->y_len / 4 - 1, game->copy.x, game->copy.y, 0x000000FF);
}

void build_map(t_game *game)
{
	//printf("x:%d, y:%d\n", (int)game->player.x, (int)game->player.y);
	game->x_len = game->x / game->copy.max_width / SCALE;
	game->y_len = game->y / game->copy.max_height / SCALE;
	game->map2.img = mlx_new_image(game->connection, game->x, game->y);
	game->map2.addr = mlx_get_data_addr(game->map2.img, &game->map2.bits_per_pixel, &game->map2.line_len, &game->map2.endian);
	//ft_raycasting_untextured(game);
	ft_raycasting(game);
	draw_minimap(game);
	//draw_player_direction(game, &game->map2);
	mlx_put_image_to_window(game->connection, game->window, game->map2.img, 0, 0);
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
	else
	{
		build_map(game);
		return (0);
	}
	redraw_map(game);
	return (0);
}

int main(int argc, char **argv)
{
	t_game game;

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
	mlx_hook(game.window, DestroyNotify, NoEventMask, window_closed, &game);
	mlx_loop_hook(game.connection, display_map, &game);
	mlx_loop(game.connection);
	/* 	mlx_destroy_window(game.connection, game.window);
		mlx_destroy_display(game.connection);
		free(game.connection); */
	free_everything(&game);
	return (0);
}
