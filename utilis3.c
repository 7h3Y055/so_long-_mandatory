#include "so_long.h"

size_t	map_x_len(char *map)
{
	int	x;

	x = 0;
	while (map[x] && map[x] != '\n')
		x++;
	return (x);
}

size_t	map_y_len(char *map)
{
	int		i;
	size_t	y;

	i = 0;
	y = 0;
	while (map[i])
	{
		while (map[i] && map[i] != '\n')
			i++;
		i++;
		y++;
	}
	return (y);
}

int	check_rectangular(char **map_2d)
{
	int		i;

	i = 1;
	while (map_2d[i])
	{
		if (ft_strlen(map_2d[i - 1]) != ft_strlen(map_2d[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_components(char *map)
{
	int				i;
	t_components	*content;

	i = 0;
	content = ft_calloc(sizeof(t_components), 1);
	while (map[i])
	{
		if (map[i] == '1')
			content->one++;
		else if (map[i] == '0')
			content->zero++;
		else if (map[i] == 'E')
			content->e++;
		else if (map[i] == 'C')
			content->c++;
		else if (map[i] == 'P')
			content->p++;
		else if (!(map[i] == '\n' || map[i] == '\r'))
			content->others++;
		i++;
	}
	if (content->others || !content->one || !content->zero || \
			!content->c || content->e != 1 || content->p != 1)
		return (free(map), free(content), 1);
	return (free(content), 0);
}

char	*read_map(int fd)
{
	char	*map;
	char	*tmp;
	char	*tmp2;

	map = NULL;
	tmp = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tmp2 = ft_strjoin(map, tmp);
		free(tmp);
		free(map);
		map = tmp2;
	}
	return (map);
}
