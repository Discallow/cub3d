/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:42:10 by asofia-g          #+#    #+#             */
/*   Updated: 2023/11/26 19:09:09 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_match(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	j = 0;
	aux = (char *)s1;
	while (set[j] != '\0')
	{
		while (aux[i] != set[j] && set[j] != '\0')
			j++;
		if (set[j] == '\0')
			return (i);
		i++;
		j = 0;
	}
	return (i);
}

int	ft_rmatch(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*aux;

	i = ft_strlen(s1) - 1;
	j = 0;
	aux = (char *)s1;
	while (set[j] != '\0')
	{
		while (aux[i] != set[j] && set[j] != '\0')
			j++;
		if (set[j] == '\0')
			return (i);
		i--;
		j = 0;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*s1 == '\0')
		trim = ft_calloc(1, 1);
	else
	{
		i = ft_match(s1, set);
		j = ft_rmatch(s1, set);
		if (j < 0 || j - i + 1 < 0)
			trim = ft_calloc(1, 1);
		else
			trim = ft_substr(s1, i, j - i + 1);
	}
	return (trim);
}
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf ("%s",ft_strtrim(argv[1], argv[2]));
}
*/
//end test
