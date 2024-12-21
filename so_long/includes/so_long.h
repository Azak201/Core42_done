/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:42:32 by amismail          #+#    #+#             */
/*   Updated: 2025/01/07 00:01:36 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <libft.h>
#include <fcntl.h>

typedef struct s_map
{
	char **map;
	char **fmap;
	int col_p;
	int row_p;
	int C;
	int P;
	int E;
	int row_num;
	int col_num;
} t_map;

typedef struct s_game
{
	t_map **tmap;
	void *mlx_ptr;
	void *win_ptr;
	void *player_image;
	void *wall_image;
	void *c_image;
	void *exit_image;
	void *tail_image;
} t_game;

char **handling_map_shape(char **line);
void ft_exit_fd(int flag, char *message, int fd);
void ft_free(int flag, char **arr, char *message);
t_map *map_validation(char **map);
t_map *define_struct(char **map_str);
void find_p(t_map *map);
void check_empty_lines(char **line);
void ft_exit_fd(int flag, char *message, int fd);
void ft_free(int flag, char **arr, char *message);
void ft_free_map_struct(int flag, t_map **stru, char *message);
char **create_fmap(t_map **main_map);
void flood_fill(t_map **map, int p_row, int p_col);
int find_C(t_map *map);
void create_the_game(t_map **tmap);
#endif