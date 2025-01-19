/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:11:44 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/19 17:20:01 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	ft_finding_enemys_and_doors(t_game *game, int x, int **buffer)
{
	if (BONUS)
	{
		ft_which_box_in(game);
		ft_side_dist(game);
		ft_dda(game, 'X');
		if (game->calc.enemy_in == 1 && find_enemy_ray(game))
		{
			ft_enemy_height(game);
			game->calc.enemy_pos = x;
		}
		ft_finding_doors(game, buffer, x);
	}
}

/*enemy_dist - distance between player and enemy
*enemy_height - height based on enemy distance*/
void	ft_enemy_height(t_game *game)
{
	double	enemy_dist;
	double	dx;
	double	dy;

	dx = game->enemy.x - game->player.x;
	dy = game->enemy.y - game->player.y;
	enemy_dist = sqrt(dx * dx + dy * dy);
	if (enemy_dist > 0.0)
		game->calc.enemy_height = (int)(game->y / enemy_dist);
	else
		game->calc.enemy_height = game->y;
	ft_wall_height(game, 1, 'X');
}

void	ini_enemy(t_game *game)
{
	game->enemy_data.draw_end_y = game->calc.enemy_height / ENEMY_SCALE
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

void	draw_enemy_stripe(t_game *game, int **buffer, int tex_x, int x)
{
	int		tex_y;
	double	tex_pos;
	int		color;
	int		y;
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
	x = game->calc.enemy_pos - (game->calc.enemy_height / ENEMY_SCALE / 2);
	x_max = game->calc.enemy_pos + (game->calc.enemy_height / ENEMY_SCALE / 2);
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
