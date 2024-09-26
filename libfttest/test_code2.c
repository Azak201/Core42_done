#include "libft.h"
char f(unsigned int i, char c)
{
    printf("%d ", i);
    return ft_toupper(c);
}

/*void f(unsigned int i, char *c)
{
    printf("%d ", i);
    *c = ft_toupper(*c);
}*/

int main()
{
    printf("\n\n######################################################################\n\n\n");
    printf("part 2 functions test");
    printf("\n\n######################################################################\n\n\n");

    printf("substr \n");
    char a[20] = "amjed test the loc";
    char *b;

    b = ft_substr(a, 2, 10);
    printf("the str:%s sub from 2 and size 10 :%s|%p\n", a, b, b);
    b = ft_substr(a, 2, 2);
    printf("the str:%s sub from 2 and size 2 :%s|%p\n", a, b, b);
    b = ft_substr(a, 25, 10);
    printf("the str:%s sub from 25 and size 10 :%s|%p\n", a, b, b);
    free(b);
    printf("\n\n######################################################################\n\n\n");

    printf("strjoin\n");

    char *str1 = "hello my test";
    char *str2 = " worldthis is my codde";
    char *result;

    result = ft_strjoin(str1, str2);
    printf("joining two strings first :%s\t sec:%s\nthe result: %s\n", str1, str2, result);
    free(result);

    printf("\n\n######################################################################\n\n\n");
    printf("strtrim \n");

    char test[30] = " ***+*a*mjed tes*t *   =*";
    char *tremmed;
    tremmed = ft_strtrim(test, " *+=");
    printf("the str:%s\tthe set:%s\nthe trimmed str:%s\n", test, " *+=", tremmed);
    free(tremmed);

    printf("\n\n######################################################################\n\n\n");
    printf("split \n");

    char str[] = "Hello,world,this,is,a,test";
    char delimiter = ',';
    char **result2 = NULL;
    result2 = ft_split(str, delimiter);
    if (result2 == NULL)
    {
        printf("Error: Memory allocation failed or empty string\n");
        return (1);
    }
    printf("the str before the split : %s\n", str);
    for (int i = 0; result2[i] != NULL; i++)
    {
        printf("Word %d: %s\n", i, result2[i]);
        free(result2[i]);
    }
    free(result2);
    printf("\n\n######################################################################\n\n\n");
    printf("itoa function \n");

    int i = 0;
    int a1[6] = {53727, -155, 634527, 0, -2147483648, 2147483647};
    printf("the a1[6]={53727,-155,634527,0,-2147483648,2147483647}; \n");
    while (i <= 5)
    {
        printf("%s \n", ft_itoa(a1[i]));
        i++;
    }

    printf("\n\n######################################################################\n\n\n");
    printf("strmapi \n");
    char s[] = "this is test for strmapi";
    char *x = ft_strmapi(s, f);
    printf("the str: %s\t new str:%s \n", s, x);
    free(x);
    printf("\n\n######################################################################\n\n\n");
    printf("striteri ||| the comments remove the \n");
    // ft_striteri(s, f);
    // printf("new str:%s \n", s);

    printf("\n\n######################################################################\n\n\n");
    printf("put__fd\n");
    ft_putchar_fd('a', 1);
    ft_putstr_fd("amjed", 1);
    ft_putendl_fd("ismail and my age is", 1);
    ft_putnbr_fd(23, 1);
    return 0;
}