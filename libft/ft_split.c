#include "libft.h"
static countword(char *str, char del)
{
    int c;
    int i;

    c = 0;
    i = 0;
    if (!*str)
        return (0);
    while (str[i] != '\0')
    {
        while (str[i] == c)
            i++;
        if (str[i] != '\0')
            c++;
        while (str[i] != c && str[i] != '\0')
            i++;
    }
    return (c);
}

char **ft_split(char const *s, char c)
{
    char **spstr;
    int count;
    size_t wlen;

    spstr = (char **)malloc(sizeof(char *) * (countword(s, c) + 1));
    if (!s || !spstr)
        return (NULL);
    count = 0;
    while (*s != '\0')
    {
        while (*s == c && *s)
            s++;
        if (*s)
        {
            if (!ft_strchr(s, c))
                wlen = ft_strlen(s);
            else
                wlen = ft_strchr(s, c) - s;
            spstr[count++] = ft_substr(s, 0, wlen);
            s += wlen;
        }
    }
    spstr[count] = NULL;
    return (spstr);
}
int main()
{
}