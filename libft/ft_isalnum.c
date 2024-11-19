/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:54:48 by asofia-g          #+#    #+#             */
/*   Updated: 2023/10/03 17:46:08 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1);
	return (0);
}
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf("Resultado com isalnum: %d\n", isalnum(argv[1][0]));
	printf("Resultado com ft_isalnum: %d\n", ft_isalnum(argv[1][0]));
}
//end test
*/
