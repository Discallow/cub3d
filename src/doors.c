/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:45:11 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/19 13:48:16 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	ft_finding_doors(t_game *game, int **buffer, int x)
{
	ft_which_box_in(game);
	ft_side_dist(game);
	ft_dda(game, 'P');
	if (game->door.flag)
	{
		ft_wall_height(game, 1, 'P');
		ft_wall_x(game);
		ft_tex_x(game, 1);
		buffering_image_stripe(game, buffer, x, 0);
	}
}
