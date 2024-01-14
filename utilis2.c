#include "so_long.h"

void	get_exit_position(int *ep, t_utilis *ptr)
{
	ep[0] = 1;
	while (ep[0] < (int)map_y_len(ptr->map))
	{
		ep[1] = 1;
		while (ep[1] < (int)map_x_len(ptr->map))
		{
			if (ptr->map_2d[ep[0]][ep[1]] == 'E')
				return ;
			ep[1]++;
		}
		ep[0]++;
	}
}

void	destroy_all(t_utilis *ptr)
{
	destroy_assets(ptr);
	mlx_destroy_window(ptr->mlx_ptr, ptr->mlx_window);
	mlx_destroy_display(ptr->mlx_ptr);
	free(ptr->mlx_ptr);
	free(ptr->map);
	free_map(ptr->map_2d);
	exit(0);
}

void	winner_winner(t_utilis *ptr, int *ep, int *pp)
{
	ptr->exit = 0;
	get_exit_position(ep, ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_window, \
			ptr->assets.opened_door, ep[1] * 32, ep[0] * 32);
	get_player_position(pp, ptr->map_2d);
	if (ptr->exit_position[0] == pp[0] && ptr->exit_position[1] == pp[1])
	{
		ft_printf("winner winner chicken dinner\n");
		destroy_all(ptr);
	}
}

int	handle_input(int key, t_utilis *ptr)
{
	int	ep[2];
	int	pp[2];

	if (key == W)
		go_up(ptr);
	else if (key == D)
		go_left(ptr);
	else if (key == S)
		go_down(ptr);
	else if (key == A)
		go_rigth(ptr);
	if (key == XK_Escape)
		destroy_all(ptr);
	if (ptr->available_coins == 0)
	{
		winner_winner(ptr, ep, pp);
	}
	return (0);
}

void	destroy_assets(t_utilis *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->assets.player.back);
	mlx_destroy_image(ptr->mlx_ptr, ptr->assets.player.front);
	mlx_destroy_image(ptr->mlx_ptr, ptr->assets.player.left);
	mlx_destroy_image(ptr->mlx_ptr, ptr->assets.player.right);
	mlx_destroy_image(ptr->mlx_ptr, ptr->assets.closed_door);
	mlx_destroy_image(ptr->mlx_ptr, ptr->assets.opened_door);
	mlx_destroy_image(ptr->mlx_ptr, ptr->assets.coin);
	mlx_destroy_image(ptr->mlx_ptr, ptr->assets.wall);
	mlx_destroy_image(ptr->mlx_ptr, ptr->assets.zalij);
}
