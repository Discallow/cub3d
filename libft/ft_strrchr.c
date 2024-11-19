/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:41:07 by asofia-g          #+#    #+#             */
/*   Updated: 2023/11/07 15:08:37 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	while (i >= 0)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s--;
		i--;
	}
	return (NULL);
}
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf ("Resultado com strrchr: %s\n", strrchr(argv[1], 'e' + 256));
	printf ("Resultado com ft_strrchr: %s\n", ft_strrchr(argv[1], 'e' + 256));
	printf ("Resultado com strrchr: %s\n", strrchr(argv[1], argv[2][0]));
	printf ("Resultado com ft_strrchr: %s\n", ft_strrchr(argv[1], argv[2][0]));
}
*/
//end test
