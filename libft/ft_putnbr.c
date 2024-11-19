/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:16:04 by asofia-g          #+#    #+#             */
/*   Updated: 2024/03/07 13:50:49 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Devido aos unsigned de u, x e X, o n tem que ser long
int	ft_putnbr(long n, char *basecode, int base)
{
	int		len;
	long	copy;

	copy = n;
	len = (n <= 0);
	copy = n * ((n > 0) - (n < 0));
	while (copy > 0)
	{
		copy = copy / base;
		len++;
	}
	if (n < 0)
	{
		ft_putstr("-");
		ft_putnbr(-n, basecode, base);
	}
	else if (n > base - 1)
	{
		ft_putnbr(n / base, basecode, base);
		ft_putnbr(n % base, basecode, base);
	}
	else
		ft_putchar(basecode[n]);
	return (len);
}

//Para interpretar o argumento como um endereço, precisamos de um 
//unsigned long long e assim não dá para usar o ft_putnbrlen, pois
//o tipo de variável foi alterado
int	ft_putnbr_pointer(unsigned long long n, char *basecode,
	unsigned int base)
{
	unsigned long long	copy;
	unsigned long long	len;

	copy = n;
	len = 0;
	while (copy > 0)
	{
		copy = copy / base;
		len++;
	}
	if (n > base - 1)
	{
		ft_putnbr(n / base, basecode, base);
		ft_putnbr(n % base, basecode, base);
	}
	else
		ft_putchar(basecode[n]);
	return (len);
}

//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf("\n%d",ft_putnbr(ft_atoi(argv[1]), argv[2], ft_atoi(argv[3])));
//	ft_putnbr(ft_atoi(argv[1]));
}
*/
//end test
