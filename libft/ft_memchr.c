/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:51:55 by asofia-g          #+#    #+#             */
/*   Updated: 2023/11/07 21:34:06 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*copy_s;
	size_t	i;

	i = 0;
	copy_s = (char *)s;
	while (i < n)
	{
		if ((unsigned char)*copy_s == (unsigned char)c)
			return (copy_s);
		copy_s++;
		i++;
	}
	return (NULL);
}
/*EXPLICACAO
os bytes comecam em 1 nao em 0, nao se limita o while ate ao \0 pois como estamos
a trabalhar com bytes, nao termina no fim da string*/
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf ("Resultado com memchr: ");
	printf("%s\n", (char *)memchr(argv[1], argv[2][0], atoi(argv[3])));
	printf ("Resultado com ft_memchr: ");
	printf ("%s\n", (char *)ft_memchr(argv[1], argv[2][0], atoi(argv[3])));
}
*/
//end test
