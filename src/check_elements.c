/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:04:35 by discallow         #+#    #+#             */
/*   Updated: 2024/12/03 12:15:19 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	check_valid_line(char *line, t_game *game)
{
	size_t	i;

	i = 0;
	skip_spaces(line, &i);
	if (!line[i])
		return ;
	check_valid_element(line + i, game);
}

bool	check_elements_filled(t_game *game)
{
	if (game->north.path && game->south.path && game->east.path
		&& game->west.path && game->floor.path && game->ceiling.path)
	{
		game->copy.elements_filled = true;
		return (true);
	}
	return (false);
}

void	check_valid_color(t_game *game, char *line, int i)
{
	if (!ft_strncmp(line, "C", i) && !game->ceiling.path)
	{
		game->ceiling.path = check_name(game, line + i, line);
		check_rgb_value(game, &game->ceiling, line);
	}
	else if (!ft_strncmp(line, "F", i) && !game->floor.path)
	{
		game->floor.path = check_name(game, line + i, line);
		check_rgb_value(game, &game->floor, line);
	}
	else
		return_invalid_line(game, line);
}

void	check_valid_element(char *line, t_game *game)
{
	int	i;

	i = 0;
	if (check_elements_filled(game))
		return ;
	while (line[i] && !ft_isspace(line[i]))
		i++;
	if (i == 1 && line[i - 1] != 'C' && line[i - 1] != 'F')
		i = 2;
	if (!ft_strncmp(line, "NO", i) && !game->north.path)
		game->north.path = check_name(game, line + i, line);
	else if (!ft_strncmp(line, "SO", i) && !game->south.path)
		game->south.path = check_name(game, line + i, line);
	else if (!ft_strncmp(line, "EA", i) && !game->east.path)
		game->east.path = check_name(game, line + i, line);
	else if (!ft_strncmp(line, "WE", i) && !game->west.path)
		game->west.path = check_name(game, line + i, line);
	else
		check_valid_color(game, line, i);
	check_elements_filled(game);
}

void	check_rgb_value( t_game *game, t_position *element, char *line)
{
	int		num;

	num = 0;
	element->rgb = ft_split(element->path, ',');
	if (!element->rgb)
		return_invalid_color(element->path, game, line);
	num = ft_atoi2(element->rgb[0]);
	if (num == -1)
		return_invalid_color(element->rgb[0], game, line);
	element->color |= num << 16;
	num = ft_atoi2(element->rgb[1]);
	if (num == -1)
		return_invalid_color(element->rgb[1], game, line);
	element->color |= num << 8;
	num = ft_atoi2(element->rgb[2]);
	if (num == -1)
		return_invalid_color(element->rgb[2], game, line);
	element->color |= num;
}
