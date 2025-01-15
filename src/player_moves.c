/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:23:57 by discallow         #+#    #+#             */
/*   Updated: 2025/01/15 19:47:15 by discallow        ###   ########.fr       */
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
long	gettime(void)
{
	struct timeval	start;
	long			elapsed;

	if (gettimeofday(&start, NULL))
	{
		printf(YELLOW"gettimeofday function failed."RESET"\n");
		exit (1);
	}
	elapsed = (start.tv_sec * MILLISECOND) + (start.tv_usec / MILLISECOND);
	return (elapsed);
}

/* void	change_door_texture(void)
{
	long	start;

	start = gettime();
	printf("start:%ld\n", start);
	while (1)
	{
		if (gettime() - start >= 100)
			break ;
	}
	start = gettime();
	printf("start:%ld\n", start);
} */

int	check_door(t_game *game, int x, int y, int flag)
{
    if (game->map[(int)game->player.y][x] == 'P' || game->map[y][(int)game->player.x] == 'P')
		game->door.open_door = true;
	if (flag == 2 && (game->map[(int)game->player.y][x] != 'P' && game->map[y][(int)game->player.x] != 'P') && game->door.open_door)
		game->door.open_door = false;
	if (flag && (game->map[(int)game->player.y][(int)x] != 'P' || game->player.flag))
		return (1);
	if (game->map[(int)y][(int)game->player.x] != 'P' || game->player.flag)
		return (2);
	return (0);
	game->flag = true;
}


void move_forward(t_game *game)
{
	float	next_x;
	float	next_y;

	next_x = game->player.x + game->player.dir_x / 10;
	next_y = game->player.y + game->player.dir_y / 10;
    if (game->map[(int)game->player.y][(int)next_x] != '1' && check_door(game, next_x, next_y, 2) == 1)
		game->player.x = next_x;
	if (game->map[(int)next_y][(int)game->player.x] != '1' && check_door(game, next_x, next_y, 0) == 2)
		game->player.y = next_y;
	next_x = game->player.x + game->player.dir_x / 10;
	next_y = game->player.y + game->player.dir_y / 10;
	if (game->map[(int)game->player.y][(int)next_x] != '1' && check_door(game, next_x, next_y, 2) == 1)
		game->copy.x = game->player.x;
	if (game->map[(int)next_y][(int)game->player.x] != '1' && check_door(game, next_x, next_y, 0) == 2)
		game->copy.y = game->player.y;
	next_x = (game->player.x + game->player.dir_x);
	next_y = (game->player.y + game->player.dir_y);
	if (game->player.dir_x == 0)
		next_x = game->player.x + 1;
	if (game->player.dir_y == 0)
		next_y = game->player.y + 1;
	check_door(game, (int)next_x, (int)next_y, 0);
	game->flag = true;
}

void move_backwards(t_game *game)
{
    float	next_x;
    float	next_y;

	next_x = game->player.x - game->player.dir_x / 10;
	next_y = game->player.y - game->player.dir_y / 10;
	if (game->map[(int)game->player.y][(int)next_x] != '1' && check_door(game, next_x, next_y, 2) == 1)
		game->player.x = next_x;
	if (game->map[(int)next_y][(int)game->player.x] != '1' && check_door(game, next_x, next_y, 0) == 2)
		game->player.y = next_y;
	next_x = game->player.x - game->player.dir_x / 10;
	next_y = game->player.y - game->player.dir_y / 10;
	if (game->map[(int)game->player.y][(int)next_x] != '1' && check_door(game, next_x, next_y, 2) == 1)
		game->copy.x = game->player.x;
	if (game->map[(int)next_y][(int)game->player.x] != '1' && check_door(game, next_x, next_y, 0) == 2)
		game->copy.y = game->player.y;
	next_x = (game->player.x - game->player.dir_x);
	next_y = (game->player.y - game->player.dir_y);
	if (game->player.dir_x == 0)
		next_x = game->player.x - 1;
	if (game->player.dir_y == 0)
		next_y = game->player.y - 1;
	check_door(game, (int)next_x, (int)next_y, 0);
	game->flag = true;
}

void move_left(t_game *game)
{
	float	next_x;
	float	next_y;

	next_x = game->player.x + game->player.dir_y / 10;
	next_y = game->player.y - game->player.dir_x / 10;
	if (game->map[(int)game->player.y][(int)next_x] != '1' && check_door(game, next_x, next_y, 1) == 1)
		game->player.x = next_x;
	if (game->map[(int)next_y][(int)game->player.x] != '1' && check_door(game, next_x, next_y, 0) == 2)
        game->player.y = next_y;
	next_x = game->player.x + game->player.dir_y / 10;
	next_y = game->player.y - game->player.dir_x / 10;
	if (game->map[(int)game->player.y][(int)next_x] != '1' && check_door(game, next_x, next_y, 1) == 1)
		game->copy.x = game->player.x;
	if (game->map[(int)next_y][(int)game->player.x] != '1' && check_door(game, next_x, next_y, 0) == 2)
		game->copy.y = game->player.y;
	next_x = (game->player.x + game->player.dir_x);
	next_y = (game->player.y - game->player.dir_y);
	if (game->player.dir_x == 0)
		next_x = game->player.x + 1;
	if (game->player.dir_y == 0)
		next_y = game->player.y - 1;
	check_door(game, (int)next_x, (int)next_y, 0);
	game->flag = true;
}

void move_right(t_game *game)
{
	float	next_x;
	float	next_y;

	next_x = game->player.x - game->player.dir_y / 10;
	next_y = game->player.y + game->player.dir_x / 10;
	if (game->map[(int)game->player.y][(int)next_x] != '1' && check_door(game, next_x, next_y, 1) == 1)
		game->player.x = next_x;
	if (game->map[(int)next_y][(int)game->player.x] != '1' && check_door(game, next_x, next_y, 0) == 2)
		game->player.y = next_y;
	next_x = game->player.x - game->player.dir_y / 10;
	next_y = game->player.y + game->player.dir_x / 10;
	if (game->map[(int)game->player.y][(int)next_x] != '1' && check_door(game, next_x, next_y, 1) == 1)
		game->copy.x = game->player.x;
	if (game->map[(int)next_y][(int)game->player.x] != '1' && check_door(game, next_x, next_y, 0) == 2)
		game->copy.y = game->player.y;
	next_x = (game->player.x - game->player.dir_x);
	next_y = (game->player.y + game->player.dir_y);
	if (game->player.dir_x == 0)
		next_x = game->player.x - 1;
	if (game->player.dir_y == 0)
		next_y = game->player.y + 1;
	check_door(game, (int)next_x, (int)next_y, 0);
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