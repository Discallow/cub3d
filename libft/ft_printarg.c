/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:47:55 by asofia-g          #+#    #+#             */
/*   Updated: 2024/03/07 13:50:14 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Para interpretar o argumento como um endereço, precisamos de um 
//unsigned long long
int	point_convertion(va_list arg)
{
	unsigned long long	pointer;

	pointer = va_arg(arg, unsigned long long);
	if (pointer != 0)
		return (ft_putstr("0x") + ft_putnbr_pointer(pointer,
				"0123456789abcdef", 16));
	else
		return (ft_putstr("(nil)"));
}

//va_arg é uma estrutura que trabalha com 4 bits, assim, para os char (1 bit)
//precisamos interpreta-lo como int para considerar 4 bits
int	ft_printarg(char specifier, va_list arg)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(arg, int), "0123456789", 10));
	else if (specifier == 'u')
		return (ft_putnbr(va_arg(arg, unsigned int), "0123456789", 10));
	else if (specifier == 'x')
		return (ft_putnbr(va_arg(arg, unsigned int), "0123456789abcdef",
				16));
	else if (specifier == 'X')
		return (ft_putnbr(va_arg(arg, unsigned int), "0123456789ABCDEF",
				16));
	else if (specifier == 'p')
		return (point_convertion(arg));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}
//EXPLICACAO
//para 'u' tambem funcionaria fazer 
//u = va_arg(arg, int);
//if (u < 0)
//	return (ft_putnbr(u + 4294967296))
