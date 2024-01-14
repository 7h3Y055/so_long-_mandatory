#include "so_long.h"

void	go_up(t_utilis *ptr)
{
	int	pp[2];
	int	y;
	int	x;

	get_player_position(pp, ptr->map_2d);
	y = pp[0];
	x = pp[1];
	if (ptr->map_2d[y - 1][x] == '1' || \
			(ptr->map_2d[y - 1][x] == 'E' && ptr->exit))
		return ;
	if (ptr->map_2d[y - 1][x] == 'C')
		ptr->available_coins -= 1 ;
	ft_printf("[%d]%d,%d\n", ptr->available_coins, y, x);
	ptr->map_2d[y - 1][x] = 'P';
	ptr->map_2d[y][x] = '0';
	mlx_put_image_to_window(ptr->mlx_ptr, \
			ptr->mlx_window, ptr->assets.zalij, x * 32, y * 32);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_window, \
			ptr->assets.player.back, x * 32, (y - 1) * 32);
}

void	go_down(t_utilis *ptr)
{
	int	pp[2];
	int	y;
	int	x;

	get_player_position(pp, ptr->map_2d);
	y = pp[0];
	x = pp[1];
	if (ptr->map_2d[y + 1][x] == '1' || \
			(ptr->map_2d[y + 1][x] == 'E' && ptr->exit))
		return ;
	if (ptr->map_2d[y + 1][x] == 'C')
		ptr->available_coins -= 1 ;
	ft_printf("[%d]%d,%d\n", ptr->available_coins, y, x);
	ptr->map_2d[y + 1][x] = 'P';
	ptr->map_2d[y][x] = '0';
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_window, \
			ptr->assets.zalij, x * 32, y * 32);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_window, \
			ptr->assets.player.front, x * 32, (y + 1) * 32);
}

void	go_left(t_utilis *ptr)
{
	int	pp[2];
	int	y;
	int	x;

	get_player_position(pp, ptr->map_2d);
	y = pp[0];
	x = pp[1];
	if (ptr->map_2d[y][x + 1] == '1' || \
			(ptr->map_2d[y][x + 1] == 'E' && ptr->exit))
		return ;
	if (ptr->map_2d[y][x + 1] == 'C')
		ptr->available_coins -= 1 ;
	ft_printf("[%d]%d,%d\n", ptr->available_coins, y, x);
	ptr->map_2d[y][x + 1] = 'P';
	ptr->map_2d[y][x] = '0';
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_window, \
			ptr->assets.zalij, x * 32, y * 32);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_window, \
			ptr->assets.player.right, (x + 1) * 32, y * 32);
}

void	go_rigth(t_utilis *ptr)
{
	int	pp[2];
	int	y;
	int	x;

	get_player_position(pp, ptr->map_2d);
	y = pp[0];
	x = pp[1];
	if (ptr->map_2d[y][x - 1] == '1' || \
			(ptr->map_2d[y][x - 1] == 'E' && ptr->exit))
		return ;
	if (ptr->map_2d[y][x - 1] == 'C')
		ptr->available_coins -= 1 ;
	ft_printf("[%d]%d,%d\n", ptr->available_coins, y, x);
	ptr->map_2d[y][x - 1] = 'P';
	ptr->map_2d[y][x] = '0';
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_window, \
			ptr->assets.zalij, x * 32, y * 32);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_window, \
			ptr->assets.player.left, (x - 1) * 32, y * 32);
}

void	init_assets(t_utilis *ptr)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	ptr->assets.player.back = mlx_xpm_file_to_image(ptr->mlx_ptr, \
			"./textures/player/back.xpm", &w, &h);
	ptr->assets.player.front = mlx_xpm_file_to_image(ptr->mlx_ptr, \
			"./textures/player/front.xpm", &w, &h);
	ptr->assets.player.left = mlx_xpm_file_to_image(ptr->mlx_ptr, \
			"./textures/player/left.xpm", &w, &h);
	ptr->assets.player.right = mlx_xpm_file_to_image(ptr->mlx_ptr, \
			"./textures/player/right.xpm", &w, &h);
	ptr->assets.closed_door = mlx_xpm_file_to_image(ptr->mlx_ptr, \
			"./textures/exit-closed.xpm", &w, &h);
	ptr->assets.opened_door = mlx_xpm_file_to_image(ptr->mlx_ptr, \
			"./textures/open-exit.xpm", &w, &h);
	ptr->assets.coin = mlx_xpm_file_to_image(ptr->mlx_ptr, \
			"./textures/coin-bag.xpm", &w, &h);
	ptr->assets.wall = mlx_xpm_file_to_image(ptr->mlx_ptr, \
			"./textures/wall.xpm", &w, &h);
	ptr->assets.zalij = mlx_xpm_file_to_image(ptr->mlx_ptr, \
			"./textures/floor.xpm", &w, &h);
}
