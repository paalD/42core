/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:28:42 by dpaal             #+#    #+#             */
/*   Updated: 2022/09/27 15:05:39 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE				1024

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# include "../mlx/mlx.h"
# include "../Libft/libft.h"
# include "../printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# define A_KEY					97
# define W_KEY					119
# define S_KEY					115
# define D_KEY					100
# define ESC					65307

# define SPR_WIDTH				60
# define SPR_HEIGHT				60

typedef struct s_vector {
	int			x;
	int			y;
}	t_vector;

typedef struct s_game {
	int			count_points;
	int			count_steps;
}	t_game;

typedef struct s_map {
	char		**mtx;
	t_vector	size;
}	t_map;

typedef struct s_img {
	void		*img_ptr;
	t_vector	size;
	t_vector	pos;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_game		game;
	t_map		map;
	t_img		img;
}	t_vars;

int		check_arg(int argc, char **argv);
int		check_argument(int argc, char **argv);
void	msg_error(char *msg);
int		get_map_size(t_vars *vars, char **argv);
int		initialize_map(t_vars *vars, char **argv);
int		check_map(t_vars vars);
int		check_walls(t_vars vars);
int		check_objects(t_vars vars);
int		check_shape(t_vars vars);
int		check_map_characters(t_vars vars);
int		place_player(t_vars *vars);
int		count_points(t_vars *vars);
int		draw_map(t_vars vars);
int		load_graphics(t_vars vars, int rows, int columns);
int		use_key(int keycode, t_vars *vars);
int		move(int keycode, t_vars *vars);
int		move_up(t_vars *vars);
int		move_down(t_vars *vars);
int		move_left(t_vars *vars);
int		move_right(t_vars *vars);
int		check_points(t_vars *vars);
int		complete_game(t_vars *vars, char *congrats);
int		close_map(t_vars *vars);
int		mlx_close(t_vars *vars);
char	*get_next_line(int fd);
void	error_msg(char *msg);
int		mlx_close(t_vars *vars);

#endif
