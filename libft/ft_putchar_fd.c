/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:13:07 by asofia-g          #+#    #+#             */
/*   Updated: 2023/11/22 17:39:53 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write (fd, &c, 1);
}
//man 2 write
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	ft_putchar_fd(argv[1][0],ft_atoi(argv[2]));
}
*/
//end test
