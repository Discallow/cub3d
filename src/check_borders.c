/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:12:53 by discallow         #+#    #+#             */
/*   Updated: 2025/01/29 18:28:58 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_map_end(t_game *game, char *line)
{
	size_t	i;
	char	*temp_line;

	temp_line = NULL;
	while (1)
	{
		i = 0;
		temp_line = get_next_line(game->fd);
		if (!temp_line)
		{
			free(temp_line);
			break ;
		}
		game->copy.line_index++;
		skip_spaces(temp_line, &i);
		if (temp_line[i] != '\0')
		{
			free(line);
			return_invalid_line(game, temp_line);
		}
		free(temp_line);
	}
	game->copy.map_read = true;
}

void	check_if_map_closed(t_game *game, int x, int y)
{
	int	len;
	int	max_y;

	len = 0;
	while (game->map[x][y] && game->map[x][y] != ' ')
	{
		max_y = ft_strlen(game->map[x - 1]) - 1;
		x++;
		if (y > max_y)
			break ;
		max_y = ft_strlen(game->map[x]) - 1;
		if (y > max_y)
			break ;
	}
	if ((len == 0 && game->map[x - 1][y] != '1') || game->map[x - 1][y] != '1')
		return_invalid_map(game);
}

void	check_door_borders(t_game *game, int x, int y)
{
	bool	vertical_walls;
	bool	horizontal_walls;

	vertical_walls = false;
	horizontal_walls = false;
	game->door.num++;
	if (game->map[x - 1][y] == '1' && game->map[x + 1][y] == '1')
		vertical_walls = true;
	if (game->map[x][y - 1] == '1' && game->map[x][y + 1] == '1')
		horizontal_walls = true;
	if (!vertical_walls && !horizontal_walls)
	{
		printf(RED"You need walls around the door!"RESET"\n");
		free_everything(game);
		exit (1);
	}
}

void	check_borders(t_game *game, int x, int y)
{
	int	len;

	if (y != 0 && game->map[x][y - 1] != '1' && game->map[x][y - 1] != ' ')
		return_invalid_map(game);
	if (game->map[x][y + 1] != '\0' && game->map[x][y + 1] != '1'
		&& game->map[x][y + 1] != ' ')
		return_invalid_map(game);
	if (x != 0)
	{
		len = ft_strlen(game->map[x - 1]);
		if (len >= y + 1)
		{
			if (game->map[x - 1][y] != '\0' && game->map[x - 1][y] != '1'
				&& game->map[x - 1][y] != ' ')
				return_invalid_map(game);
		}
	}
	len = ft_strlen(game->map[x + 1]);
	if (len >= y + 1)
	{
		if (game->map[x + 1][y] != '\0' && game->map[x + 1][y] != '1'
			&& game->map[x + 1][y] != ' ')
			return_invalid_map(game);
	}
}

void	check_first_last_line(t_game *game)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (game->map[0][j])
	{
		if (game->map[0][j] != ' ' && game->map[0][j] != '1')
			return_invalid_map(game);
		j++;
	}
	while (game->map[i])
		i++;
	i--;
	j = 0;
	while (game->map[i][j])
	{
		if (game->map[i][j] != ' ' && game->map[i][j] != '1')
			return_invalid_map(game);
		j++;
	}
}
