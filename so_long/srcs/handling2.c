#include <so_long.h>

void ft_exit_fd(int flag, char *message, int fd)
{
	ft_printf("Error\n%s\n", message);
	if (flag == 1)
		close(fd);
	exit(1);
}

void ft_free(int flag, char **arr, char *message)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
	if (flag != 0)
		ft_exit_fd(0, message, 0);
}
void ft_free_map_struct(int flag, t_map **stru, char *message)
{
	if ((*stru)->fmap != NULL)
		ft_free(0, ((*stru)->fmap), NULL);
	if ((*stru)->map != NULL)
		ft_free(0, ((*stru)->map), NULL);
	free(stru);
	if (flag != 0)
		ft_exit_fd(0, message, 0);
}