/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:51:44 by discallow         #+#    #+#             */
/*   Updated: 2024/11/23 04:41:46 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*O nome deve ser tudo a seguir ao Element, excluindo a newline? like, incluir todos os spaces à frente?*/
void	skip_spaces(char *line, size_t *i)
{
	size_t	index;

	index = *i;
	while (line[index] && ft_isspace(line[index]))
		index++;
	*i = index;
}

char	*check_name(char *line)
{
	int	i;
	char	*str;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	//printf("line here:%s", line + i);
	str = ft_substr(line, i, ft_strlen(line) - i - NEWLINE);
	printf("str:|%s|\n", str);
	return (str);
}

bool	check_elements_filled(t_game *game)
{
	if (game->north.path && game->south.path && game->east.path
		&& game->west.path && game->floor.path && game->ceiling.path)
		return (true);
	return (false);
}

/* char	*check_rgb_value(char *line, int element)
{
	return (line);
} */

void	check_valid_element(char *line, t_game *game)
{
	int	i;

	i = 0;
	if (check_elements_filled(game))
	{
		game->elements_filled = true;
		return ;
	}
	while (line[i] && !ft_isspace(line[i]))
		i++;
	if ((line[i] != 'C' || line[i] != 'F') && i < 2)
		i = 2;
	if (!ft_strncmp(line, "NO", i) && !game->north.path)
		game->north.path = check_name(line + i);
	else if (!ft_strncmp(line, "SO", i) && !game->south.path)
		game->south.path = check_name(line + i);
	else if (!ft_strncmp(line, "EA", i) && !game->east.path)
		game->east.path = check_name(line + i);
	else if (!ft_strncmp(line, "WE", i) && !game->west.path)
		game->west.path = check_name(line + i);
 	else if (!ft_strncmp(line, "C", i) && !game->ceiling.path)
		game->ceiling.path = check_name(line + i);
	else if (!ft_strncmp(line, "F", i) && !game->floor.path)
		game->floor.path = check_name(line + i);
	else
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("Invalid line: ", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd(RESET, 2);
		free (line);
		exit (1);
	}
}

void	check_valid_line(char *line, t_game *game)
{
	size_t	i;

	i = 0;
	skip_spaces(line, &i);
	if (!line[i])
		return ;
	if (game->elements_filled == false)
		check_valid_element(line + i, game);
}

void	read_file(t_game *game)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
		{
			free(line);
			break ;
		}
		check_valid_line(line, game);
		free(line);
	}
	exit(1);
}

int	ft_strcmp2(char *str1)
{
	int	i;

	i = 0;
	if (!str1)
		return (1);
	while (str1[i])
		i++;
	i--;
	if ((str1[i] && str1[i] != 'b') || 
		(str1[i - 1] && str1[i - 1] != 'u') ||
		(str1[i - 2] && str1[i - 1] != 'c') ||
		(str1[i - 3] && str1[i - 1] != '.'))
		return (1);
	return (0);
}

void	check_extension(char *file)
{
	if (ft_strcmp2(file) == 0)
	{
		write(2, "Wrong extension file\n", 21);
		exit (1);
	}
}

void	open_file(t_game *game, char *file)
{
	game->fd = open(file, O_RDONLY);
	if (game->fd < 0)
	{
		perror("Error opening file");
		exit (1);
	}
}

void	check_map(t_game *game, char *map)
{
	check_extension(map);
	open_file(game, map);
	read_file(game);
	close(game->fd);
}