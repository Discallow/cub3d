/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:37:45 by asofia-g          #+#    #+#             */
/*   Updated: 2023/10/09 13:17:18 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf("Resultado com bzero: ");
	bzero(argv[1], atoi(argv[2]));
	printf("%s\n",argv[1]);
	printf("Resultado com ft_bzero: ");
	ft_bzero(argv[1], atoi(argv[2]));
	printf("%s\n",argv[1]);
}
//end test
*/
