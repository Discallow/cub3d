/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:30:46 by asofia-g          #+#    #+#             */
/*   Updated: 2024/09/10 16:55:58 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>//library that contains open
# include <stdlib.h>
# include <fcntl.h>//library that contains flags to open

char	*get_next_line(int fd);
void	ft_clean_buffer(char *str);

//as this if is inside another one need doble tab
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
