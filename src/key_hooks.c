/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 07:53:01 by discallow         #+#    #+#             */
/*   Updated: 2025/01/21 21:27:14 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_released(int keysim, t_game *game)
{
	if (keysim == XK_w || keysim == XK_Up)
		game->player.move_w = false;
	if (keysim == XK_Right)
		game->player.rotate_right = false;
	if (keysim == XK_a)
		game->player.move_a = false;
	if (keysim == XK_s || keysim == XK_Down)
		game->player.move_s = false;
	if (keysim == XK_d)
		game->player.move_d = false;
	if (keysim == XK_Left)
		game->player.rotate_left = false;
	return (0);
}

int	key_pressed(int keysim, t_game *game)
{
	if (keysim == XK_w || keysim == XK_Up)
		game->player.move_w = true;
	if (keysim == XK_Right)
		game->player.rotate_right = true;
	if (keysim == XK_a)
		game->player.move_a = true;
	if (keysim == XK_s || keysim == XK_Down)
		game->player.move_s = true;
	if (keysim == XK_d)
		game->player.move_d = true;
	if (keysim == XK_Left)
		game->player.rotate_left = true;
	if (keysim == XK_Escape)
	{
		printf(RED"Couldn't you kill all the enemies? ");
		printf("Are you afraid?"RESET"\n");
		mlx_destroy_image(game->connection, game->map2.img);
		free_everything(game);
		mlx_destroy_window(game->connection, game->window);
		mlx_destroy_display(game->connection);
		free(game->connection);
		exit(0);
	}
	return (0);
}
