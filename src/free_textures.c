/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:09:43 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/07 02:11:01 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void    free_textures(t_game *game)
{
	int i;

	if (!game->tex_buff)
		return ;
	i = 0;
	while (i < NUM_TEXTURES)
	{
		if (game->tex_buff[i])
		{
			free(game->tex_buff[i]);
			game->tex_buff[i] = NULL;
		}
		i++;
	}
	free(game->tex_buff);
	game->tex_buff = NULL;
}

void	free_pixels_buffer(int **pixels_buffer, int height)
{
	int i;

	if (!pixels_buffer)
		return ;
	i = 0;
	while (i < height)
	{
		if (pixels_buffer[i])
		{
			free(pixels_buffer[i]);
			pixels_buffer[i] = NULL;
		}
		i++;
	}
	free(pixels_buffer);
	pixels_buffer = NULL;
}
