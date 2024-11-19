/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:58:33 by asofia-g          #+#    #+#             */
/*   Updated: 2023/11/22 17:38:16 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (fd < 0)
		return ;
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
	write (fd, "\n", 1);
}
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	ft_putendl_fd(argv[1], ft_atoi(argv[2]));
}
*/
//end test
