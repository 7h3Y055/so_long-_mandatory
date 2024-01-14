#include "so_long.h"
#include <stddef.h>

size_t	check_minimal_space(char **map_2d, int y, int x)
{
	size_t	c;

	c = 0;
	if (map_2d[y - 1][x] == 'C')
	{
		c++;
		map_2d[y - 1][x] = '0';
	}
	if (map_2d[y + 1][x] == 'C')
	{
		c++;
		map_2d[y + 1][x] = '0';
	}
	if (map_2d[y][x - 1] == 'C')
	{
		c++;
		map_2d[y][x - 1] = '0';
	}
	if (map_2d[y][x + 1] == 'C')
	{
		c++;
		map_2d[y][x + 1] = '0';
	}
	return (c);
}

size_t	back_track_coin_counter(t_utilis *ptr, char **map_2d, int y, int x)
{
	size_t	c;

	c = check_minimal_space(map_2d, y, x);
	map_2d[y][x] = '1';
	if (map_2d[y - 1][x] != '1')
		c += back_track_coin_counter(ptr, map_2d, y - 1, x);
	if (map_2d[y + 1][x] != '1')
		c += back_track_coin_counter(ptr, map_2d, y + 1, x);
	if (map_2d[y][x - 1] != '1')
		c += back_track_coin_counter(ptr, map_2d, y, x - 1);
	if (map_2d[y][x + 1] != '1')
		c += back_track_coin_counter(ptr, map_2d, y, x + 1);
	return (c);
}

size_t	count_available_coins(t_utilis *ptr)
{
	size_t	c;
	int		pp[2];
	char	**map_2d;

	create_2d_map(ptr->map, &map_2d);
	get_player_position(pp, map_2d);
	c = back_track_coin_counter(ptr, map_2d, pp[0], pp[1]);
	free_map(map_2d);
	return (c);
}

void	init_assets_in_window(t_utilis *ptr)
{
	void	*asset;
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map_y_len(ptr->map))
	{
		x = 0;
		while (x < map_x_len(ptr->map))
		{
			asset = ptr->assets.zalij;
			if (ptr->map_2d[y][x] == '1')
				asset = ptr->assets.wall;
			if (ptr->map_2d[y][x] == 'P')
				asset = ptr->assets.player.front;
			if (ptr->map_2d[y][x] == 'E')
				asset = ptr->assets.closed_door;
			if (ptr->map_2d[y][x] == 'C')
				asset = ptr->assets.coin;
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_window, \
					asset, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
