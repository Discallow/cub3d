/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotation_door.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:34:32 by discallow         #+#    #+#             */
/*   Updated: 2025/01/18 15:36:25 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	redraw_map(t_game *game)
{
	mlx_destroy_image(game->connection, game->map2.img);
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

void	rotate_right(t_game *game)
{
	game->player.angle += 0.1;
	if (game->player.angle > 2 * M_PI)
		game->player.angle -= 2 * M_PI;
	game->player.dir_x = cos(game->player.angle);
	game->player.dir_y = sin(game->player.angle);
}

void	rotate_left(t_game *game)
{
	game->player.angle -= 0.1;
	if (game->player.angle < 0)
		game->player.angle += 2 * M_PI;
	game->player.dir_x = cos(game->player.angle);
	game->player.dir_y = sin(game->player.angle);
}
