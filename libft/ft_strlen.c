/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:57:50 by asofia-g          #+#    #+#             */
/*   Updated: 2024/02/14 21:12:37 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf("Resultado com strlen: %lu\n", strlen(argv[1]));
	printf("Resultado com ft_strlen: %zu\n", ft_strlen(argv[1]));
}
//end test
*/
