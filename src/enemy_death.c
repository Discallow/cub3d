/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:13:37 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/19 17:27:02 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/*Check if the vector player-enemy is aligned with the ray
*Calculate the player-enemy vector. Calculate the cross product of the 
*current last ray with the player-enemy vector, and do the same for the next 
*ray.Multiply the two cross products by each other; if there is a sign change,
*the ray has passed through the player-enemy vector.*/
int	find_enemy_ray(t_game *game)
{
	double	player_to_enemy_x;
	double	player_to_enemy_y;
	double	cross_product_last;
	double	cross_product_current;

	player_to_enemy_x = game->enemy.x - game->player.x;
	player_to_enemy_y = game->enemy.y - game->player.y;
	cross_product_last = (game->calc.last_ray_dir_x * player_to_enemy_y)
		- (game->calc.last_ray_dir_y * player_to_enemy_x);
	cross_product_current = (game->calc.ray_dir_x * player_to_enemy_y)
		- (game->calc.ray_dir_y * player_to_enemy_x);
	if (cross_product_last * cross_product_current < 0)
		return (1);
	return (0);
}

void	enemy_can_die(t_game *game, int **buffer)
{
	double		dist;
	static long	start;

	dist = sqrt(pow(game->enemy.x - game->player.x, 2)
			+ pow(game->enemy.y - game->player.y, 2));
	if (game->calc.enemy_height && game->player.shoot)
	{
		if (game->calc.enemy_pos > game->x / 2 - ((game->y / WEAPON_SCALE))
			&& game->calc.enemy_pos < game->x / 2 + ((game->y / WEAPON_SCALE))
			&& dist < 2.0)
		{
			start = gettime();
			game->enemy_data.enemy_type = ENEMY_DEAD;
		}
	}
	if (game->enemy_data.enemy_type == ENEMY_DEAD && gettime() - start >= 400)
		game->map[(int)game->enemy.y][(int)game->enemy.x] = '0';
	if (game->calc.enemy_height && (!game->door.wall_dist
			|| game->door.open_door
			|| game->enemy.wall_dist < game->door.wall_dist))
		draw_enemy(game, buffer);
}
