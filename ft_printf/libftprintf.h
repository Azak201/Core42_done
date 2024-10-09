#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putu_fd(unsigned int n, int fd);
void ft_puthex_fd(unsigned int num, int fd, int flag);

#endif