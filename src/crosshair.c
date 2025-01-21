/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 07:55:11 by discallow         #+#    #+#             */
/*   Updated: 2025/01/21 21:26:25 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_filled_rect(t_game *game, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->crosshair.height)
	{
		j = 0;
		while (j < game->crosshair.width)
		{
			my_mlx_pixel_put(&game->map2, x + j, y + i, 0x0000FFFF);
			j++;
		}
		i++;
	}
}

void	draw_crosshair(t_game *game)
{
	game->crosshair.line_length = (int)(min(game->x, game->y) * 0.01f);
	game->crosshair.thickness = max(1, game->crosshair.line_length / 4);
	game->crosshair.x_start = game->x / 2 - (game->crosshair.thickness / 2);
	game->crosshair.y_start_vertical = game->y / 2
		- (game->crosshair.line_length / 2);
	game->crosshair.y_end_vertical = game->y / 2
		+ (game->crosshair.line_length / 2);
	game->crosshair.height = game->crosshair.y_end_vertical
		- game->crosshair.y_start_vertical;
	game->crosshair.width = game->crosshair.thickness;
	draw_filled_rect(game, game->crosshair.x_start,
		game->crosshair.y_start_vertical);
	game->crosshair.y_start = game->y / 2 - (game->crosshair.thickness / 2);
	game->crosshair.x_start_horizontal = game->x / 2
		- (game->crosshair.line_length / 2);
	game->crosshair.x_end_horizontal = game->x / 2
		+ (game->crosshair.line_length / 2);
	game->crosshair.height = game->crosshair.thickness;
	game->crosshair.width = game->crosshair.x_end_horizontal
		- game->crosshair.x_start_horizontal;
	draw_filled_rect(game, game->crosshair.x_start_horizontal,
		game->crosshair.y_start);
}
