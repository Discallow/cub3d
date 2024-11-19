/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:37:11 by asofia-g          #+#    #+#             */
/*   Updated: 2024/02/25 20:13:58 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	arg;

	va_start(arg, str);
	len = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str != '%')
			len += write(1, str, 1);
		else
			len += ft_printarg(*(++str), arg);
		str++;
	}
	va_end(arg);
	return (len);
}
//test
/*
int	main()
{
	char c = 'c';
	char *str = "abc";
//	char *str1 = NULL;
	int i = -234;
	long long l = -ULONG_MAX;

	printf("printf ret;\n");
	int printf_ret = printf("%c, %s, %d, %i, %u, %x, %X, %p, %%\n", 
		c, str, i, i, i, i, i, &l);
	printf("printf ret value: %d;\n", printf_ret);

//	int printf_ret1 = printf(" NULL %s NULL ", str1);
//	printf("printf ret value: %d;\n", printf_ret1);

	printf("ft_printf ret;\n");
	int ft_printf_ret = ft_printf("%c, %s, %d, %i, %u, %x, %X, %p, %%\n", 
		c, str, i, i, i, i, i, &l);
	printf("ft_printf_ret value: %d;\n", ft_printf_ret);

//	int ft_printf_ret1 = ft_printf(" NULL %s NULL ", str1);
//	ft_printf("printf ret value: %d;\n", ft_printf_ret1);
}
*/
/*
int	main(int argc, char* argv[])
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	(void)argc;
	while (argv[2][i] != '\0')
	{
		if (argv[2][i] == '-' || ft_isdigit(argv[2][i]) == 1)
			count = 1;
		else
			count = 0;
		i++;
	}
	if (count == 1 && argv[1][1] == 'd')
	{
		ft_printf("\n%d", ft_printf(argv[1], atoi(argv[2])));
		printf("\nResultado com printf:\n");
		printf("\n%d",printf(argv[1], atoi(argv[2])));
	}
	else
	{
		ft_printf("\n%d", ft_printf(argv[1], argv[2]));
		printf("\nResultado com printf:\n");
		printf("\n%d",printf(argv[1], argv[2]));
	}
}
*/
///*COMO PRINTF FUNCIONA
//int	main(int argc, char *argv[])
/*{
	int	i;
	i = 0;

	while (++i < argc)
		printf ("arg [%d] = %s \n", i, argv[i]); 
}
*/
//Prints a percent sign.
/*
{
	int	i = 1;

	(void)argc;
	(void)argv;
	int printf_ret = printf ("%d%%%", i);
	printf("\nprintf ret value: %d", printf_ret);
}
*/
