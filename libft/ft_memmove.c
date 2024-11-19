/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:01:19 by asofia-g          #+#    #+#             */
/*   Updated: 2023/11/17 20:27:45 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*copy_dest;
	unsigned char	*copy_src;

	if (!dest && !src)
		return (NULL);
	copy_dest = (unsigned char *)dest;
	copy_src = (unsigned char *)src;
	if (copy_dest < copy_src)
		ft_memcpy(dest, src, n);
	else if (copy_dest > copy_src)
	{
		while (n > 0)
		{
			copy_dest[n - 1] = copy_src[n - 1];
			n--;
		}
	}
	return (dest);
}
//test
//EXPLICACAO na linha 24 (copy_dest < copy_src) garante que nao ha sobreposicao
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf("Resultado com memmove: ");
	memmove(argv[1], argv[2], atoi(argv[3]));
	printf("%s\n",argv[1]);
	printf("Resultado com ft_memmove: ");
	ft_memmove(argv[1], argv[2], atoi(argv[3]));
	printf("%s\n",argv[1]);
	printf("NULLOS: ");
	printf("Resultado com ft_memmove: ");
	ft_memmove((NULL), (NULL), atoi(argv[3]));
}
//end test
*/
