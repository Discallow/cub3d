/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:39:40 by asofia-g          #+#    #+#             */
/*   Updated: 2024/12/21 05:50:37 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* void    draw_rays_3D(t_game *game)
{
    int mx;
    int my;
    int mp;
    double  dof;
    double  aTan;
    
    game->calc.ray_angle = game->player.angle;
    dof = 0;
    aTan = -1 / tan(game->calc.ray_angle);
    if (game->calc.ray_angle > M_PI)
    {
        game->calc.ray_dir_y = (((int)game->player.y >> 6) << 6) - 0.0001;
        game->calc.ray_dir_x = game->player.y - game->calc.ray_dir_y
    }
} */

void	my_mlx_pixel_put(t_position *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void    ver_Line(t_position *data, int pos_x, int start, int end, int color)
{
    int y;
    
    y = start;
    printf("pos_x=%d, start=%d, end=%d\n", pos_x, start, end);//APAGAR
    while (y <= end)
    {
        my_mlx_pixel_put(data, pos_x, y, color);
        y++;
    }
}