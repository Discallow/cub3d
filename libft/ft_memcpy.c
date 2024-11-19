/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:15:33 by asofia-g          #+#    #+#             */
/*   Updated: 2023/10/09 17:52:54 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*copy_dest;
	unsigned char	*copy_src;
	size_t			i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	copy_dest = (unsigned char *)dest;
	copy_src = (unsigned char *)src;
	while (i < n)
	{
		copy_dest[i] = copy_src[i];
		i++;
	}
	return (dest);
}
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf("Resultado com memcpy: ");
	memcpy(argv[1], argv[2], atoi(argv[3]));
	printf("%s\n",argv[1]);
	printf("Resultado com ft_memcpy: ");
	ft_memcpy(argv[1], argv[2], atoi(argv[3]));
	printf("%s\n",argv[1]);
	printf("NULLOS: ");
	printf("Resultado com ft_memcpy: ");
	ft_memcpy((NULL), (NULL), atoi(argv[3]));
}
//end test
*/
