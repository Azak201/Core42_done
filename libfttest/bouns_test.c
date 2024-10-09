#include "libft.h"

void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

// Function to delete the content (string) of a node
void delete_content(void *content)
{
    free(content); // Assuming content was dynamically allocated
}

int main()
{
    t_list *list = NULL;

    // Adding elements to the list
    for (int i = 0; i < 5; i++)
    {
        char *content = malloc(20);
        snprintf(content, 20, "Node %d", i);
        t_list *new_node = ft_lstnew(content);
        ft_lstadd_back(&list, new_node);
    }

    // Print the list
    printf("Initial list:\n");
    print_list(list);

    // Adding a new element at the front
    char *new_content = malloc(20);
    snprintf(new_content, 20, "Front Node");
    t_list *new_front_node = ft_lstnew(new_content);
    ft_lstadd_front(&list, new_front_node);

    // Print the updated list
    printf("After adding a new front node:\n");
    print_list(list);

    // Mapping function: make all contents uppercase
    t_list *mapped_list = ft_lstmap(list, (void *(*)(void *))ft_toupper, delete_content);
    printf("Mapped list (uppercase):\n");
    print_list(mapped_list);

    // Clear the original list
    ft_lstclear(&list, delete_content);
    printf("Original list after clearing:\n");
    print_list(list); // Should print NULL

    // Clear the mapped list
    ft_lstclear(&mapped_list, delete_content);
    printf("Mapped list after clearing:\n");
    print_list(mapped_list); // Should print NULL

    return 0;
}