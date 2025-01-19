/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calcs_untextured.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:45:58 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/19 16:56:51 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/*Calculate distance of perpendicular ray, i.e. remove fisheye effect!*/
void	ft_wall_height(t_game *game, int scale, char c)
{
	if (game->calc.wall_side == VERTICAL)
	{
		game->calc.wall_dist = (game->calc.map_x - game->player.x
				+ (1 - game->calc.step_x) / 2) / game->calc.ray_dir_x;
	}
	else
		game->calc.wall_dist = (game->calc.map_y - game->player.y
				+ (1 - game->calc.step_y) / 2) / game->calc.ray_dir_y;
	if (c == 'X')
		game->enemy.wall_dist = game->calc.wall_dist;
	if (c == 'P')
		game->door.wall_dist = game->calc.wall_dist;
	game->calc.line_height = fmax((int)(game->y
				/ (scale * game->calc.wall_dist)), 0);
	game->calc.draw_start = -game->calc.line_height / 2 + game->y / 2;
	if (game->calc.draw_start < 0)
		game->calc.draw_start = 0;
	game->calc.draw_end = game->calc.line_height / 2 + game->y / 2;
	if (game->calc.draw_end >= game->y || game->calc.wall_dist < 0.01)
		game->calc.draw_end = game->y - 1;
}

/*give x and y sides different brightness*/
int	ft_chose_color(t_game *game)
{
	int	color;

	color = 0x000000FF;
	if (game->calc.wall_side == VERTICAL)
		color = ((color >> 1) & 0x7F7F7F);
	return (color);
}

void	my_mlx_pixel_put(t_position *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ver_line(t_game *game, int pos_x, int color)
{
	int	y;

	y = game->calc.draw_start;
	while (y <= game->calc.draw_end)
	{
		my_mlx_pixel_put(&game->map2, pos_x, y, color);
		y++;
	}
}

/*UNTEXTURED VERTION*/
void	ft_raycasting_untextured(t_game *game)
{
	int	x;
	int	color;

	x = 0;
	ft_get_player_inicial_direction(game);
	while (x < game->x)
	{
		ft_ray_position(game, x);
		ft_which_box_in(game);
		ft_delta_dist(game);
		ft_side_dist(game);
		ft_dda(game, '1');
		ft_wall_height(game, 1, '1');
		color = ft_chose_color(game);
		ver_line(game, x, color);
		x++;
	}
}
