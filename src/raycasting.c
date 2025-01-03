/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:27:37 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/02 03:24:59 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	ft_get_player_inicial_direction(t_game *game)
{
	if (game->player.flag_pos == 1)
		return;
	if (ft_strcmp(game->player.dir, "N") == 0)
		game->player.dir_y = -1.0;
	if (ft_strcmp(game->player.dir, "S") == 0)
		game->player.dir_y = 1.0;
	if (ft_strcmp(game->player.dir, "E") == 0)
		game->player.dir_x = 1.0;
	if (ft_strcmp(game->player.dir, "W") == 0)
		game->player.dir_x = -1.0;
	game->player.angle = atan2(game->player.dir_y, game->player.dir_x);
	game->player.flag_pos = 1;
}

/*calculate ray position and direction 
*camera plane is perpendicular to the direction
*Since the viewing angle of Wolfenstein 3D, the motif of cub3d, is 66°, 
*the value of the plane vector is set at ±0.66
*/
void	ft_ray_position(t_game *game, int x)
{
	game->calc.plane_x = - game->player.dir_y * 0.66;
	game->calc.plane_y = game->player.dir_x * 0.66;
	game->calc.camera_x = 2 * x / (double)game->x - 1;
	game->calc.ray_dir_x = game->player.dir_x + 
						game->calc.plane_x * game->calc.camera_x;
	game->calc.ray_dir_y = game->player.dir_y + 
						game->calc.plane_y * game->calc.camera_x;
	//printf("dir_x=%f, dir_y= %f, plane_x=%f, plane_y=%f, camera_x=%f, ray_dir_x=%f, ray_dir_y=%f\n", game->player.dir_x, game->player.dir_y, game->calc.plane_x, game->calc.plane_y, game->calc.camera_x, game->calc.ray_dir_x, game->calc.ray_dir_y);//APAGAR
}

/*which box of the map we're in*/
void	ft_which_box_in(t_game *game)
{
	// printf("player_x=%f, player_y=%f\n", game->player.x, game->player.y);//APAGAR
	// printf("player_angle=%f\n", game->player.angle);//APAGAR
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
	//printf("delta_dist_x =%f, delta_dist_y =%f\n", game->calc.delta_dist_x, game->calc.delta_dist_y);//APAGAR
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
	// printf("side_dist_x=%f, side_dist_y=%f\n", game->calc.side_dist_x, game->calc.side_dist_y);//APAGAR
}

/*jump to next map square, either in x-direction, or in y-direction
*if we hit a wall we break out of the loop
*wall_side = 0, means we hit vertical side of the wall
*wall_side = 1, means we hit horizontal side of the wall*/
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
		// printf("map_x=%d, map_y=%d\n", game->calc.map_x, game->calc.map_y);//APAGAR
		// printf("map[map_x][map_y]=%d\n", game->map[game->calc.map_x][game->calc.map_y]);//APAGAR
		if (game->map[game->calc.map_y][game->calc.map_x] == '1') 
			break;
	}
}

