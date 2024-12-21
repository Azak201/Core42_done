/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:38:33 by amismail          #+#    #+#             */
/*   Updated: 2025/01/07 00:21:25 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <so_long.h>

static void fail_join(char *tmp, char *tmp2, int fd);
static char *fileread(int fd);

/*void print_maps(t_map *map)
{
	int i;

	i = 0;
	while (map->map[i] != NULL)
	{
		ft_printf("%s\n", map->map[i]);
		i++;
	}
	i = 0;
	ft_printf("\n------------------\n");
	while (map->fmap[i] != NULL)
	{
		ft_printf("%s\n", map->fmap[i]);
		i++;
	}
}*/

int main(int arc, char **argv)
{
	int fd;
	char *line;
	char **map;
	int len;
	t_map *tmap;

	if (arc != 2)
		ft_exit_fd(0, "invalid args number", 0);
	len = ft_strlen(argv[1]);
	if ((ft_strncmp(argv[1] + (len - 4), ".ber", 5) != 0))
		ft_exit_fd(0, "invalid File extention", 0);
	fd = open(argv[1], O_RDONLY);
	line = fileread(fd);
	close(fd);
	map = handling_map_shape(&line);
	free(line);
	tmap = map_validation(map);
	ft_free_map_struct(0, &tmap, 0);
	create_the_game(&tmap);
}

static char *fileread(int fd)
{
	int i;
	char *tmp;
	char *tmp2;
	char *line;

	if (fd < 0)
		ft_exit_fd(0, "failure in opening file", 0);
	line = NULL;
	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp && i == 0)
			ft_exit_fd(1, "failure in read or file is empty", fd);
		tmp2 = line;
		line = ft_strjoin(tmp2, tmp);
		if (i++ > 0)
			free(tmp2);
		if (!line)
			fail_join(tmp, tmp2, fd);
		if (!tmp)
			return (line);
		free(tmp);
	}
}

static void fail_join(char *tmp, char *tmp2, int fd)
{
	if (tmp)
		free(tmp);
	if (tmp2)
		free(tmp2);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
	ft_exit_fd(1, "failure in reading file", fd);
}

void create_the_game(t_map **tmap)
{
	t_game so_long;

	so_long.tmap = tmap;
	so_long.mlx_ptr = mlx_init();
	so_long.win_ptr = mlx_new_window(so_long.mlx_ptr, 1000, 1000, "so_long");
	mlx_loop(so_long.mlx_ptr);
}