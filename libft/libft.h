/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:51:18 by asofia-c          #+#    #+#             */
/*   Updated: 2024/09/30 17:50:19 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//<stdarg.h> is the library to va_arg
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

//LIBC FUNCTIONS

int			ft_isalpha(int c);//1
int			ft_isdigit(int c);//2
int			ft_isalnum(int c);//3
int			ft_isascii(int c);//4
int			ft_isprint(int c);//5
int			ft_isspace(int c);
size_t		ft_strlen(const char *s);//6
void		*ft_memset(void *s, int c, size_t n);//7
void		ft_bzero(void *s, size_t n);//8
void		*ft_memcpy(void *dest, const void *src, size_t n);//9
void		*ft_memmove(void *dest, const void *src, size_t n);//10
size_t		ft_strlcpy(char *dst, const char *src, size_t size);//11
size_t		ft_strlcat(char *dst, const char *src, size_t size);//12
int			ft_toupper(int c);//13
int			ft_tolower(int c);//14
char		*ft_strchr(const char *s, int c);//15
char		*ft_strrchr(const char *s, int c);//16
int			ft_strcmp(char *str1, char *str2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);//17
void		*ft_memchr(const void *s, int c, size_t n);//18
int			ft_memcmp(const void *s1, const void *s2, size_t n);//19
char		*ft_strnstr(const char *big, const char *little, size_t len);//20
int			ft_atoi(const char *nptr);//21
long long	ft_atol(const char *nptr);
long		ft_atoil(const char *nptr);//21 modifie
void		*ft_calloc(size_t nmemb, size_t size);//22
char		*ft_strdup(const char *s);//23

//ADDITIONAL FUNCTIONS

char		*ft_substr(char const *s, unsigned int start, size_t len);//24
char		*ft_strjoin(char *s1, char *s2);//25
char		*ft_strtrim(char const *s1, char const *set);//26
char		**ft_split(char const *s, char c);//27
char		*ft_itoa(int n);//28
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));//29
void		ft_striteri(char *s, void (*f)(unsigned int, char*));//30
void		ft_putchar_fd(char c, int fd);//31
void		ft_putstr_fd(char *s, int fd);//32
void		ft_putendl_fd(char *s, int fd);//33
void		ft_putnbr_fd(int n, int fd);//34

//PRINTF FUNCTIONS
int			ft_putchar(char c);//1
int			ft_putstr(char *str);//2
int			ft_putnbr_pointer(unsigned long long n, char *basecode,
				unsigned int base);//3
int			ft_putnbr(long n, char *basecode, int base);//4, 5, 6, 7 e 6
int			ft_printarg(char str, va_list arg);
int			ft_printf(const char *str, ...);

#endif
