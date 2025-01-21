/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_validate_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 05:49:29 by discallow         #+#    #+#             */
/*   Updated: 2025/01/21 22:50:18 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_one_or_space(t_game *game, int i)
{
	int			len;
	static int	flag = 0;

	len = ft_strlen(game->map[i]);
	if (len > game->copy.max_width)
		game->copy.max_width = len;
	if (flag == 0)
		check_first_last_line(game);
	flag = 1;
	if ((game->map[i][0] != ' ' && game->map[i][0] != '1')
		|| (game->map[i][len - 1] != ' ' && game->map[i][len - 1] != '1'))
		return_invalid_map(game);
}

static void	check_valid_char(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
		|| game->map[i][j] == 'W' || game->map[i][j] == 'E')
	{
		game->copy.player_num++;
		game->player.dir = game->map[i][j];
		game->player.x = j + 0.5;
		game->player.y = i + 0.5;
	}
	else if (game->map[i][j] == ' ')
		check_borders(game, i, j);
	else if (BONUS && game->map[i][j] == 'X')
	{
		game->copy.enemy_num++;
		game->enemy.x = j + 0.5;
		game->enemy.y = i + 0.5;
	}
	else if (BONUS && game->map[i][j] == 'P')
		;
	else if (game->map[i][j] != '1' && game->map[i][j] != '0')
		return_invalid_map(game);
}

static void	validate_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map && game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			check_one_or_space(game, i);
			check_valid_char(game, i, j);
			j++;
		}
		game->copy.max_height++;
		i++;
	}
	if (game->copy.player_num != 1 || game->copy.enemy_num != 1)
		return_invalid_number_players(game);
}

static void	check_valid_map(char *line, t_game *game)
{
	static int	flag = 0;
	size_t		i;

	i = 0;
	skip_spaces(line, &i);
	if (!line[i])
	{
		if (flag)
			check_map_end(game, line);
		return ;
	}
	if (!flag)
		flag = 1;
	game->copy.map_joined = ft_strjoin3(game->copy.map_joined, line);
}

void	read_map(t_game *game)
{
	char	*line;

	line = NULL;
	while (1)
	{
		if (game->copy.map_read)
			break ;
		line = get_next_line(game->fd);
		if (!line)
		{
			free(line);
			break ;
		}
		game->copy.line_index++;
		check_valid_map(line, game);
		free(line);
	}
	if (!game->copy.map_joined)
		return_invalid_map(game);
	game->map = ft_split2(game->copy.map_joined, '\n');
	validate_map(game);
}
