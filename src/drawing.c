/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:39:40 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/21 21:26:46 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*give x and y sides different brightness*/
static int	ft_set_bright(t_game *game, int color)
{
	if (game->calc.tex_drawn == NORTH || game->calc.tex_drawn == EAST)
		color = ((color >> 1) & 8355711);
	return (color);
}

/*Draw a vertical stripe with the colors of the texture
*
*tex_y_step calculate how much to increase the texture 
*	coordinate per screen pixel
*
*tex_y = (int)pos & (TEXTURE_SIZE - 1) - Cast the texture coordinate to integer
*	and mask with (texHeight - 1) in case of overflow
*/
void	buffering_image_stripe(t_game *game, int **buffer, int x, int y)
{
	int	tex_y;
	int	color;

	game->calc.tex_y_step = 1.0
		* game->tex_buff_data[game->calc.tex_drawn].tex_height
		/ game->calc.line_height;
	game->calc.tex_y_pos = (game->calc.draw_start - game->y / 2
			+ game->calc.line_height / 2) * game->calc.tex_y_step;
	while (y++ < game->calc.draw_start && y < game->y)
		buffer[y][x] = game->ceiling.color;
	while (y < game->calc.draw_end)
	{
		tex_y = (int)game->calc.tex_y_pos
			& (game->tex_buff_data[game->calc.tex_drawn].tex_height - 1);
		game->calc.tex_y_pos += game->calc.tex_y_step;
		color = game->tex_buff[game->calc.tex_drawn][game->tex_buff_data[
			game->calc.tex_drawn].tex_width * tex_y + game->calc.tex_x];
		if (ft_set_bright(game, color) > 0)
			buffer[y][x] = ft_set_bright(game, color);
		y++;
	}
	y = game->calc.draw_end - 1;
	while (++y < game->y)
		buffer[y][x] = game->floor.color;
}

void	update_image_from_buffer(t_game *game, t_position *data,
								int **buffer)
{
	int	x;
	int	y;
	int	*img_addr;
	int	pixel_index;

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
	free_pixels_buffer(buffer, game->y);
}

void	ft_drawing_enemys_and_weapon(t_game *game, int **pixels_buffer)
{
	if (BONUS)
	{
		enemy_can_die(game, pixels_buffer);
		if (game->player.shoot)
			draw_weapon(game, pixels_buffer, WEAPON_SHOOTING);
		else
			draw_weapon(game, pixels_buffer, WEAPON);
	}
}
