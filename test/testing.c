/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:27:37 by asofia-g          #+#    #+#             */
/*   Updated: 2024/12/14 16:25:30 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void    ft_get_cardinal_direction(t_game *game)
{
    if (game->player.dir == N)
        game->player.dir_y = 1;
    if (game->player.dir == S)
        game->player.dir_y = -1;
    if (game->player.dir == E)
        game->player.dir_x = 1;
    if (game->player.dir == W)
        game->player.dir_x = -1;
}
//void	raycasting(t_game *game)