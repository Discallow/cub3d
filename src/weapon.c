/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:46:17 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/21 21:29:16 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ini_weapon(t_game *game)
{
	game->weapon_data.draw_end_y = game->y - game->y / 15;
	game->weapon_data.draw_start_y = game->weapon_data.draw_end_y
		- (int)(game->y / WEAPON_SCALE);
	game->weapon_data.tex_step[WEAPON]
		= (double)game->tex_buff_data[WEAPON].tex_height
		/ (game->y / WEAPON_SCALE);
	game->weapon_data.tex_step[WEAPON_SHOOTING]
		= (double)game->tex_buff_data[WEAPON_SHOOTING].tex_height
		/ (game->y / WEAPON_SCALE);
}

void	draw_weapon_stripe(t_game *game, int **buffer, int weapon_type, int x)
{
	int		tex_y;
	double	tex_pos;
	int		color;
	int		y;

	tex_pos = 0;
	y = game->weapon_data.draw_start_y;
	while (y < game->weapon_data.draw_end_y && y < game->y)
	{
		tex_y = (int)tex_pos
			& (game->tex_buff_data[weapon_type].tex_height - 1);
		tex_pos += game->weapon_data.tex_step[weapon_type];
		color = game->tex_buff[weapon_type][tex_y
			* game->tex_buff_data[weapon_type].tex_width
			+ game->weapon_data.tex_x];
		if (color > 0)
			buffer[y][x] = color;
		y++;
	}
}

void	draw_weapon(t_game *game, int **buffer, int weapon_type)
{
	int	x;

	x = game->x / 2 - ((game->y / WEAPON_SCALE) / 2);
	while (x < game->x / 2 + ((game->y / WEAPON_SCALE) / 2))
	{
		if (x >= 0)
		{
			game->weapon_data.tex_x = (x - (game->x / 2
						- ((game->y / WEAPON_SCALE) / 2)))
				* game->tex_buff_data[weapon_type].tex_width
				/ (game->y / WEAPON_SCALE);
			draw_weapon_stripe(game, buffer, weapon_type, x);
		}
		x++;
	}
}