/*Calculate distance of perpendicular ray, i.e. remove fisheye effect!*/
void	ft_wall_height(t_game *game)
{
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
	game->calc.line_height = (int)(game->y / game->calc.wall_dist);
	game->calc.draw_start = -game->calc.line_height / 2 + game->y / 2;
	if (game->calc.draw_start < 0)
		game->calc.draw_start = 0;
	game->calc.draw_end = game->calc.line_height / 2 + game->y / 2;
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

/*Calculate x coordinate on the texture*/
void	ft_tex_x(t_game *game)
{
	game->calc.tex_x = (int)(game->calc.wall_x * TEXTURE_SIZE);

	if ((game->calc.wall_side == 0 && game->calc.ray_dir_x < 0) ||
		(game->calc.wall_side == 1 && game->calc.ray_dir_y > 0))
	game->calc.tex_x = TEXTURE_SIZE - game->calc.tex_x - 1;		
}

/*Calculates which texture to use depending wall cardinal direction*/
void	ft_set_wall_texture(t_game *game)
{
	if (game->calc.wall_side == 1)
	{
		if (game->calc.ray_dir_y <= 0)
			game->calc.tex_drawn = NORTH;
		else if (game->calc.ray_dir_y > 0)
			game->calc.tex_drawn = SOUTH;
	}
	else if (game->calc.wall_side == 0)
	{
		if(game->calc.ray_dir_x >= 0)
			game->calc.tex_drawn = EAST;
		else if (game->calc.ray_dir_x < 0)
			game->calc.tex_drawn = WEST;
	}
}
/*give x and y sides different brightness*/
int	ft_set_bright(t_game *game, int color)
{
	if (game->calc.tex_drawn == NORTH || game->calc.tex_drawn == EAST) 
		color = ((color >> 1) & 8355711);
	return(color);
}

/*tex_y_step calculate how much to increase the texture 
*	coordinate per screen pixel
*
*tex_y = (int)pos & (TEXTURE_SIZE - 1) - Cast the texture coordinate to integer
*	and mask with (texHeight - 1) in case of overflow
*/
void	buffering_texture_strip(t_game *game, int **buffer, int x)
{
	int	tex_y;
	int	color;
	int	i;

	load_all_textures(game);
	ft_set_wall_texture(game);
	game->calc.tex_y_step = 1.0 * TEXTURE_SIZE / game->calc.line_height;
	game->calc.tex_y_pos = (game->calc.draw_start - game->y / 2 +
						game->calc.line_height / 2) * game->calc.tex_y_step;
	i = game->calc.draw_start;
	while (i < game->calc.draw_end)
	{
		tex_y = (int)game->calc.tex_y_pos & (TEXTURE_SIZE - 1);	
		game->calc.tex_y_pos += game->calc.tex_y_step;
		// printf("ray_dir_x=%f, ray_di_y=%f, wall_dist=%f, side= %d, x = %d, wall_x = %f, texture to be drawn = %d, tex_x = %d, tex_y =%d\n", game->calc.ray_dir_x, game->calc.ray_dir_y, game->calc.wall_dist, game->calc.wall_side, x, game->calc.wall_x, game->calc.tex_drawn, game->calc.tex_x, tex_y);//APAGAR
		color = game->textures[game->calc.tex_drawn].
					data[TEXTURE_SIZE * tex_y + game->calc.tex_x];
		color = ft_set_bright(game, color);
		if (color > 0)
			buffer[i][x] = color;
		i ++;
	}
	
}

/*give x and y sides different brightness*/
int	ft_chose_color(t_game *game)
{
	int color;

	color = 0x000000FF;
	if (game->calc.wall_side == 0) 
		color = ((color >> 1) & 0x7F7F7F);
	return(color);
}

void	ft_raycasting(t_game *game)
{
	int	x;
	int color;//for untextured
	// int **pixels_buffer;// y-coordinate first because it works per scanline //just for textures
	// int i ;//just for textures
	
	// pixels_buffer = malloc(game->y * sizeof(int *));//just for textures
	// i = 0;
	// while (i < game->y) 
	// {
    // 	pixels_buffer[i] = malloc(game->x * sizeof(int));
    // 	i++;
	// }
	x = 0;
	ft_get_player_inicial_direction(game);
	while (x < game->x)
	{
		ft_ray_position(game, x);
		ft_which_box_in(game);
		ft_delta_dist(game);
		ft_side_dist(game);
		ft_dda(game);
		ft_wall_height(game);
		
		// ft_wall_x(game);//just for textures
		// ft_tex_x(game);//just for textures
		// buffering_texture_strip(game,pixels_buffer,x);//just for textures
		
		color = ft_chose_color(game);//for untextured
		//printf("game.->map2=%p\n", &game->map2);//APAGAR
		//printf("x:%d, game->calc.draw_start:%d, game->calc.draw_end:%d\n", x, game->calc.draw_start, game->calc.draw_end);
		ver_Line(&game->map2, x, game->calc.draw_start, game->calc.draw_end, color);//for untextured
		x++;
	}
	// update_image_from_buffer(game,&game->map2,pixels_buffer);//just for textures
	// i = 0;
	// while (i < game->y) {
	// 	free(pixels_buffer[i]);
	// 	i++;
	// }
	// free(pixels_buffer);
}