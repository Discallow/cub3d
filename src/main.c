/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:12:51 by discallow         #+#    #+#             */
/*   Updated: 2025/01/10 10:49:24 by discallow        ###   ########.fr       */
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
	game->player.dir_x = 0.0;
	game->player.dir_y = 0.0;
	game->player.flag_pos = 0;
	game->door.path = NULL;
	game->door.flag = false;
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
	game->player.angle = 0.0;
	game->player.move_a = false;
	game->player.move_d = false;
	game->player.move_s = false;
	game->player.move_w = false;
	game->player.open_door = false;
	game->player.rotate_left = false;
	game->player.rotate_right = false;
	game->player.shoot = false;
	game->flag = false;
	game->tex_buff = NULL;
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
/* 	game->x = 800;
	game->y = 800; */
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
	if (keysim == XK_e)
		game->player.open_door = true;
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

static int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

static int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

 void draw_minimap(t_game *game)
{
    int start_i, end_i, start_j, end_j;
    int i, j, k, l;
    
    int px = (int)game->player.x;
    int py = (int)game->player.y;

    start_i = max(0, py - 3);
    end_i = min(game->copy.max_height, py + 3);
    start_j = max(0, px - 3);
    end_j = min(game->copy.max_width, px + 3);
    while (end_i - start_i < 6) 
	{
        if (start_i > 0) 
			start_i--;
        else if (end_i < game->copy.max_height) 
			end_i++;
        else 
			break;
    }
    while (end_j - start_j < 6) 
	{
        if (start_j > 0) 
			start_j--;
        else if (end_j < game->copy.max_width) 
			end_j++;
        else 
			break;
    }
    i = 0;
	l = start_i;
    while (start_i < end_i)
    {
		k = 0;
        j = start_j;
        while (j < end_j)
        {
            if (game->map[start_i][j] == '1')
                draw_square(&game->map2, game->len, game->len, k * game->len, i * game->len, 0x0000FF00);
            else if (game->map[start_i][j] == '0' || game->map[start_i][j] == 'N' || game->map[start_i][j] == 'P'
				|| game->map[start_i][j] == 'E' || game->map[start_i][j] == 'W' || game->map[start_i][j] == 'S')
                draw_square(&game->map2, game->len, game->len, k * game->len, i * game->len, 0x00808080);
			else if (game->map[start_i][j] == 'X')
			{
				draw_square(&game->map2, game->len, game->len, k * game->len, i * game->len, 0x00808080);
				draw_square(&game->map2, game->len / 5, game->len / 5, k * game->len, i * game->len, 0x00FF0000);
			}
            j++;
			k++;
        }
		start_i++;
        i++;
    }
	
    float player_x_on_map = (game->copy.x - (float)start_j) * game->len;
    float player_y_on_map = (game->copy.y - (float)l) * game->len;
    draw_square(&game->map2, game->len / 5, game->len / 5,
                (int)player_x_on_map, (int)player_y_on_map, 0x000000FF);
}

void draw_filled_rect(t_game *game, int x, int y, int width, int height, int color)
{
    int i, j;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            my_mlx_pixel_put(&game->map2, x + j, y + i, color);
        }
    }
}

void draw_crosshair(t_game *game)
{
    int line_length = (int)(min(game->x, game->y) * 0.01f); // Crosshair line length (1% of smaller screen dimension)
    int thickness = max(1, line_length / 4);               // Crosshair line thickness (minimum 1 pixel)

    // Draw vertical line (centered at middle_x, middle_y)
    int x_start = game->x / 2 - (thickness / 2);
    int y_start_vertical = game->y / 2 - (line_length / 2);
    int y_end_vertical = game->y / 2 + (line_length / 2);

    draw_filled_rect(game, x_start, y_start_vertical, thickness, y_end_vertical - y_start_vertical, 0x0000FFFF); // White color

    // Draw horizontal line (centered at middle_x, middle_y)
    int y_start = game->y / 2 - (thickness / 2);
    int x_start_horizontal = game->x / 2 - (line_length / 2);
    int x_end_horizontal = game->x / 2 + (line_length / 2);

    draw_filled_rect(game, x_start_horizontal, y_start, x_end_horizontal - x_start_horizontal, thickness, 0x0000FFFF); // White color
}

void build_map(t_game *game)
{
	game->len = game->x / SCALE ;
	game->map2.img = mlx_new_image(game->connection, game->x, game->y);
	game->map2.addr = mlx_get_data_addr(game->map2.img, &game->map2.bits_per_pixel, &game->map2.line_len, &game->map2.endian);
	//ft_raycasting_untextured(game);
	ft_raycasting(game);
	if (BONUS)
	{
		draw_minimap(game);
		draw_crosshair(game);
	}
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
	if (game->player.open_door)
		check_door(game);
	if (game->player.shoot || !game->player.shoot)
		game->flag = true;
	if (game->flag)
	{
		game->flag = false;
		redraw_map(game);
	}	
	return (0);
}

int	mouse_pressed(int button, int x, int y, t_game *game)
{
	if (button == Button1)
		game->player.shoot = true;
	(void)x;
	(void)y;
	return (0);
}

int	mouse_released(int button, int x, int y, t_game *game)
{
	if (button == Button1)
		game->player.shoot = false;
	(void)x;
	(void)y;
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
	mlx_hook(game.window, ButtonPress, ButtonPressMask, mouse_pressed, &game);
	mlx_hook(game.window, ButtonRelease, ButtonReleaseMask, mouse_released, &game);
	mlx_hook(game.window, DestroyNotify, NoEventMask, window_closed, &game);
	mlx_loop_hook(game.connection, display_map, &game);
	mlx_loop(game.connection);
	/* 	mlx_destroy_window(game.connection, game.window);
		mlx_destroy_display(game.connection);
		free(game.connection); */
	free_everything(&game);
	return (0);
}
