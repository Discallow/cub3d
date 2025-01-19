/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:52:07 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/19 14:43:11 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/*calculate ray position and direction 
*camera plane is perpendicular to the direction
*Since the viewing angle of Wolfenstein 3D, the motif of cub3d, is 66°, 
*the value of the plane vector is set at ±0.66
*/
void	ft_ray_position(t_game *game, int x)
{
	game->calc.plane_x = -game->player.dir_y * 0.66;
	game->calc.plane_y = game->player.dir_x * 0.66;
	game->calc.camera_x = 2 * x / (double)game->x - 1;
	game->calc.last_ray_dir_x = game->calc.ray_dir_x;
	game->calc.last_ray_dir_y = game->calc.ray_dir_y;
	game->calc.ray_dir_x = game->player.dir_x
		+ game->calc.plane_x * game->calc.camera_x;
	game->calc.ray_dir_y = game->player.dir_y
		+ game->calc.plane_y * game->calc.camera_x;
}

/*which box of the map we're in*/
void	ft_which_box_in(t_game *game)
{
	game->calc.map_x = (int)game->player.x;
	game->calc.map_y = (int)game->player.y;
}

/*length of ray from one x or y-side to next x or y-side*/
void	ft_delta_dist(t_game *game)
{
	if (game->calc.ray_dir_x == 0)
		game->calc.delta_dist_x = 1e30;
	else
		game->calc.delta_dist_x = fabs(1 / game->calc.ray_dir_x);
	if (game->calc.ray_dir_y == 0)
		game->calc.delta_dist_y = 1e30;
	else
		game->calc.delta_dist_y = fabs(1 / game->calc.ray_dir_y);
}

/*side_dist is length of ray from current position to next x or y-side
*step means what direction to step in x or y - direction (either +1 or -1)*/
void	ft_side_dist(t_game *game)
{
	if (game->calc.ray_dir_x < 0)
	{
		game->calc.step_x = -1;
		game->calc.side_dist_x = (game->player.x
				-game->calc.map_x) * game->calc.delta_dist_x;
	}
	else
	{
		game->calc.step_x = 1;
		game->calc.side_dist_x = (game->calc.map_x + 1.0
				-game->player.x) * game->calc.delta_dist_x;
	}
	if (game->calc.ray_dir_y < 0)
	{
		game->calc.step_y = -1;
		game->calc.side_dist_y = (game->player.y
				-game->calc.map_y) * game->calc.delta_dist_y;
	}
	else
	{
		game->calc.step_y = 1;
		game->calc.side_dist_y = (game->calc.map_y + 1.0
				-game->player.y) * game->calc.delta_dist_y;
	}
}

/*jump to next map square, either in x-direction, or in y-direction
*if we hit a wall we break out of the loop
*wall_side = 0, means we hit vertical side of the wall
*wall_side = 1, means we hit horizontal side of the wall*/
void	ft_dda(t_game *game, char c)
{
	while (1)
	{
		if (game->calc.side_dist_x < game->calc.side_dist_y)
		{
			game->calc.side_dist_x += game->calc.delta_dist_x;
			game->calc.map_x += game->calc.step_x;
			game->calc.wall_side = VERTICAL;
		}
		else
		{
			game->calc.side_dist_y += game->calc.delta_dist_y;
			game->calc.map_y += game->calc.step_y;
			game->calc.wall_side = HORIZONTAL;
		}
		if (BONUS && game->map[game->calc.map_y][game->calc.map_x] == 'X')
			game->calc.enemy_in = 1;
		if (BONUS && game->map[game->calc.map_y][game->calc.map_x] == 'P'
			&& c == 'P')
			game->door.flag = true;
		if (game->map[game->calc.map_y][game->calc.map_x] == '1'
			|| game->map[game->calc.map_y][game->calc.map_x] == c
			|| (BONUS && game->map[game->calc.map_y][game->calc.map_x] == 'P'
			&& c == 'P'))
			break ;
	}
}
