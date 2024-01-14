#include "so_long.h"

int	check_closed(char **map_2d)
{
	int		i;
	int		y;

	y = 0;
	while (map_2d[y])
		y++;
	i = -1;
	while (map_2d[0][++i])
		if (map_2d[0][i] != '1' || map_2d[y - 1][i] != '1')
			return (1);
	i = 0;
	while (map_2d[i] && map_2d[i][0])
	{
		if (map_2d[i][0] != '1' || map_2d[i][ft_strlen(map_2d[0]) - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	get_player_position(int *pp, char **map_2d)
{
	pp[0] = 0;
	while (map_2d[pp[0]])
	{
		pp[1] = 0;
		while (map_2d[pp[0]][pp[1]])
		{
			if (map_2d[pp[0]][pp[1]] == 'P')
				return ;
			pp[1]++;
		}
		pp[0]++;
	}
}

int	valid_path(char **map, int y, int x)
{
	if (map[y - 1][x] == 'E')
		return (1);
	else if (map[y + 1][x] == 'E')
		return (1);
	else if (map[y][x - 1] == 'E')
		return (1);
	else if (map[y][x + 1] == 'E')
		return (1);
	map[y][x] = '1';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
		if (valid_path(map, y - 1, x))
			return (1);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
		if (valid_path(map, y + 1, x))
			return (1);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
		if (valid_path(map, y, x - 1))
			return (1);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
		if (valid_path(map, y, x + 1))
			return (1);
	return (0);
}

int	check_valid_path(char *map)
{
	char	**map_2d;
	int		player_position[2];

	if (create_2d_map(map, &map_2d))
		return (1);
	get_player_position(player_position, map_2d);
	if (!valid_path(map_2d, player_position[0], player_position[1]))
		return (free_map(map_2d), free(map), 1);
	free_map(map_2d);
	return (0);
}

int	create_2d_map(char *map, char ***map_2d)
{
	int	i;
	int	j;
	int	u;

	i = 0;
	u = 0;
	map_2d[0] = malloc(sizeof(char *) * (map_y_len(map) + 1));
	if (!map_2d[0])
		return (free(map), 1);
	while (map[i])
	{
		map_2d[0][u] = malloc(sizeof(char) * (map_x_len(map) + 1));
		j = 0;
		while (map[i] && !(map[i] == '\n' || map[i] == '\r'))
			map_2d[0][u][j++] = map[i++];
		map_2d[0][u][j] = 0;
		u++;
		i++;
	}
	map_2d[0][u] = NULL;
	return (0);
}
