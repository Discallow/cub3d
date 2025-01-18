/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:11:44 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/18 01:01:25 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	ini_enemy(t_game *game)
{
	game->enemy_data.draw_end_y = game->calc.enemy_height / ENEMY_SCALE /*/ 2*/ 
									+ game->y / 2;
	if (game->enemy_data.draw_end_y >= game->y)
		game->enemy_data.draw_end_y = game->y - 1;
	game->enemy_data.draw_start_y = game->enemy_data.draw_end_y 
									- game->calc.enemy_height / ENEMY_SCALE;
	if (game->enemy_data.draw_start_y < 0)
		game->enemy_data.draw_start_y = 0;				
	game->enemy_data.tex_step = (double)game->tex_buff_data[ENEMY].tex_height
								/ (game->calc.enemy_height / ENEMY_SCALE);
	
}

void    draw_enemy_stripe(t_game *game, int **buffer, int	tex_x, int x)
{
	int     tex_y; 
	double  tex_pos;
	int     color;
	int     y;
	int		enemy_to_draw;

	enemy_to_draw = game->enemy_data.enemy_type;
	tex_pos = 0;
	y = game->enemy_data.draw_start_y;
	tex_pos = 0;
	while (y < game->enemy_data.draw_end_y && y < game->y)
	{
		tex_y = (int)tex_pos 
				& (game->tex_buff_data[enemy_to_draw].tex_height - 1);
		tex_pos += game->enemy_data.tex_step;
		color = game->tex_buff[enemy_to_draw][tex_y 
					* game->tex_buff_data[enemy_to_draw].tex_width + tex_x];
		if (color > 0)
			buffer[y][x] = color;
		y++;
	}
}

void	draw_enemy(t_game *game, int **buffer)
{
	int		tex_x;
	int		x;
	int		x_max;
	
	ini_enemy(game);
	x = game->calc.enemy_pos - (game->calc.enemy_height/ ENEMY_SCALE / 2);
	x_max = game->calc.enemy_pos + (game->calc.enemy_height/ ENEMY_SCALE / 2);
	// printf("enemy_height = %d, enemy_pos = %d\n", game->calc.enemy_height, game->calc.enemy_pos);//APAGAR
	while (x < x_max && x < game->x)
	{
		if (x >= 0)
		{
			tex_x = (x - (game->calc.enemy_pos
					- ((game->calc.enemy_height / ENEMY_SCALE) / 2)))
					* game->tex_buff_data[ENEMY].tex_width
					/ (game->calc.enemy_height / ENEMY_SCALE);
			draw_enemy_stripe(game, buffer, tex_x, x);
		}
		x++;
	}
}
