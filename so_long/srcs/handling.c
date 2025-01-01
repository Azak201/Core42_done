#include <so_long.h>

static void counter(char mc, int *c, int *p, int *e);
static void eadges_validating(char **map);

char **handling(char **line)
{
	char **tmp;
	int i;
	int cmp;
	int len;

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
		if ((cmp != len) || (tmp[i + 1] == NULL && i < 2) || len < 5)
		{
			free(*line);
			ft_free(1, tmp, "invalid  map shape");
		}
		i++;
	}
	return (tmp);
}

void map_validation(char **map)
{
	int c;
	int p;
	int e;
	int i;
	int j;

	i = 0;
	c = 0;
	p = 0;
	e = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strchr("01EPC", map[i][j]) == NULL)
				ft_free(1, map, "map contant not valid");
			counter(map[i][j], &c, &p, &e);
			j++;
		}
		i++;
	}
	if (c < 1 || p != 1 || e != 1)
		ft_free(1, map, "invalid number of E, P or C");
	eadges_validating(map);
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
static void eadges_validating(char **map)
{
	int i;
	int j;
	int col;
	int row;

	i = 0;
	j = 0;
	col = ft_strlen(map[0]);
	while (map[i] != NULL)
		i++;
	row = i;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[0][j] != '1' || map[row - 1][j] != '1')
				ft_free(1, map, " rowe adge are not 1 !!?");
			j++;
		}
		if (map[i][0] != '1' || map[i][col - 1] != '1')
			ft_free(1, map, "colums are not 1 !!?");
		i++;
	}
}
