/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 07:41:50 by discallow         #+#    #+#             */
/*   Updated: 2025/01/21 21:27:39 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_square(t_game *game, int start_x, int start_y, int color)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = game->len;
	if (color == 255)
		len = game->len / 5;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			my_mlx_pixel_put(&game->map2, j + start_x, i + start_y, color);
			j++;
		}
		i++;
	}
}

static void	draw_into_buffer(t_game *game, int i, int j, int k)
{
	if (game->map[game->mini_map.start_i][j] == '1')
		draw_square(game, k * game->len, i * game->len, 0x0000FF00);
	else if (game->map[game->mini_map.start_i][j] == 'X')
	{
		draw_square(game, k * game->len, i * game->len, 0x00808080);
		draw_square(game, k * game->len, i * game->len, 0x00FF0000);
	}
	else
		draw_square(game, k * game->len, i * game->len, 0x00808080);
}

static void	fill_minimap_to_buffer(t_game *game)
{
	int	i;
	int	j;
	int	k;
	int	start_i;

	i = 0;
	start_i = game->mini_map.start_i;
	while (game->mini_map.start_i < game->mini_map.end_i)
	{
		k = 0;
		j = game->mini_map.start_j;
		while (j < game->mini_map.end_j)
		{
			draw_into_buffer(game, i, j, k);
			j++;
			k++;
		}
		game->mini_map.start_i++;
		i++;
	}
	game->mini_map.player_x = (game->player.x
			- (float)game->mini_map.start_j) * game->len;
	game->mini_map.player_y = (game->player.y - (float)start_i) * game->len;
	draw_square(game, (int)game->mini_map.player_x,
		(int)game->mini_map.player_y, 0x000000FF);
}

void	draw_minimap(t_game *game)
{
	game->mini_map.start_i = max(0, (int)game->player.y - 3);
	game->mini_map.end_i = min(game->copy.max_height, (int)game->player.y + 3);
	game->mini_map.start_j = max(0, (int)game->player.x - 3);
	game->mini_map.end_j = min(game->copy.max_width, (int)game->player.x + 3);
	while (game->mini_map.end_i - game->mini_map.start_i < 6)
	{
		if (game->mini_map.start_i > 0)
			game->mini_map.start_i--;
		else if (game->mini_map.end_i < game->copy.max_height)
			game->mini_map.end_i++;
		else
			break ;
	}
	while (game->mini_map.end_j - game->mini_map.start_j < 6)
	{
		if (game->mini_map.start_j > 0)
			game->mini_map.start_j--;
		else if (game->mini_map.end_j < game->copy.max_width)
			game->mini_map.end_j++;
		else
			break ;
	}
	fill_minimap_to_buffer(game);
}
