/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:51:44 by discallow         #+#    #+#             */
/*   Updated: 2025/01/18 16:55:39 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	read_file(t_game *game)
{
	char	*line;

	while (1)
	{
		if (game->copy.elements_filled)
			break ;
		line = get_next_line(game->fd);
		if (!line)
		{
			free(line);
			break ;
		}
		game->copy.line_index++;
		check_valid_line(line, game);
		free(line);
	}
	if (game->copy.elements_filled == false)
	{
		printf(RED"Not all the elements were defined"RESET"\n");
		free_everything(game);
		exit (1);
	}
	check_image_extension(game);
	read_map(game);
}

void	check_map(t_game *game, char *map)
{
	if (check_extension(map))
		exit (1);
	open_file(game, map);
	read_file(game);
	close(game->fd);
}
