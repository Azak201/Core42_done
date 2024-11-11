#include "get_next_line.h"
#include <stdio.h>

static char *longer(int fd);
char *get_next_line(int fd)
{
        char buffer[BUFFER_SIZE];
        char *result = 0;
        int i;

        i = 0;
        read(fd, buffer, BUFFER_SIZE);
        if (nfinder(buffer) != -1)
        {
                printf("reached if");
                i = nfinder(buffer);
                result = ft_substr(buffer, 0, i);
                return (result);
        }
        else
        {
                printf("reached else");
                result = ft_strjoin(result, longer(fd));
        }
        return ("\0");
}

static char *longer(int fd)
{
        char buffer[BUFFER_SIZE];
        char *result;
        int i;

        i = 0;
        while (i < BUFFER_SIZE)
                buffer[i++] = '\0';

        read(fd, buffer, BUFFER_SIZE);
        while (nfinder(buffer))
        {
                read(fd, buffer, BUFFER_SIZE);
                result = ft_strjoin(result, buffer);
        }
        return (result);
}