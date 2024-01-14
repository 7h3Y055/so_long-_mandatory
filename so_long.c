#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*map;

	if (argc != 2)
		return (ft_putendl_fd("[-] Usage:\n./so_long map.ber", 2), 1);
	if (!ft_strchr(argv[1], '.') || \
			ft_strncmp(ft_strchr(argv[1], '.'), ".ber", 5))
		return (ft_putendl_fd("[!] file extention was not .ber", 2), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror(argv[1]), 1);
	map = read_and_check_map(fd);
	if (!map)
		return (1);
	start_game(map);
	return (0);
}

char	*read_and_check_map(int fd)
{
	char	*map;
	char	*tmp;
	char	**map_2d;

	tmp = read_map(fd);
	if (tmp[ft_strlen(tmp) - 1] != '\n')
	{
		map = ft_strjoin(tmp, "\n");
		free(tmp);
	}
	else
		map = tmp;
	create_2d_map(map, &map_2d);
	if (check_components(map))
		return (free_map(map_2d), \
				ft_putendl_fd("[!] Contain invalid component", 2), NULL);
	if (check_rectangular(map_2d))
		return (free(map), free_map(map_2d), \
				ft_putendl_fd("[!] Not rectangular", 2), NULL);
	if (check_closed(map_2d))
		return (free(map), free_map(map_2d), \
				ft_putendl_fd("[!] Not closed by wall", 2), NULL);
	if (check_valid_path(map))
		return (free_map(map_2d), ft_putendl_fd("[!] Invalid path", 2), NULL);
	return (free_map(map_2d), map);
}

void	start_game(char *map)
{
	t_utilis	ptr;
	char		**map_2d;

	ptr.map = map;
	create_2d_map(map, &map_2d);
	ptr.map_2d = map_2d;
	ptr.available_coins = count_available_coins(&ptr);
	ptr.exit = 1;
	get_exit_position(ptr.exit_position, &ptr);
	ptr.mlx_ptr = mlx_init();
	ptr.mlx_window = mlx_new_window(ptr.mlx_ptr, map_x_len(map) * 32, \
			map_y_len(map) * 32, "so_long");
	init_assets(&ptr);
	init_assets_in_window(&ptr);
	mlx_key_hook(ptr.mlx_window, handle_input, &ptr);
	mlx_loop(ptr.mlx_ptr);
	exit(0);
}
