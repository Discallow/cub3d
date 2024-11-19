/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-c <asofia-c@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:46:02 by asofia-c          #+#    #+#             */
/*   Updated: 2023/10/21 13:20:16 by asofia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	long unsigned int		aux;
	long unsigned int		i;

	i = 0;
	aux = ft_strlen(src);
	if (size <= 0)
		return (aux);
	while (size > i + 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (aux);
}
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	//printf ("%s","Resultado com strlcpy : ");
	//printf ("%d\n", strlcpy (argv[1], argv[2], argv[3][0]-48));
	printf ("%s", "Resultado com a minha funcao: ");
	printf ("%ld\n", ft_strlcpy (argv[1], argv[2], atoi(argv[3])));
	printf ("Resultado da copia: %s\n", argv[1]);
	printf ("Comprimento da copia: %ld", ft_strlen(argv[1]));
}
*/
//end test
