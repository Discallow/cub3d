/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:51:44 by discallow         #+#    #+#             */
/*   Updated: 2025/01/03 12:28:18 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	check_map(t_game *game, char *map)
{
	if (check_extension(map))
		exit (1);
	open_file(game, map);
	read_file(game);
	close(game->fd);
}
