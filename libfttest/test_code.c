#include "libft.h"
#include <string.h>
int main()
{
    printf("this is a test for my libft functions. \n\t part1 libic function \n\n");
    printf("\n\n######################################################################\n\n\n");
    printf("is_ functions  \nis digit: \n \'5\': %d\t \'a\': %d\t  \'A\': %d\t int 9: %d \n", ft_isdigit('5'), ft_isdigit('a'), ft_isdigit('A'), ft_isdigit(9));
    printf("is alpha: \n \'5\': %d\t \'a\': %d\t  \'A\': %d\t int 9: %d \n", ft_isalpha('5'), ft_isalpha('a'), ft_isalpha('A'), ft_isalpha(9));
    printf("is alnum: \n \'5\': %d\t \'a\': %d\t  \'A\': %d\t int 9: %d \n", ft_isalnum('5'), ft_isalnum('a'), ft_isalnum('A'), ft_isalnum(9));
    printf("is print: \n \'5\': %d\t \'a\': %d\t  \'A\': %d\t int 9: %d \n", ft_isprint('5'), ft_isprint('a'), ft_isprint('A'), ft_isprint(9));
    printf("is ascii: \n \'5\': %d\t \'a\': %d\t  129: %d\t int 9: %d \n", ft_isascii('5'), ft_isascii('a'), ft_isascii(129), ft_isascii(9));

    printf("\n\n######################################################################\n\n\n");

    printf("\n\n memory functions test\n");
    printf("\n\n######################################################################\n\n\n");
    int A[10];
    ft_bzero(A, 40);
    printf("ft_bzero for int A[10] \n");
    for (int i = 0; i < 10; i++)
        printf("A[%d] : %d \t", i, A[i]);
    printf("\n");

    int B[10];
    bzero(B, 40);
    printf("orginal bzero for int B[10] \n");
    for (int i = 0; i < 10; i++)
        printf("B[%d] : %d \t", i, B[i]);
    printf("\n\n");

    char C[10];
    ft_bzero(C, 10);
    printf("ft_bzero for char C[10] \n");
    for (int i = 0; i < 10; i++)
        printf("C[%d] : %d \t", i, C[i]);
    printf("\n");

    char D[10];
    bzero(D, 10);
    printf("orginal bzero for char D[10] \n");
    for (int i = 0; i < 10; i++)
        printf("D[%d] : %d \t", i, D[i]);

    printf("\n\n######################################################################\n\n\n");

    char str[10];
    ft_memset(str, 'A', 10);
    printf("ft_memset \'A\' for char str[10] \n");
    printf("the seted str is : %s\n", str);

    char str2[10];
    memset(str2, 'A', 10);
    printf("orginal memset \'A\' for char str2[10] \n");
    printf("the seted str is : %s\n\n", str2);

    ft_memset(A, 0, 40);
    printf("ft_memset 0 for int A[10] \n");
    for (int i = 0; i < 10; i++)
        printf("A[%d] : %d \t", i, A[i]);
    printf("\n");

    memset(B, 0, 40);
    printf("orginal memset 0 for int B[10] \n");
    for (int i = 0; i < 10; i++)
        printf("A[%d] : %d \t", i, B[i]);

    printf("\n\n######################################################################\n\n\n");

    char memcp[20] = "amjed ismail";
    char cpy[20];
    printf("ft_memcpy test \n");
    printf("memcpy(cpy,memcp,7) result: \n");
    printf("src: %s\t returned: %p  dest: %s \n\n", memcp, ft_memcpy(cpy, memcp, 7), cpy);

    printf("\n\n######################################################################\n\n\n");

    char memmv[30] = "0123456789st for the memmove";
    char memmv2[30] = "0123456789st for the memmove";
    printf("memmove test : \nmemmove(memmv + 9,memv,13) result: \n\n");
    printf("befor edit memmv: %s\n", memmv);
    printf("returned: %p  memmv: %s \n\nthe deffernce between it and memcpy\n", ft_memmove(memmv + 9, memmv, 13), memmv);
    printf("befor edit memmv2: %s\n", memmv2);
    printf("memcpy(memmv + 9,memv,13) result: \n");
    printf("returned: %p  memmv2: %s \n\n", ft_memcpy(memmv2 + 9, memmv2, 13), memmv2);

    printf("\n\n######################################################################\n\n\n");

    printf("memchr test\n");
    char *memch = ft_strdup("this is my test for memchr");
    char *memch2 = (char *)ft_memchr(memch, 'i', 5);

    printf("the str is: %s\nthe first 'i' found in first 5 element is: %s\n\n", memch, memch2);
    memch2 = (char *)ft_memchr(memch, ' ', 4);
    printf("the str is: %s\nthe first ' ' found in first 4 element is: %s\n", memch, memch2);
    free(memch);
    free(memch2);

    printf("\n\n######################################################################\n\n\n");

    printf("memcmp test\n");
    char memcmp[20] = "AMJEDismail";
    char memcmp2[20] = "AMJEDISMAIL";
    printf("str1 = %s\t str2:%s\n", memcmp, memcmp2);
    printf("1 vs 2  size (4): %d\n", ft_memcmp(memcmp, memcmp2, 4));
    printf("1 vs 2  size (6): %d\n", ft_memcmp(memcmp, memcmp2, 6));
    printf("2 vs 1  size (7): %d\n", ft_memcmp(memcmp2, memcmp, 7));
    printf("1 vs 1  size (4): %d\n", ft_memcmp(memcmp, memcmp, 4));

    printf("\n\n######################################################################\n\n\n");

    printf("string funcions test ");

    printf("\n\n######################################################################\n\n\n");

    printf("ft_strlen  + ft_toupper + ft_tolower\t for array x\n");
    char x[22] = "amJed ZAkaRia IsMail";
    printf("str: %s\t the length: %ld\t first char toupper: %c\t first char tolower:%c\n", x, ft_strlen(x), ft_toupper(x[0]), ft_tolower(x[0]));

    printf("\n\n######################################################################\n\n\n");
    printf("strchr\t +\t strrchr\n\n");
    char strchr[50] = "this is a test for the strchr and strrchr";
    char strc[7] = "thisis";
    printf("the str is : %s\t find first 's':%s \n", strchr, ft_strchr(strchr, 's'));
    printf("the str:%s\t len : %ld\t the str addres is : %p\t address of find '\\0' in strchr:%p\n", strc, ft_strlen(strc), &strchr, ft_strchr(strchr, '\0'));
    printf("the str is : %s\t find last 's':%s\n", strchr, ft_strrchr(strchr, 's'));
    printf("the str:%s\t len : %ld\t the str addres is : %p\t address of find 'g' in strchr:%p\n", strc, ft_strlen(strc), &strchr, ft_strchr(strchr, 'g'));

    printf("\n\n######################################################################\n\n\n");
    printf("strncmp test\n");

    printf("str1 = %s\t str2:%s\n", memcmp, memcmp2);
    printf("1 vs 2  size (4): %d\n", ft_strncmp(memcmp, memcmp2, 4));
    printf("1 vs 2  size (6): %d\n", ft_strncmp(memcmp, memcmp2, 6));
    printf("2 vs 1  size (7): %d\n", ft_strncmp(memcmp2, memcmp, 7));
    printf("1 vs 1  size (4): %d\n", ft_strncmp(memcmp, memcmp, 4));

    printf("\n\n######################################################################\n\n\n");

    printf("strnstr test \n");
    char Astr[50] = "this another test for the str functions";
    printf("the str: %s \n find \"another\" in first 20 element : %s\n", Astr, ft_strnstr(Astr, "another", 20));
    printf("the str: %s \n find \"another\" in first 10 element : %s\n", Astr, ft_strnstr(Astr, "another", 10));
    printf("the str: %s \n find \"\\0\" in first 10 element : %s\n", Astr, ft_strnstr(Astr, "", 10));

    printf("\n\n######################################################################\n\n\n");
    printf("strlcpy \n");
    char strcp[50] = "this str is for the test of strlcpy";
    char strcp2[50];
    printf("size 5 the str : %s\t the return: %ld\t the dest:%s\t\n", strcp, ft_strlcpy(strcp2, strcp, 5), strcp2);
    printf("size 10 the str : %s\t the return: %ld\t the dest:%s\t\n", strcp, ft_strlcpy(strcp2, strcp, 10), strcp2);
    printf("size 0 the str : %s\t the return: %ld\t the dest:%s\t\n", strcp, ft_strlcpy(strcp2, strcp, 0), strcp2);

    printf("\n\n######################################################################\n\n\n");
    printf("strlcat \n");
    char strlc[50] = "lcat test";

    printf("the str : %s\tthedest:%s\nsize 10 the return: %ld\t the dest:%s\t\n", strcp, strlc, ft_strlcat(strlc, strcp, 10), strlc);
    printf("size 5 the str : %s\t the return: %ld\t the dest:%s\t\n", strcp, ft_strlcat(strlc, strcp, 5), strlc);
    printf("size 0 the str : %s\t the return: %ld\t the dest:%s\t\n", strcp, ft_strlcat(strlc, strcp, 0), strlc);
    printf("size 20 the str : %s\t the return: %ld\t the dest:%s\t\n", strcp, ft_strlcat(strlc, strcp, 20), strlc);

    printf("\n\n######################################################################\n\n\n");
    printf("atoi function\n");
    int i = 0;
    char *a[6] = {"53727", "-155", "634527", "0", "-2147483648", "2147483647"};
    printf("the ints are 53727,-155,634527,0,-2147483648,2147483647\n");
    while (i <= 5)
    {
        printf("%d \n", ft_atoi(a[i]));
        i++;
    }
    printf("\n\n######################################################################\n\n\n");
    printf("calloc function\n");

    char *cal = (char *)ft_calloc(1, 10);
    int *cal2 = (int *)ft_calloc(5, 4);

    printf("the first calloc for char * : %s\n", cal);
    printf("calloc for int *cal2\n");
    for (int i = 0; i < 5; i++)
        printf("cal2[%d]: %d\t", i, cal2[i]);
    printf("\n");

    printf("\n\n######################################################################\n\n\n");
    printf("strdup\n");
    char cc[20] = "amjedismail";
    char *dp = ft_strdup(cc);
    printf("the first str: %s address %p the dup of it : %s address %p", cc, &cc, dp, dp);
    printf("\n$$$$\t\tfinished\t\t$$$$");
}