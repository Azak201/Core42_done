/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:42:32 by amismail          #+#    #+#             */
/*   Updated: 2025/01/01 06:25:15 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <libft.h>
#include <fcntl.h>

typedef struct s_map
{
	char **map;
	int col_p;
	int row_p;
	int C;
	int P;
	int E;
} t_map;

char **handling(char **line);
void ft_exit_fd(int flag, char *message, int fd);
void ft_free(int flag, char **arr, char *message);
void map_validation(char **map);
t_map define_struct(char **map_str);

void find_p(t_map *map);

#endif