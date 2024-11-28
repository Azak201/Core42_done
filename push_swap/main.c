

int main(int ac, char **av)
{
        char **str;
        int i;

        i = 1;
        if (ac <= 1)
                exit(1);
        else if (ac == 2)
        {
                str = ft_split(av[1]);
        }
        else
        {
                str = (char **)malloc(sizeof(char *) * ac);
                while (i <= ac)
                        str[i - 1] = av[i++];
        }
}