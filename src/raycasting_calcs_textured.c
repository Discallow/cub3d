/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calcs_textured.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:12:08 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/21 21:28:13 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*Calculate value of wallX, where exactly the wall was hit*/
void	ft_wall_x(t_game *game)
{
	if (game->calc.wall_side == VERTICAL)
	{
		game->calc.wall_x = game->player.y
			+ game->calc.wall_dist * game->calc.ray_dir_y;
	}
	else
	{
		game->calc.wall_x = game->player.x
			+ game->calc.wall_dist * game->calc.ray_dir_x;
	}
	game->calc.wall_x -= floor(game->calc.wall_x);
}

/*Calculate x coordinate on the texture*/
void	ft_tex_x(t_game *game, int scale)
{
	ft_set_wall_texture(game);
	game->calc.tex_x = (int)(game->calc.wall_x
			* game->tex_buff_data[game->calc.tex_drawn].tex_width * scale);
	if ((game->calc.wall_side == VERTICAL && game->calc.ray_dir_x < 0)
		|| (game->calc.wall_side == HORIZONTAL && game->calc.ray_dir_y > 0))
		game->calc.tex_x = game->tex_buff_data[game->calc.tex_drawn].tex_width
			- game->calc.tex_x - 1;
}
