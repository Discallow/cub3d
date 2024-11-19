/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:51:44 by discallow         #+#    #+#             */
/*   Updated: 2024/11/19 22:32:02 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_strcmp2(char *str1)
{
	int	i;

	i = 0;
	if (!str1)
		return (1);
	while (str1[i])
		i++;
	i--;
	if ((str1[i] && str1[i] != 'r') || 
		(str1[i - 1] && str1[i - 1] != 'e') ||
		(str1[i - 2] && str1[i - 1] != 'b') ||
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

void	check_map(t_game *game, char *map)
{
	check_extension(map);
}