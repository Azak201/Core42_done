/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:38:33 by amismail          #+#    #+#             */
/*   Updated: 2024/12/31 23:10:27 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <so_long.h>

void ft_exit(int flag, char *message, int fd);
void fail_join(char *tmp, char *tmp2, int fd);
char *fileread(int fd);

int main(int arc, char **argv)
{
	int fd;
	char *map;
	int len;

	if (arc != 2)
		ft_exit(0, "Error in args number", 0);
	len = ft_strlen(argv[1]);
	if ((ft_strncmp(argv[1] + (len - 4), ".ber", 5) != 0))
		ft_exit(0, "Error in File extention", 0);
	fd = open(argv[1], O_RDONLY);
	map = fileread(fd);
	free(map);
	close(fd);
}

char *fileread(int fd)
{
	int i;
	char *tmp;
	char *tmp2;
	char *line;

	if (fd < 0)
		ft_exit(0, "Error if opening file", 0);
	line = NULL;
	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp && i == 0)
			ft_exit(1, "Error in read or empty file", fd);
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

void fail_join(char *tmp, char *tmp2, int fd)
{
	if (tmp)
		free(tmp);
	if (tmp2)
		free(tmp2);
	ft_exit(1, "Error in reading file", fd);
}

void ft_exit(int flag, char *message, int fd)
{
	if (flag < 4)
	{
		ft_printf("%s\n", message);
		if (flag == 1)
			close(fd);
		exit(1);
	}
}
