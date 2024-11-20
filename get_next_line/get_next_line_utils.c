#include "get_next_line.h"
#include <stdio.h>

size_t ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	int len1;
	int len2;
	char *str;
	char *pt;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	pt = str;
	while (*s1 != '\0')
		*pt++ = *s1++;
	while (*s2 != '\0')
		*pt++ = *s2++;
	*pt = 0;
	return (str);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;
	char *substr;
	char *dup;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	dup = (char *)(s + start);
	if (ft_strlen(dup) < len)
		len = ft_strlen(dup);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	substr = sub;
	while (*dup != '\0' && len > 0)
	{
		*sub++ = *dup++;
		len--;
	}
	*sub = '\0';
	return (substr);
}

char *ft_strdup(char *src)
{
	char *x;
	int i;

	i = 0;
	x = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	if (!x)
		return (NULL);
	while (src[i])
	{
		x[i] = src[i];
		i++;
	}
	x[i] = '\0';
	return (x);
}

char *ft_strchr(const char *s, int c)
{
	const char *p;

	p = s;
	while (*p != 0)
	{
		if (*p == (char)c)
			return ((char *)p);
		p++;
	}
	if ((char)c == '\0')
		return ((char *)p);
	return (NULL);
}

/*void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n)
	{
		*ptr = (char)c;
		ptr++;
		n--;
	}
	return (s);
}*/