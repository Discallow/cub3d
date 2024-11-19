/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:44:48 by asofia-g          #+#    #+#             */
/*   Updated: 2023/10/03 17:54:38 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf("Resultado com isprint: %d\n", isprint(argv[1][0]));
	printf("Resultado com ft_isprint: %d\n", ft_isprint(argv[1][0]));
}
//test no ascii ²
//endtest
*/
