/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:41:53 by asofia-g          #+#    #+#             */
/*   Updated: 2023/11/08 16:27:32 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *)big);
	if (*big == '\0')
		return (NULL);
	while (i < len && (*big != '\0' || little[j] != '\0'))
	{
		while (big[j] == little[j] && (i + j) < len && little[j] != '\0')
			j++;
		if (little[j] == '\0')
			return ((char *)big);
		j = 0;
		i++;
		big++;
	}
	return (NULL);
}
//test
/*
int	main(int argc, char*argv[])
{
	(void)argc;
//	printf("Resultado com strnstr:");
//	printf("%s", strnstr(argv[1], argv[2], atoi(argv[3])));
	printf("Resultado com ft_strnstr:");
	printf("%s", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
}
*/
//end test
