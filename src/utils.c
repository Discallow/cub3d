/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:53:51 by discallow         #+#    #+#             */
/*   Updated: 2024/12/03 12:17:28 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	skip_spaces(char *line, size_t *i)
{
	size_t	index;

	index = *i;
	while (line[index] && ft_isspace(line[index]))
		index++;
	*i = index;
}

int	ft_atoi2(const char *s)
{
	int	result;
	int	i;
	int	size;

	i = 0;
	result = 0;
	size = 0;
	while (ft_isspace(s[i]))
		i++;
	while (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (size > 4 && result > 255)
			return (-1);
		result = result * 10 + (s[i] - '0');
		i++;
		size++;
	}
	while (ft_isspace(s[i]))
		i++;
	if (result > 255 || result < 0 || s[i] || size == 0)
		return (-1);
	return (result);
}

char	*ft_strjoin3(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	j = 0;
	buffer = ft_calloc(sizeof(char *), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!buffer)
		return (NULL);
	while (s1 && s1[i])
	{
		buffer[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		buffer[i + j] = s2[j];
		j++;
	}
	if (s1)
		free(s1);
	return (buffer);
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
	if ((str1[i] && str1[i] != 'b')
		|| (str1[i - 1] && str1[i - 1] != 'u')
		|| (str1[i - 2] && str1[i - 2] != 'c')
		|| (str1[i - 3] && str1[i - 3] != '.'))
		return (0);
	return (1);
}
