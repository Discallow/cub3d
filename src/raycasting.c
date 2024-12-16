/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:27:37 by asofia-g          #+#    #+#             */
/*   Updated: 2024/12/16 02:35:55 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	ft_get_player_inicial_direction(t_game *game)
{
	if (ft_strcmp(game->player.dir, "N") == 0)
		game->player.dir_y = -1;
	if (ft_strcmp(game->player.dir, "S") == 0)
		game->player.dir_y = 1;
	if (ft_strcmp(game->player.dir, "E") == 0)
		game->player.dir_x = 1;
	if (ft_strcmp(game->player.dir, "W") == 0)
		game->player.dir_x = -1;
}

/*calculate ray position and direction 
*camera plane is perpendicular to the direction
*Since the viewing angle of Wolfenstein 3D, the motif of cub3d, is 66°, 
*the value of the plane vector is set at ±0.66
*/
void	ft_ray_position(t_game *game, int x)
{
	game->calc.plane_x = game->player.dir_y;
	game->calc.plane_y = - game->player.dir_x;
	game->calc.camera_x = 2 * x / (double)game->x - 1;
	game->calc.ray_dir_x = game->player.dir_x + 
						game->calc.plane_x * game->calc.camera_x;
	game->calc.ray_dir_y = game->player.dir_y + 
						game->calc.plane_y * game->calc.camera_x;
	printf("dir_x=%d, dir_y= %d, plane_x=%f, plane_y=%f, camera_x=%f, ray_dir_x=%f, ray_dir_y=%f\n", game->player.dir_x, game->player.dir_y, game->calc.plane_x, game->calc.plane_y, game->calc.camera_x, game->calc.ray_dir_x, game->calc.ray_dir_y);//APAGAR
}

/*which box of the map we're in*/
void	ft_which_box_in(t_game *game)
{
	printf("player_x=%d, player_y=%d\n", (int)game->player.x, (int)game->player.y);//APAGAR
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
		game->calc.side_dist_x = (game->player.x - 
								game->calc.map_x) * game->calc.delta_dist_x;
	}
	else
	{
		game->calc.step_x = 1;
		game->calc.side_dist_x = (game->calc.map_x + 1.0 - 
								game->player.x) * game->calc.delta_dist_x;
	}
	if (game->calc.ray_dir_y < 0)
	{
		game->calc.step_y = -1;
		game->calc.side_dist_y = (game->player.y - 
								game->calc.map_y) * game->calc.delta_dist_y;
	}
	else
	{
		game->calc.step_y = 1;
		game->calc.side_dist_y = (game->calc.map_y + 1.0 - 
								game->player.y) * game->calc.delta_dist_y;
	}
	printf("side_dist_x=%f, side_dist_y=%f\n", game->calc.side_dist_x, game->calc.side_dist_y);//APAGAR
}

/*jump to next map square, either in x-direction, or in y-direction
*if we hit a wall we break out of the loop
*wall_side = 0, means we hit x side of the wall
*wall_side = 1, means we hit x side of the wall*/
void	ft_dda(t_game *game)
{
	while (1)
	{
		if (game->calc.side_dist_x < game->calc.side_dist_y)
		{
			game->calc.side_dist_x += game->calc.delta_dist_x;
			game->calc.map_x += game->calc.step_x;
			game->calc.wall_side = 0;
		}
		else
		{
			game->calc.side_dist_y += game->calc.delta_dist_y;
			game->calc.map_y += game->calc.step_y;
			game->calc.wall_side = 1;
		}
		printf("map_x=%d, map_y=%d\n", game->calc.map_x, game->calc.map_y);//APAGAR
		printf("map[map_x][map_y]=%d\n", game->map[game->calc.map_x][game->calc.map_y]);//APAGAR
		if (game->map[game->calc.map_x][game->calc.map_y] == '1') 
			break;
	}
}

/*Calculate distance of perpendicular ray, i.e. remove fisheye effect!*/
void	ft_wall_height(t_game *game)
{
	int 	line_height;

	if (game->calc.wall_side == 0)
	{
		game->calc.wall_dist = (game->calc.map_x - game->player.x +
			(1 - game->calc.step_x) / 2) / game->calc.ray_dir_x;
	}
	else
	{
		game->calc.wall_dist = (game->calc.map_y - game->player.y + 
			(1 - game->calc.step_y) / 2) / game->calc.ray_dir_y;
	}
	line_height = (int)(game->y / game->calc.wall_dist);
	game->calc.draw_start = -line_height / 2 + game->y / 2;
	if (game->calc.draw_start < 0)
		game->calc.draw_start = 0;
	game->calc.draw_end = line_height / 2 + game->y / 2;
	if (game->calc.draw_end >= game->y)
		game->calc.draw_end = game->y - 1;
}

/*Calculate value of wallX, where exactly the wall was hit*/
void	ft_wall_x(t_game *game)
{	
	if (game->calc.wall_side == 0)
	{
		game->calc.wall_x = game->player.y + 
								game->calc.wall_dist * game->calc.ray_dir_y;
	}
	else
	{
		game->calc.wall_x = game->player.x + 
								game->calc.wall_dist * game->calc.ray_dir_x;
	}
	game->calc.wall_x -= floor(game->calc.wall_x);
}

/*give x and y sides different brightness*/
int	ft_chose_color(t_game *game)
{
	int color;

	color = 0x000000FF;
	if (game->calc.wall_side == 1) 
		color = ((color >> 1) & 0x7F7F7F);
	return(color);
}

void	ft_raycasting(t_game *game)
{
	int	x;
	// int color;
	
	x = 0;
	ft_get_player_inicial_direction(game);//qdo o player se mexer não pode vir buscar esta função
	while (x < game->x)
	{
		ft_ray_position(game, x);
		ft_which_box_in(game);
		ft_delta_dist(game);
		ft_side_dist(game);
		ft_dda(game);
		ft_wall_height(game);
		// ft_wall_x(game) //just for textures
		ft_chose_color(game);
		// color = ft_chose_color(game);
		printf("game.->map2=%p\n", &game->map2);//APAGAR
		ver_Line(&game->map2, x, game->calc.draw_start, game->calc.draw_end, 0x000000FF);
		x++;
	}
}