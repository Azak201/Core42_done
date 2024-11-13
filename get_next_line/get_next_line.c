#include "get_next_line.h"
#include <stdio.h>

static char *longer(int fd);

char *get_next_line(int fd)
{
        char buffer[BUFFER_SIZE];
        char *result = NULL;
        int i;

        i = 0;
        read(fd, buffer, BUFFER_SIZE);
        if (nfinder(buffer) != -1)
        {
                printf("reached if\n");
                i = nfinder(buffer);
                result = ft_substr(buffer, 0, i);
                return (result);
        }
        else
        {
                printf("reached else\n");
                result = ft_strjoin("", buffer);
                printf("the result before longer have :%s\n", result);
                result = ft_strjoin(result, longer(fd));
                printf("else in getnextline finished\n");
                return (result);
        }
        return ("\0");
}

static char *longer(int fd)
{
        printf("call longer\n");
        char buffer[BUFFER_SIZE];
        char *result = "";
        int i;
        read(fd, buffer, BUFFER_SIZE);
        if (nfinder(buffer) != -1)
        {
                printf("reached if in longer\n");
                i = nfinder(buffer);
                result = ft_substr(buffer, 0, i);
                return (result);
        }
        else
        {
                printf("the result now have :%s\n", result);
                while (nfinder(buffer) == -1)
                {
                        result = ft_strjoin(result, buffer);
                        printf("the result now have :%s\n", result);
                        read(fd, buffer, BUFFER_SIZE);
                }
                result = ft_strjoin(result, ft_substr(buffer, 0, nfinder(buffer)));
        }
        printf("longer finished\n");
        return (result);
}