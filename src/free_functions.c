/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:58:38 by discallow         #+#    #+#             */
/*   Updated: 2025/01/05 11:42:39 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	free_everything_2(t_game *game)
{
	int	i;

	i = -1;
	if (game->floor.rgb)
	{
		while (game->floor.rgb[++i])
			free(game->floor.rgb[i]);
		free(game->floor.rgb);
	}
	if (game->copy.map_joined)
		free (game->copy.map_joined);
	if (game->map)
	{
		i = -1;
		while (game->map[++i])
			free(game->map[i]);
		free(game->map);
	}
	free_textures(game);//just for textures
}

void	free_everything(t_game *game)
{
	int	i;

	if (game->north.path)
		free(game->north.path);
	if (game->south.path)
		free(game->south.path);
	if (game->west.path)
		free(game->west.path);
	if (game->east.path)
		free(game->east.path);
	if (game->floor.path)
		free(game->floor.path);
	if (game->ceiling.path)
		free(game->ceiling.path);
	i = -1;
	if (game->ceiling.rgb)
	{
		while (game->ceiling.rgb[++i])
			free(game->ceiling.rgb[i]);
		free(game->ceiling.rgb);
	}
	free_everything_2(game);
}
