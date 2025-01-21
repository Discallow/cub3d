/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_door_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:38:11 by discallow         #+#    #+#             */
/*   Updated: 2025/01/21 21:26:17 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	close_doors2(t_game *game, int *flag)
{
	long		start;
	static int	text = 0;

	start = gettime();
	if (text && start - game->elapsed >= 600)
	{
		game->calc.tex_drawn = DOOR_CLOSED;
		game->door.close_door = true;
		*flag = 0;
	}
	else if (text && start - game->elapsed >= 400)
		game->calc.tex_drawn = DOOR_OPEN1;
	else if (game->elapsed && start - game->elapsed >= 200)
	{
		text++;
		game->calc.tex_drawn = DOOR_OPEN2;
	}
	else
	{
		game->player.flag = true;
		text = 0;
		game->calc.tex_drawn = DOOR_OPEN3;
	}
}

static void	close_doors(t_game *game)
{
	static int	flag = 0;

	if (game->door.close_door || game->door.open_door)
		return ;
	if (flag == 0)
	{
		flag++;
		game->elapsed = gettime();
	}
	close_doors2(game, &flag);
}

static void	open_doors(t_game *game)
{
	long		start;
	static int	text = 0;

	start = gettime();
	if (game->door.open_door && !game->door.close_door)
		game->calc.tex_drawn = DOOR_OPEN3;
	if (game->door.open_door == false || game->door.close_door == false)
		return ;
	if (text && start - game->elapsed >= 600)
	{
		game->calc.tex_drawn = DOOR_OPEN3;
		game->door.close_door = false;
		game->player.flag = true;
	}
	else if (game->elapsed && start - game->elapsed >= 400)
	{
		text++;
		game->calc.tex_drawn = DOOR_OPEN2;
	}
	else
	{
		text = 0;
		game->calc.tex_drawn = DOOR_OPEN1;
	}
}

static void	check_door_texture(t_game *game)
{
	game->door.flag = false;
	if (game->door.open_door == false && game->door.close_door)
	{
		game->calc.tex_drawn = DOOR_CLOSED;
		game->player.flag = false;
		game->elapsed = gettime();
	}
	open_doors(game);
	close_doors(game);
}

/*Calculates which texture to use depending wall cardinal direction*/
void	ft_set_wall_texture(t_game *game)
{
	if (game->door.flag)
	{
		check_door_texture(game);
		return ;
	}
	if (game->calc.wall_side == HORIZONTAL)
	{
		if (game->calc.ray_dir_y <= 0)
			game->calc.tex_drawn = NORTH;
		else if (game->calc.ray_dir_y > 0)
			game->calc.tex_drawn = SOUTH;
	}
	else if (game->calc.wall_side == VERTICAL)
	{
		if (game->calc.ray_dir_x >= 0)
			game->calc.tex_drawn = EAST;
		else if (game->calc.ray_dir_x < 0)
			game->calc.tex_drawn = WEST;
	}
}
