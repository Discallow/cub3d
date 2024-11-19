/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asofia-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:26:45 by asofia-g          #+#    #+#             */
/*   Updated: 2023/11/22 17:39:03 by asofia-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
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
}
//test
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	ft_putstr_fd(argv[1], ft_atoi(argv[2]));
}
*/
//end test
