#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# define W 119
# define D 100
# define S 115
# define A 97

typedef struct s_components
{
	int	one;
	int	zero;
	int	c;
	int	e;
	int	p;
	int	others;
}	t_components;

typedef struct s_img_player
{
	void	*front;
	void	*back;
	void	*left;
	void	*right;

}	t_img_player;

typedef struct s_img
{
	t_img_player	player;
	void			*wall;
	void			*coin;
	void			*closed_door;
	void			*opened_door;
	void			*zalij;
}	t_img;

typedef struct s_utilis
{
	char	*map;
	char	**map_2d;
	void	*mlx_ptr;
	void	*mlx_window;
	size_t	available_coins;
	int		exit;
	int		exit_position[2];
	t_img	assets;

}	t_utilis;

char	*read_and_check_map(int fd);
char	*read_map(int fd);
int		check_components(char *map);
int		check_rectangular(char **map_2d);
int		check_closed(char **map_2d);
int		create_2d_map(char *map, char ***map_2d);
int		check_valid_path(char *map);
void	free_map(char **map);
size_t	map_x_len(char *map);
size_t	map_y_len(char *map);
void	get_player_position(int *pp, char **map_2d);
void	init_assets_in_window(t_utilis *ptr);
void	start_game(char *map);
void	go_up(t_utilis *ptr);
void	go_down(t_utilis *ptr);
void	destroy_all(t_utilis *ptr);
void	go_left(t_utilis *ptr);
void	go_rigth(t_utilis *ptr);
size_t	count_available_coins(t_utilis *ptr);
void	destroy_assets(t_utilis *ptr);
int		handle_input(int key, t_utilis *ptr);
void	get_exit_position(int *ep, t_utilis *ptr);
void	init_assets(t_utilis *ptr);

#endif
