#include "get_next_line.h"
#include <stdio.h>

static char *readline(int fd, char *line);
static char *splitter(char *str, char *reminder);
static char *line(char *line);
static char *ft_free(char *f1, char *f2, char *f3);

char *get_next_line(int fd)
{
    static char *reminder = NULL;
    char *str;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    if (reminder)
    {
        str = ft_strdup(reminder);
        if (!str)
            return (ft_free(str, NULL, NULL));
        free(reminder);
        reminder = NULL;
    }
    else
        str = ft_strdup("");
    if (!str)
        return (NULL);
    str = readline(fd, str);
    if (!str)
        return (NULL);
    if (str[0] == '\0')
        return (ft_free(str, NULL, NULL));
    reminder = splitter(str, reminder);
    str = line(str);
    return (str);
}

char *readline(int fd, char *line)
{
    ssize_t r;
    char buffer[BUFFER_SIZE + 1];
    int i;

    i = 0;
    while (i <= BUFFER_SIZE)
        buffer[i++] = '\0';
    if (!line)
        return (NULL);
    r = read(fd, buffer, BUFFER_SIZE);
    if (r > 0)
        buffer[r] = '\0';
    else
        buffer[0] = '\0';
    while (1)
    {
        if (r != 0)
            line = ft_strjoin(line, buffer);
        if (!line)
            return (ft_free(line, NULL, NULL));
        if (ft_strchr(buffer, '\n') || r == 0)
            break;
        r = read(fd, buffer, BUFFER_SIZE);
    }
    return (line);
}

char *splitter(char *str, char *reminder)
{
    int i;

    i = 0;
    while (str[i] != '\n' && str[i])
        i++;
    if (i != -1)
    {
        reminder = ft_substr(str, i + 1, ft_strlen(str));
        if (!reminder)
            return (ft_free(reminder, NULL, NULL));
    }
    else
        reminder = NULL;
    return (reminder);
}

static char *line(char *line)
{
    int i;
    char *temp;

    i = 0;
    while (line[i] != '\n' && line[i])
        i++;
    if (line[i] == '\n')
    {
        temp = ft_substr(line, 0, (i + 1));
        if (!temp)
            return (ft_free(line, NULL, NULL));
        ft_free(line, NULL, NULL);
        line = temp;
    }
    return (line);
}

static char *ft_free(char *f1, char *f2, char *f3)
{
    if (f1)
        free(f1);
    if (f2)
        free(f2);
    if (f3)
        free(f3);
    return (NULL);
}