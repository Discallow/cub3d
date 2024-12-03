/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:51:44 by discallow         #+#    #+#             */
/*   Updated: 2024/12/03 12:13:10 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	check_map(t_game *game, char *map)
{
	check_extension(map);
	open_file(game, map);
	read_file(game);
	close(game->fd);
}
