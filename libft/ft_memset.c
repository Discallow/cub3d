/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:59:22 by asofia-g          #+#    #+#             */
/*   Updated: 2023/10/09 15:48:29 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*copy_s;
	unsigned char	copy_c;
	size_t			i;

	copy_s = (unsigned char *)s;
	copy_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		copy_s[i] = copy_c;
		i++;
	}
	return (s);
}
//EXPLICACAO
//
//na linha 21 uso o endereco de s para poder editar o seu conteudo
//
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf("Resultado com memset: ");
	memset(argv[1], atoi(argv[2]), atoi(argv[3]));
	printf("%s\n",argv[1]);
	printf("Resultado com ft_memset: ");
	ft_memset(argv[1], atoi(argv[2]), atoi(argv[3]));
	printf("%s\n",argv[1]);
}
//end test
*/
