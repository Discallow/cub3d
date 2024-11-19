/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:03:29 by asofia-g          #+#    #+#             */
/*   Updated: 2023/10/03 14:52:21 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
//test
/*
int	main( int argc, char *argv[])
{
	(void)argc;
	printf("Resultado com isacii: %d\n", isascii(argv[1][0]));
	printf("Resultado com ft_isascii: %d\n", ft_isascii(argv[1][0]));
}
//test no ascii ²
//end test
*/
