#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
        int fd;
        char *str;

        fd = 0;

        str = get_next_line(fd);
        printf("<%s>", str);
        free(str);


        close(fd);
        return (0);
}
