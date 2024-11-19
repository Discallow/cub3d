/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:27:08 by asofia-g          #+#    #+#             */
/*   Updated: 2023/10/31 19:01:24 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf ("Resutado com toupper: %d\n", toupper(atoi(argv[1])));
	printf ("Resutado com ft_toupper: %d", ft_toupper(atoi(argv[1]))); 
}
*/
//test
