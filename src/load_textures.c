/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:57:40 by asofia-g          #+#    #+#             */
/*   Updated: 2025/01/21 21:27:21 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	texture_error(t_game *game)
{
	free_everything(game);
	mlx_destroy_window(game->connection, game->window);
	mlx_destroy_display(game->connection);
	free(game->connection);
	exit (1);
}

void	load_texture(t_game *game, char *relative_path, int index)
{
	game->textures[index].tex = mlx_xpm_file_to_image(
			game->connection, relative_path, &game->textures[index].tex_width,
			&game->textures[index].tex_height);
	if (game->textures[index].tex == NULL)
	{
		printf(YELLOW"Error while building image"RESET"\n");
		texture_error(game);
	}
	game->textures[index].data_addr = mlx_get_data_addr(
			game->textures[index].tex, &game->textures[index].bpp,
			&game->textures[index].size_line, &game->textures[index].endian);
	game->tex_buff_data[index].tex_height = game->textures[index].tex_height;
	game->tex_buff_data[index].tex_width = game->textures[index].tex_width;
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
void	buffering_texture(t_game *game, char *relative_path, int index, int y)
{
	int		*buffer;
	int		x;
	int		pixel_index;

	load_texture(game, relative_path, index);
	buffer = ft_calloc(1, sizeof * buffer * game->textures[index].tex_width
			* game->textures[index].tex_height);
	if (!buffer)
		texture_error(game);
	while (y < game->textures[index].tex_height)
	{
		x = 0;
		while (x < game->textures[index].tex_width)
		{
			pixel_index = (y * game->textures[index].size_line)
				+ (x * (game->textures[index].bpp / 8));
			buffer[y * game->textures[index].tex_width + x]
				= *(int *)(game->textures[index].data_addr + pixel_index);
			++x;
		}
		y++;
	}
	mlx_destroy_image(game->connection, game->textures[index].tex);
	game->tex_buff[index] = buffer;
}

void	load_all_textures(t_game *game)
{
	game->tex_buff = ft_calloc (NUM_TEXTURES, sizeof * game->tex_buff);
	if (!game->tex_buff)
		texture_error(game);
	buffering_texture(game, game->north.path, NORTH, 0);
	buffering_texture(game, game->south.path, SOUTH, 0);
	buffering_texture(game, game->west.path, WEST, 0);
	buffering_texture(game, game->east.path, EAST, 0);
	if (BONUS)
	{
		buffering_texture(game, ENEMY_TEXTURE, ENEMY, 0);
		buffering_texture(game, ENEMY_DEAD_TEXTURE, ENEMY_DEAD, 0);
		buffering_texture(game, DOOR_CLOSED_TEXTURE, DOOR_CLOSED, 0);
		buffering_texture(game, DOOR_OPEN1_TEXTURE, DOOR_OPEN1, 0);
		buffering_texture(game, DOOR_OPEN2_TEXTURE, DOOR_OPEN2, 0);
		buffering_texture(game, DOOR_OPEN3_TEXTURE, DOOR_OPEN3, 0);
		buffering_texture(game, WEAPON_IDLE_TEXTURE, WEAPON, 0);
		buffering_texture(game, WEAPON_SHOOTING_TEXTURE, WEAPON_SHOOTING, 0);
		ini_weapon(game);
	}
}
