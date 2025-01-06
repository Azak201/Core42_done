/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:38:33 by amismail          #+#    #+#             */
/*   Updated: 2025/01/01 18:50:40 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <so_long.h>

static void fail_join(char *tmp, char *tmp2, int fd);
static char *fileread(int fd);

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
	ft_free_map_struct(1, &tmap, "map done");
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
	ft_exit_fd(1, "failure in reading file", fd);
}
