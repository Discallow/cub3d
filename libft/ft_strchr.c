/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:21:39 by asofia-g          #+#    #+#             */
/*   Updated: 2023/11/07 15:08:24 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(s);
	while (i <= l)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
		i++;
	}
	return (NULL);
}
//EXPLICACAO
//ha que usar unsigned para ter uma gama de caracteres disponiveis maior
//
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf ("Resultado com strchr: %s\n", strchr(argv[1], 'e' + 256));
	printf ("Resultado com ft_strchr: %s\n", ft_strchr(argv[1], 'e' + 256));
	printf ("Resultado com strchr: %s\n", strchr(argv[1], argv[2][0]));
	printf ("Resultado com ft_strchr: %s\n", ft_strchr(argv[1], argv[2][0]));
}
*/
//end test
