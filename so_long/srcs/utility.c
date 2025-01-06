#include <so_long.h>

t_map *define_struct(char **map_str)
{
	t_map *main_map;

	main_map = (t_map *)malloc(sizeof(t_map));
	main_map->map = map_str;
	main_map->col_p = 0;
	main_map->row_p = 0;
	main_map->C = 0;
	main_map->P = 0;
	main_map->E = 0;
	main_map->col_num = 0;
	main_map->row_num = 0;
	main_map->fmap = NULL;
	return (main_map);
}

void find_p(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'P')
			{
				map->col_p = j;
				map->row_p = i;
				return;
			}
			j++;
		}
		i++;
	}
}

void create_fmap(t_map **main_map)
{
	int i;

	i = 0;
	while ((*main_map)->map[i] != NULL)
		i++;
	(*main_map)->fmap = (char **)malloc(sizeof(char *) * i);
	if (!((*main_map)->fmap))
		ft_free_map_struct(1, &(*main_map), "fail Alocation in fmap");
	i = 0;
	while ((*main_map)->map[i] != NULL)
	{
		(*main_map)->fmap[i] = ft_strdup((*main_map)->map[i]);
		if (!((*main_map)->fmap[i]))
			ft_free_map_struct(1, &(*main_map), "fail Alocation in fmap");
		i++;
	}
	(*main_map)->fmap[i] = NULL;
}
int find_C(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (map->fmap[i] != NULL)
	{
		j = 0;
		while (map->fmap[i][j] != '\0')
		{
			if (map->fmap[i][j] != 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}