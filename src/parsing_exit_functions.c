/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_exit_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:49:12 by discallow         #+#    #+#             */
/*   Updated: 2025/01/29 17:58:42 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	return_invalid_color(char *str, t_game *game, char *line)
{
	printf(RED"%s: Invalid color at line %d"RESET"\n", str,
		game->copy.line_index);
	free(line);
	free_everything(game);
	exit (1);
}

void	return_invalid_number_players(t_game *game, t_icon texture)
{
	if (texture == PLAYER)
		printf(RED"Invalid number of players"RESET"\n");
	else if (texture == ENEMIES)
		printf(RED"Invalid number of enemies"RESET"\n");
	else if (texture == DOOR)
		printf(RED"Invalid number of doors"RESET"\n");
	free_everything(game);
	exit (1);
}

void	return_invalid_map(t_game *game)
{
	printf(RED"Invalid map"RESET"\n");
	free_everything(game);
	exit (1);
}

void	return_invalid_line(t_game *game, char *line)
{
	printf(RED"Invalid line at line %d: %s"RESET"\n",
		game->copy.line_index, line);
	free(line);
	free_everything(game);
	exit (1);
}
