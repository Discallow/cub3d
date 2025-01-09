/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:39:40 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/08 18:23:14 by discallow        ###   ########.fr       */
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
	//printf("pos_x=%d, start=%d, end=%d\n", pos_x, start, end);//APAGAR
	while (y <= end)
	{
		my_mlx_pixel_put(data, pos_x, y, color);
		y++;
	}
}

/*Calculates which texture to use depending wall cardinal direction*/
void	ft_set_wall_texture(t_game *game, int enemy)
{
	if (enemy == 1)
	{
		game->calc.tex_drawn = ENEMY;
		return;
	}
	if (game->door.flag)
	{
		game->door.flag = false;
		game->calc.tex_drawn = DOOR;
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
void	buffering_image_stripe(t_game *game, int **buffer, int x, int enemy)
{
	int	tex_y;
	int	color;
	int	y;

	ft_set_wall_texture(game, enemy);
	game->calc.tex_y_step = 1.0 * TEXTURE_SIZE / game->calc.line_height;
	game->calc.tex_y_pos = (game->calc.draw_start - game->y / 2 +
						game->calc.line_height / 2) * game->calc.tex_y_step;
	y = -1 + game->calc.draw_start * enemy;
	while (y++ < game->calc.draw_start && enemy == 0)
		buffer[y][x] = game->ceiling.color;
	while (y < game->calc.draw_end)
	{
		tex_y = (int)game->calc.tex_y_pos & (TEXTURE_SIZE - 1);	
		game->calc.tex_y_pos += game->calc.tex_y_step;
		color = game->tex_buff[game->calc.tex_drawn]
								[TEXTURE_SIZE * tex_y + game->calc.tex_x];
		color = ft_set_bright(game, color);
		if (color > 0)
			buffer[y][x] = color;
		y ++;
	}
	y = game->calc.draw_end - 1;
	while (enemy == 0 && ++y < game->y)
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