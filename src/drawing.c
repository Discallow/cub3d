/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:39:40 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/02 01:30:04 by asofia-g         ###   ########.fr       */
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

void update_image_from_buffer(t_game *game, t_position *data, 
								int **buffer)
{
	int			x;
	int 		y;
	int	*img_addr;
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

