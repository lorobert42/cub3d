#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <float.h>
# include <math.h>
# include "keys.h"
# include "libft.h"
# include "mlx.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	final;
}	t_color;

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_line
{
	int		n_line;
	int		wall_size;
	float	wall_x;
}	t_line;

//	field => the percentage of view
//
typedef struct s_view
{
	int	field_horizontal;
	int	field_vertical;

}	t_view;

typedef struct s_texture
{
	void	*image;
	int		width;
	int		height;
}	t_texture;

typedef struct s_image
{
	void	*data;
	char	*image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;



/*#BSQ map[line][column]*/
typedef struct s_info
{
	char		**map;
	int			nb_lines;

//////////////////shiroz///////////////////////
	char		start_direction;
	int			start_column;
	int			start_line;
	int			middle;
	t_texture	n_info;
	t_texture	s_info;
	t_texture	w_info;
	t_texture	e_info;
	t_line		line_to_print;
	t_image		image;
//////////////////lorobert///////////////////////
	t_point		pos;
	t_point		dir;
	t_point		plane;
	char		*n_texture;
	char		*s_texture;
	char		*w_texture;
	char		*e_texture;
	t_color		f_color;
	t_color		c_color;
	void		*mlx_ptr;
	void		*win_ptr;
}	t_info;

typedef enum e_arg_type
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	EMPTY,
	NONE
}	t_arg_type;

//////////////////lorobert///////////////////////

void	parse_file(t_info *info, char *file_name);
void	fatal_error(char *msg, char *element);
void	check_info_header(t_info *info);
void	clear_split(char **split);
void	clear_info(t_info *info);
void	clear_mlx(t_info *info);
void	del(void *content);
void	init_info(t_info *info);
void	init_mlx(t_info *info);
void	init_player(t_info *info);
void	hooks(t_info *info);
int		quit(t_info *info);
void	raycast(t_info *info);

///////////////////shiroz///////////////////////
void	check_map(t_info *info);
char	**ft_strdup_tab_of_string(char **to_duplicate);
void	check_map_invalid_char(char **map, t_info *info);
void	check_map_is_closed(char **map, int column, int line, int nb_line);
void	check_texture(t_info *info);
void	ft_put_line(t_info *info);
#endif
