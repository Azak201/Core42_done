#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <unistd.h>
void	ft_bzero(void *s, size_t n);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*strrchr(const char *s, int c);
int	ft_tolower(int c);
int	ft_toupper(int c);

#endif
