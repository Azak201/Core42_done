#include <so_long.h>

static void counter(char mc, int *c, int *p, int *e);
static void eadges_validating(t_map **tmap);
static void validate_map_contant(char **map, t_map **main_map);

char **handling_map_shape(char **line)
{
	char **tmp;
	int i;
	int cmp;
	int len;

	check_empty_lines(&(*line));
	tmp = ft_split(*line, '\n');
	if (!tmp)
	{
		free(*line);
		ft_exit_fd(0, "Failure in allocation", 0);
	}
	i = 0;
	cmp = ft_strlen(tmp[0]);
	while (tmp[i] != NULL)
	{
		len = ft_strlen(tmp[i]);
		if ((cmp != len) || (tmp[i + 1] == NULL && i < 2) || len < 3)
		{
			free(*line);
			ft_free(1, tmp, "invalid  map shape");
		}
		i++;
	}
	return (tmp);
}

t_map *map_validation(char **map)
{
	int i;
	t_map *main_map;

	i = 0;
	main_map = define_struct(map);
	validate_map_contant(map, &main_map);
	while (main_map->map[i] != NULL)
		i++;
	main_map->col_num = ft_strlen(main_map->map[0]);
	main_map->row_num = i;
	eadges_validating(&main_map);
	find_p(&(*main_map));
	main_map->fmap = create_fmap(&main_map);
	flood_fill(&main_map, main_map->row_p, main_map->col_p);
	if ((find_C(main_map)) == 1)
		ft_free_map_struct(1, &main_map, "C is not reachable");
	return (main_map);
}

static void validate_map_contant(char **map, t_map **main_map)
{
	int i;
	int j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strchr("01EPC", map[i][j]) == NULL)
				ft_free_map_struct(1, main_map, "map contant not valid");
			counter(map[i][j], &((*main_map)->C), &((*main_map)->P), &((*main_map)->E));
			j++;
		}
		i++;
	}
	if ((*main_map)->C < 1 || (*main_map)->E != 1 || (*main_map)->P != 1)
		ft_free_map_struct(1, main_map, "invalid number of E, P or C");
}
static void counter(char mc, int *c, int *p, int *e)
{
	if (mc == 'C')
		*c = *c + 1;
	if (mc == 'P')
		*p = *p + 1;
	if (mc == 'E')
		*e = *e + 1;
}
static void eadges_validating(t_map **tmap)
{
	int i;
	int j;

	i = 0;
	while ((*tmap)->map[i] != NULL)
	{
		j = 0;
		while ((*tmap)->map[i][j] != '\0')
		{
			if ((*tmap)->map[0][j] != '1' || (*tmap)->map[(*tmap)->row_num - 1][j] != '1')
				ft_free_map_struct(1, tmap, " rowe adge are not 1 !!?");
			j++;
		}
		if ((*tmap)->map[i][0] != '1' || (*tmap)->map[i][(*tmap)->col_num - 1] != '1')
			ft_free_map_struct(1, tmap, "colums are not 1 !!?");
		i++;
	}
}
