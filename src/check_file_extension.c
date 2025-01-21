/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:01:40 by discallow         #+#    #+#             */
/*   Updated: 2025/01/21 21:26:02 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_image_extension(t_game *game)
{
	if (game->copy.elements_filled)
	{
		if (ft_strcmp2(game->north.path, ".xpm")
			|| ft_strcmp2(game->south.path, ".xpm")
			|| ft_strcmp2(game->east.path, ".xpm")
			|| ft_strcmp2(game->west.path, ".xpm"))
		{
			printf(RED"Wrong extension file"RESET"\n");
			free_everything(game);
			exit (1);
		}
	}
}

int	check_extension(char *file)
{
	if (ft_strcmp2(file, ".cub"))
	{
		printf(RED"Wrong extension file"RESET"\n");
		return (1);
	}
	return (0);
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

char	*check_name(t_game *game, char *line, char *complete_line)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	while (line[i + j] && !ft_isspace(line[i + j]))
		j++;
	str = ft_substr(line, i, j);
	while (line[i + j] && ft_isspace(line[i + j]))
		j++;
	if (line[i + j])
	{
		if (str)
			free(str);
		return_invalid_line(game, complete_line);
	}
	return (str);
}
