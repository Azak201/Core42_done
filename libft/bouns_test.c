
#include "libft.h"
void del(void *x)
{
    free(x);
}

int main ()
{
    t_list *list;
    int i;

    list = ft_lstnew("this is first node");

    ft_lstadd_back(&list,ft_lstnew("this is the sec"));
    ft_lstadd_front(&list,ft_lstnew("third but we added front"));

    i = ft_lstsize(list);
    t_list *cp = list;
    while (cp->next!=NULL)
    {
        printf("%s \n",(char *)(cp)->content);
        cp=cp->next;
    }
    printf("the list size is %d\n",i);
    t_list *last ; 
    last = ft_lstlast(list);
    printf("the last element (%s)\n",(char *)last->content);
    printf("delet it \n");
    ft_lstdelone(ft_lstlast(list),del);
    cp = list;
    while (list->next!=NULL)
    {
        printf("%s \n",(char *)(list)->content);
        (list)=(list)->next;
    }
    return(0);



}