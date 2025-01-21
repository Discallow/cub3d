/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 07:37:24 by discallow         #+#    #+#             */
/*   Updated: 2025/01/21 21:27:46 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	mouse_pressed(int button, int x, int y, t_game *game)
{
	if (button == Button1)
		game->player.shoot = true;
	(void)x;
	(void)y;
	return (0);
}

static int	mouse_released(int button, int x, int y, t_game *game)
{
	if (button == Button1)
		game->player.shoot = false;
	(void)x;
	(void)y;
	return (0);
}

static int	mouse_moved(int x, int y, t_game *game)
{
	(void)y;
	if (x < game->x / 3)
	{
		game->player.rotate_left = true;
		game->player.rotate_right = false;
	}
	else if (x > game->x * 2 / 3)
	{
		game->player.rotate_left = false;
		game->player.rotate_right = true;
	}
	else
	{
		game->player.rotate_left = false;
		game->player.rotate_right = false;
	}
	return (0);
}

void	check_mouse_hooks(t_game *game)
{
	mlx_hook(game->window, ButtonPress, ButtonPressMask, mouse_pressed, game);
	mlx_hook(game->window, ButtonRelease, ButtonReleaseMask,
		mouse_released, game);
	mlx_hook(game->window, MotionNotify, PointerMotionMask, mouse_moved, game);
}
