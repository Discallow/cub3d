/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:27:37 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/19 17:26:00 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	ft_get_player_inicial_direction(t_game *game)
{
	static int	flag = 0;

	if (flag)
		return ;
	if (game->player.dir == 'N')
		game->player.dir_y = -1.0;
	if (game->player.dir == 'S')
		game->player.dir_y = 1.0;
	if (game->player.dir == 'E')
		game->player.dir_x = 1.0;
	if (game->player.dir == 'W')
		game->player.dir_x = -1.0;
	game->player.angle = atan2(game->player.dir_y, game->player.dir_x);
	flag++;
}

/*y-coordinate first because it works per collums*/
int	**init_pixels_buffer(t_game *game)
{
	int	**pixels_buffer;
	int	i;

	pixels_buffer = ft_calloc(game->y + 1, sizeof * pixels_buffer);
	if (!pixels_buffer)
	{
		printf(YELLOW"Malloc alocation error"RESET"\n");
		texture_error(game);
	}
	i = 0;
	while (i < game->y)
	{
		pixels_buffer[i] = ft_calloc(game->x + 1, sizeof pixels_buffer);
		if (!pixels_buffer[i])
		{
			printf(YELLOW"Malloc alocation error"RESET"\n");
			texture_error(game);
		}
		i++;
	}
	return (pixels_buffer);
}

/*TEXTURED VERTION*/
void	ft_raycasting(t_game *game)
{
	int	x;
	int	**pixels_buffer;

	pixels_buffer = init_pixels_buffer(game);
	x = 0;
	ft_get_player_inicial_direction(game);
	game->calc.enemy_height = 0;
	game->door.wall_dist = 0;
	while (x < game->x)
	{
		game->calc.enemy_in = 0;
		ft_ray_position(game, x);
		ft_which_box_in(game);
		ft_delta_dist(game);
		ft_side_dist(game);
		ft_dda(game, '1');
		ft_wall_height(game, 1, '1');
		ft_wall_x(game);
		ft_tex_x(game, 1);
		buffering_image_stripe(game, pixels_buffer, x, 0);
		ft_finding_enemys_and_doors(game, x, pixels_buffer);
		x++;
	}
	ft_drawing_enemys_and_weapon(game, pixels_buffer);
	update_image_from_buffer(game, &game->map2, pixels_buffer);
}
