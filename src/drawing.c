/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:39:40 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/17 16:41:30 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	my_mlx_pixel_put(t_position *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void    ver_Line(t_position *data, int pos_x, int start, int end, int color)
{
	int y;
	
	y = start;
	while (y <= end)
	{
		my_mlx_pixel_put(data, pos_x, y, color);
		y++;
	}
}

void	change_door_texture2(t_game *game)
{
	long	start;
	static int	text = 0;
	static int	flag = 0;

	start = gettime();
	if (game->door.close_door || game->door.open_door)
		return ;
	if (flag == 0)
	{
		flag++;
		game->elapsed = gettime();
	}
	if (text && start - game->elapsed >= 600)
	{
		game->calc.tex_drawn = DOOR_CLOSED;
		game->door.close_door = true;
		flag = 0;
	}
	else if (text && start - game->elapsed >= 400)
	{
		game->calc.tex_drawn = DOOR_OPEN1;
	}
	else if (game->elapsed && start - game->elapsed >= 200) 
	{
		text++;
		game->calc.tex_drawn = DOOR_OPEN2;
	}
	else
	{
		game->player.flag = true;
		text = 0;
		game->calc.tex_drawn = DOOR_OPEN3;
	}
}

void	change_door_texture(t_game *game)
{
	long	start;
	static int	text = 0;

	start = gettime();
	if (game->door.open_door && !game->door.close_door)
		game->calc.tex_drawn = DOOR_OPEN3;
	if (game->door.open_door == false || game->door.close_door == false)
		return ;
	if (text && start - game->elapsed >= 600)
	{
		game->calc.tex_drawn = DOOR_OPEN3;
		game->door.close_door = false;
		game->player.flag = true;
	}
	else if (game->elapsed && start - game->elapsed >= 400)
	{
		text++;
		game->calc.tex_drawn = DOOR_OPEN2;
	}
	else
	{
		text = 0;
		game->calc.tex_drawn = DOOR_OPEN1;
	}
}

/*Calculates which texture to use depending wall cardinal direction*/
void	ft_set_wall_texture(t_game *game)
{
	if (game->door.flag)
	{
		game->door.flag = false;
		if (game->door.open_door == false && game->door.close_door)
		{
			game->calc.tex_drawn = DOOR_CLOSED;
			game->player.flag = false;
			game->elapsed = gettime();
		}
		change_door_texture(game);
		change_door_texture2(game);
		return ;
	}
	if (game->calc.wall_side == HORIZONTAL)
	{
		if (game->calc.ray_dir_y <= 0)
			game->calc.tex_drawn = NORTH;
		else if (game->calc.ray_dir_y > 0)
			game->calc.tex_drawn = SOUTH;
	}
	else if (game->calc.wall_side == VERTICAL)
	{
		if(game->calc.ray_dir_x >= 0)
			game->calc.tex_drawn = EAST;
		else if (game->calc.ray_dir_x < 0)
			game->calc.tex_drawn = WEST;
	}
}
/*give x and y sides different brightness*/
int		ft_set_bright(t_game *game, int color)
{
	if (game->calc.tex_drawn == NORTH || game->calc.tex_drawn == EAST) 
		color = ((color >> 1) & 8355711);
	return(color);
}

/*Draw a vertical stripe with the colors of the texture
*
*tex_y_step calculate how much to increase the texture 
*	coordinate per screen pixel
*
*tex_y = (int)pos & (TEXTURE_SIZE - 1) - Cast the texture coordinate to integer
*	and mask with (texHeight - 1) in case of overflow
*/
void	buffering_image_stripe(t_game *game, int **buffer, int x)
{
	int	tex_y;
	int	color;
	int	y;

	game->calc.tex_y_step = 1.0 * game->tex_buff_data[
					game->calc.tex_drawn].tex_height / game->calc.line_height;
	game->calc.tex_y_pos = (game->calc.draw_start - game->y / 2 +
						game->calc.line_height / 2) * game->calc.tex_y_step;
	y = 0;
	while (y++ < game->calc.draw_start && y < game->y)
		buffer[y][x] = game->ceiling.color;
	while (y < game->calc.draw_end)
	{
		tex_y = (int)game->calc.tex_y_pos & 
					(game->tex_buff_data[game->calc.tex_drawn].tex_height - 1);
		game->calc.tex_y_pos += game->calc.tex_y_step;
		color = game->tex_buff[game->calc.tex_drawn][game->tex_buff_data[
				game->calc.tex_drawn].tex_width * tex_y + game->calc.tex_x];
		if (ft_set_bright(game, color) > 0)
			buffer[y][x] = ft_set_bright(game, color);
		y ++;
	}
	y = game->calc.draw_end - 1;
	while (++y < game->y)
		buffer[y][x] = game->floor.color;
}

void update_image_from_buffer(t_game *game, t_position *data, 
								int **buffer)
{
	int			x;
	int 		y;
	int			*img_addr;
	int			pixel_index;

	img_addr = (int *)data->addr;
	y = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			pixel_index = y * (data->line_len / 4) + x;
			if (buffer[y][x] > 0)
				img_addr[pixel_index] = buffer[y][x];
			x++;
		}
		y++;
	}
}
