/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:52:15 by asofia-g          #+#    #+#             */
/*   Updated: 2024/08/31 12:53:08 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	size_t	j;

	j = 0;
	if (!s)
		return (NULL);
	duplicate = (char *)malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	while (j < ft_strlen(s))
	{
		duplicate[j] = s[j];
		j++;
	}
	duplicate[j] = '\0';
	return (duplicate);
}
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf ("%s\n", ft_strdup(argv[1]));
}
*/
//end test
