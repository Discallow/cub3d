/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:54:37 by asofia-g          #+#    #+#             */
/*   Updated: 2023/11/08 14:15:13 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*copy_s1;
	char	*copy_s2;
	size_t	i;

	i = 0;
	copy_s1 = (char *)s1;
	copy_s2 = (char *)s2;
	if (n == 0)
		return (0);
	while ((unsigned char)*copy_s1 == (unsigned char)*copy_s2 && i < n)
	{
		if (i + 1 == n)
			return (0);
		copy_s1++;
		copy_s2++;
		i++;
	}
	return ((unsigned char)*copy_s1 - (unsigned char)*copy_s2);
}
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf("Resultado com memcmp: ");
	printf("%d\n", memcmp("test\200", "test\0", 6));
	printf("Resultado com ft_memcmp: ");
	printf("%d\n", ft_memcmp("test\200", "test\0", 6));
	printf("Resultado com memcmp: ");
	printf("%d\n", memcmp(argv[1], argv[2], atoi(argv[3])));
	printf("Resultado com ft_memcmp: ");
	printf("%d\n", ft_memcmp(argv[1], argv[2], atoi(argv[3])));
}
*/
//end test
