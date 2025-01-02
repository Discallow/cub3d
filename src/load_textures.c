/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:57:40 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/02 00:35:21 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	load_texture(t_game *game, char *relative_path, int index)
{
	game->textures[index].tex = mlx_xpm_file_to_image(
								game->connection, 
								relative_path, 
								&game->textures[index].tex_width,
								&game->textures[index].tex_height);
	game->textures[index].data = mlx_get_data_addr(
								game->textures[index].tex,
								&game->textures[index].bpp,
								&game->textures[index].size_line,
								&game->textures[index].endian);
}

void    load_all_textures(t_game *game)
{	
	load_texture(game, game->north.path, NORTH);
	load_texture(game, game->south.path, SOUTH);
	load_texture(game, game->west.path, WEST);
	load_texture(game, game->east.path, EAST);
}