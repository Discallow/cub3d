/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:33:17 by asofia-c          #+#    #+#             */
/*   Updated: 2024/12/02 12:10:48 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s && s[i] != '\0')
	{
		k = 0;
		while (s[i] == c && s[i] != '\0')
		{
			i++;
			k++;
		}
		if (s[i] != '\0')
			j++;
		if (k > 1)
			return (0);
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	if (j != 3)
		return (0);
	return (j);
}

void	*ft_clear(int i, char **ptrarraychar)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free (ptrarraychar[j]);
		j++;
	}
	free (ptrarraychar);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		l;
	int		i;
	char	**ptrarraychar;

	l = 0;
	j = -1;
	if (ft_count(s, c) == 0)
		return (NULL);
	ptrarraychar = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	ptrarraychar[ft_count(s, c)] = NULL;
	while (++j < ft_count(s, c) && s[l] != '\0')
	{
		while (s[l] == c)
			l++;
		i = 0;
		while (s[l + i] != '\0' && s[l + i] != c)
			i++;
		ptrarraychar[j] = ft_substr(s, l, i);
		if (!ptrarraychar[j])
			return (ft_clear (j, ptrarraychar));
		l = l + i;
	}
	return (ptrarraychar);
}

//test
/*
int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	(void)argc;
	//printf ("String trimed: %s\n",ft_strtrim(argv[1], &argv[2][0]));
	//printf ("Quantidade de strings: ");
	//printf ("%d\n",ft_count(ft_strtrim(argv[1], &argv[2][0]), argv[2][0]));
	printf ("Quantidade de strings: %d\n",ft_count(argv[1], argv[2][0]));
	while (ft_split(argv[1], argv[2][0])[i] != NULL)
	{
		printf ("ft_split[%d", i);
		printf ("] %s\n", ft_split(argv[1], argv[2][0])[i]);
		i++;
	}
}
*/
//end test
