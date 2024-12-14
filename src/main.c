/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:12:51 by discallow         #+#    #+#             */
/*   Updated: 2024/12/14 16:24:25 by asofia-g         ###   ########.fr       */
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
	game->player.x = 20;
	game->player.y = 20;
	game->player.size = 0;
	game->map = NULL;
	game->copy.exit = 0;
	game->player.num = 0;
	game->player.dir = N;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
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

void	init_connection(t_game *game)
{
	game->connection = mlx_init();
	if (!game->connection)
	{
		printf(RED"Error:Couldn't start connection."RESET"\n");
		free_everything(game);
		exit (1);
	}
	mlx_get_screen_size(game->connection, &game->x, &game->y);
/*  	game->x = 800;
	game->y = 800; */
	game->window = mlx_new_window(game->connection, (game->x),
			(game->y), "CUB");
	if (!game->window)
	{
		mlx_destroy_display(game->connection);
		printf(RED"Error:Couldn't open window."RESET"\n");
		free(game->connection);
		free_everything(game);
		exit (1);
	}
}

int	window_closed(t_game *game)
{
	write(1, "Window closed!\n", 15);
	mlx_destroy_window(game->connection, game->window);
	mlx_destroy_display(game->connection);
	free(game->connection);
	free_everything(game);
	exit (0);
}

void	my_mlx_pixel_put(t_position *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_position *data, int width, int height, int start_x, int start_y, int color)
{
	int	i;
	int	j;

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

int	key_pressed(int keysim, t_game *game)
{
	if (keysim == XK_w || keysim == XK_Up)
		move_up(game);
	if (keysim == XK_d || keysim == XK_Right)
		move_right(game);
	if (keysim == XK_a || keysim == XK_Left)
		move_left(game);
	if (keysim == XK_s || keysim == XK_Down)
		move_down(game);
	if (keysim == XK_Escape)
	{
		write(1, "Couldn't you get all the pokeballs? Are you afraid?\n", 52);
		//destroy_map(game);
		mlx_destroy_window(game->connection, game->window);
		mlx_destroy_display(game->connection);
		free(game->connection);
		free_everything(game);
		exit (0);
	}
	return (0);
}

void	draw_line(t_position *data, int x0, int y0, int x1, int y1, int color)
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

void	draw_grid(t_position *data, int win_width, int win_height, int cell_size, int color)
{
	int x, y;

	// Draw vertical lines
	for (x = 0; x <= win_width; x += cell_size)
		draw_line(data, x, 0, x, win_height, color);

	// Draw horizontal lines
	for (y = 0; y <= win_height; y += cell_size)
		draw_line(data, 0, y, win_width, y, color);
}


void	build_map(t_game *game)
{
	// t_position	*img;
	static int	flag = 0;
	int			i;
	int			j;

	//printf("y:%d\n", game->y_len);
	//printf("game->x:%d, game->y:%d, game->copy.max_len:%d\n", game->x, game->y, game->copy.max_len);
	game->x_len = game->x / game->copy.max_width / 5;
	game->y_len = game->y / game->copy.max_height / 5;
	//printf("x:%d, y:%d\n", game->x_len, game->y_len);
	// img = &game->player;
	i = 0;
	j = 0;

 	game->map2.img = mlx_new_image(game->connection, game->x / 5, game->y / 5);
	game->map2.addr = mlx_get_data_addr(game->map2.img, &game->map2.bits_per_pixel, &game->map2.line_len, &game->map2.endian);
	//draw_grid(&game->map2, game->x / 5, game->y / 5, 20, 0x00FFFFFF); // White grid
/* 	game->floor.img = mlx_new_image(game->connection, game->x_len, game->y_len);
	game->floor.addr = mlx_get_data_addr(game->floor.img, &game->floor.bits_per_pixel, &game->floor.line_len, &game->floor.endian);
	draw_square(&game->floor, game->x_len, game->y_len, 0x00808080); */
/* 	if (!flag)
	{
		img->img = mlx_new_image(game->connection, game->x_len / 4, game->y_len / 4);
		img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_len, &img->endian);
		draw_square(img, game->x_len / 4, game->y_len / 4, 0x000000FF);		
	} */
/* 	game->wall.img = mlx_new_image(game->connection, game->x_len, game->y_len);
	game->wall.addr = mlx_get_data_addr(game->wall.img, &game->wall.bits_per_pixel, &game->wall.line_len, &game->wall.endian);
	draw_square(&game->wall, game->x_len, game->y_len, 0x0000FF00); */
	//printf("player x:%f, player y:%f\n", game->player.x, game->player.y);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				draw_square(&game->map2, game->x_len, game->y_len, j * game->x_len, i * game->y_len, 0x0000FF00);
				//mlx_put_image_to_window(game->connection, game->window, game->wall.img, j * game->x_len, i * game->y_len);
			else if (game->map[i][j] != '1')
				draw_square(&game->map2, game->x_len, game->y_len, j * game->x_len, i * game->y_len, 0x00808080);
				// mlx_put_image_to_window(game->connection, game->window, game->floor.img, j * game->x_len, i * game->y_len);
			if (!flag && game->map[i][j] == 'S')
			{
				game->player.x = j * game->x_len;
				game->player.y = i * game->y_len;
				draw_square(&game->map2, game->x_len / 4, game->y_len / 4, j * game->x_len, i * game->y_len, 0x000000FF);
				// mlx_put_image_to_window(game->connection, game->window, img->img, j * game->x_len, i * game->y_len);
				flag = 1;
			}
			j++;
		}
		i++;
	}
	if (flag)
		draw_square(&game->map2, game->x_len / 4, game->y_len / 4, game->player.x, game->player.y, 0x000000FF);
	mlx_put_image_to_window(game->connection, game->window, game->map2.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_game	game;


	if (argc != 2)
		return (printf(RED"Invalid number of arguments"RESET"\n"));
	display_big_cub3d();
	display_controls();
	init_struct(&game);
	check_map(&game, argv[1]);
	init_connection(&game);
	//put_player(&game);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	build_map(&game);
	mlx_hook(game.window, KeyPress, KeyPressMask, &key_pressed, &game);
	mlx_hook(game.window, DestroyNotify, NoEventMask, &window_closed, &game);
	mlx_loop(game.connection);
/* 	mlx_destroy_window(game.connection, game.window);
	mlx_destroy_display(game.connection);
	free(game.connection); */
	free_everything(&game);
	return (0);
}
