/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-c <asofia-c@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:09:31 by asofia-c          #+#    #+#             */
/*   Updated: 2023/10/31 18:01:28 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	i = 0;
	if (size <= dst_len)
		return (ft_strlen(src) + size);
	while (i < size - dst_len - 1 && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + ft_strlen(src));
}
//EXPLICACAO
//so pode concatenar size-strlen(dst)-1 carateres
//
//test
/* 
int	main(int argc, char *argv[])
{
	(void)argc;
	printf ("%s", "Resultado com a minha funcao : ");
	printf ("%ld\n", ft_strlcat (argv[1], argv[2], atoi(argv[3])));
	printf ("%s", argv[1]);
}
*/
//end test
