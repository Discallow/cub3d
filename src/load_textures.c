/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:57:40 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/07 00:49:25 by asofia-g         ###   ########.fr       */
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
	// if (game->textures[index].tex == NULL)//CLEAR EVERITHING
	game->textures[index].data_addr = mlx_get_data_addr(
								game->textures[index].tex,
								&game->textures[index].bpp,
								&game->textures[index].size_line,
								&game->textures[index].endian);
}
/*The data_addr is simply a continuous block of memory where the texture data 
is stored line by line.
The size_line indicates how many bytes are in each line of the texture, 
including potential alignment bytes (padding).
To access a pixel at position (x, y) in the texture, you need to consider:
The offset to the correct line: y * size_line.
The offset to the correct pixel within that line: x * (bpp / 8).
Each pixel can occupy multiple bytes (32 bits = 4 bytes for 64x64 images), 
so we need to treat the data as int * to read the full 4-byte value. 
This is why we add pixel_index to the pointer position.
*/
void	buffering_texture(t_game *game, char *relative_path, int index)
{
	int		*buffer;
	int		x;
	int		y;
	int 	pixel_index;
	
	load_texture(game, relative_path, index);
	buffer = ft_calloc(1, sizeof * buffer * TEXTURE_SIZE * TEXTURE_SIZE);
	// if (!buffer)//CLEAR EVERITHING
	y = 0;
	while (y < TEXTURE_SIZE)
	{
		x = 0;
		while (x < TEXTURE_SIZE)
		{
			pixel_index = (y * game->textures[index].size_line) + 
							(x * (game->textures[index].bpp / 8));
			buffer[y * TEXTURE_SIZE + x] = 
					*(int *)(game->textures[index].data_addr + pixel_index);
			++x;
		}
		y++;
	}
	mlx_destroy_image(game->connection, game->textures[index].tex);
	game->tex_buff[index] = buffer;
}

void    load_all_textures(t_game *game)
{	game->tex_buff = ft_calloc (NUM_TEXTURES, sizeof*game->tex_buff);
	//if (!game->textures_test)//CLEAR EVERITHING
	buffering_texture(game, game->north.path, NORTH);
	buffering_texture(game, game->south.path, SOUTH);
	buffering_texture(game, game->west.path, WEST);
	buffering_texture(game, game->east.path, EAST);
	buffering_texture(game,"textures/enemy.xpm", ENEMY);
	//se alguma textura deu erro ao ser copiada, é necessário apagar todas
}
