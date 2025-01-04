#include <so_long.h>

// int flood_fill(t_map *map, int *arr)
//{
// }

t_map define_struct(char **map_str)
{
	t_map main_map;
	main_map.map = map_str;
	main_map.col_p = 0;
	main_map.row_p = 0;
	main_map.C = 0;
	main_map.P = 0;
	main_map.E = 0;
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
