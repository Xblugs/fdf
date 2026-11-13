/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cczerwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:45:02 by cczerwin          #+#    #+#             */
/*   Updated: 2025/01/27 11:45:08 by cczerwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
// RAND_MAX defined in stdlib.h
# include <stdio.h>
# include <string.h>
# include <math.h>
// M_PI values are defined in math.h

# include "get_next_line.h"
# include "./printf/ft_printf.h"
# include "./minilibx-linux/mlx.h"
//# include "./minilibx-linux/mlx_int.h"
# include "parrot.h"
// 🦜

# define PURPLE 0xFF00FF
# define ORANGE 0xFF9900
# define YELLOW 0xFFFF00
# define GREEN 0x00FF00
# define WHITE 0xFFFFFF

//planned for no file input animation
//maybe not the best color choice but isok (Munsell)
# define RED 0xFF0000
# define BLUE 0x0000FF
# define CYAN 0x00FFFF
# define LIME 0xBFFF00
# define BROWN 0x964B00

//ESC key as defined by X11/keysymdef.h
# define ESC 0xFF1B
# define ENTER 0xFF0D
# define SPACE 0x20

//Function keys
# define F1 0xFFBE
# define F2 0xFFBF
# define F3 0xFFC0

//Arrow keys
# define UP 0xFF52
# define DOWN 0xFF54
# define LEFT 0xFF51
# define RIGHT 0xFF53

//Numpad keys
# define NUM_UP 0xFF97
# define NUM_DOWN 0xFF99
# define NUM_LEFT 0xFF96
# define NUM_RIGHT 0xFF98
# define NUM_MID 0xFF9D
# define NUM_ZERO 0xFF9E

//hook flags
# define ON_ENTER 7
# define ON_LEAVE 8
# define ON_DESTROY 17

# define TEXT "Sadly, no bonus is hidden here"

# define HEAD1 "       :::      ::::::::"
# define HEAD2 "     :+:      :+:    :+:"
# define HEAD3 "   +:+ +:+         +:+"
# define HEAD4 "  +#+  +:+       +#+"
# define HEAD5 "+#+#+#+#+#+   +#+"
# define HEAD6 "     #+#    #+#"
# define HEAD7 "    ###   ########.fr"

// (x,y,z) are made to hold x0, x1 and dx for the draw_line function
// pix are the pixel between two data point
typedef struct s_draw
{
	int		x[3];
	int		y[3];
	int		z[3];
	int		pix_x;
	int		pix_y;
	int		pix_z;
	int		off_x;
	int		off_y;
	int		angle;
	int		angle_off;
	int		scale;
	int		h_delta;
	int		color;
}	t_draw;

// handle data map and it's various indexes
typedef struct s_map
{
	int		**map;
	int		line;		// i
	int		col;		// j
}	t_map;

// offset = y * line_lenght + x * (bpp / 8)
// img = 32bpp, 3200ll, 0endian
// 800 x 4 byte = 3200 bit for one line
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		x;
	int		y;
}	t_img;

// img is expected to be window-sized
// t_data encapsulate everything for easier cleanup
// pos are where your current image is located at
// only one image is expected to be drawn at all times
typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		pos_x;
	int		pos_y;
	t_img	*img;
	t_map	*map;
	t_draw	*draw;
}	t_data;

///////////		fdf			///////////

// main
int		get_map(char *file, t_map *map);

///////////		fdf_init			///////////

void	data_init(t_data *mlx, t_img *img, t_draw *draw, t_map *map);
void	data_init2(t_data *mlx, t_img *img, t_draw *draw, t_map *map);
void	draw_data_init(t_data *mlx, t_draw *draw, t_map *map);
void	draw_data_reset(t_data *mlx, t_draw *draw, t_map *map);
void	draw_data_precalc(t_draw *draw, t_map *map, int i, int j);

///////////		fdf_parsing			///////////

char	**copy_map(char *file, int *i, int *j);
int		get_line_count(char *file);
void	check_map(char **map, int *fd, int *i, int *j);
int		convert_map(char **charmap, t_map *map);
void	convert_map2(char **charmap, t_map *map);

///////////		fdf_hook			///////////

void	set_hook(t_data *mlx);
int		mouse_io(t_data *mlx);
int		mouse_handler(int button, int x, int y, t_data *mlx);
int		key_handler(int keycode, t_data *mlx);
int		s_key_handler(int keycode, t_data *mlx);

///////////		fdf_redraw			///////////

void	move_handler(int keycode, t_data *mlx);
void	translation_handler(int keycode, t_data *mlx);
void	zoom_handler(int mouse, t_data *mlx);
void	rotation_handler(int keycode, t_data *mlx);
void	reset_handler(int keycode, t_data *mlx);

///////////		fdf_draw_line		///////////

void	draw_line(t_img *img, t_draw *draw);
void	draw_precalc(t_draw *draw);
void	draw_low(t_img *img, t_draw data);
void	draw_high(t_img *img, t_draw data);
void	pixel_put(t_img *img, int x, int y, int color);

///////////		fdf_draw_iso		///////////

void	draw_isometric(t_data *mlx, t_draw *draw, t_map *map);
void	draw_horizontal(t_data *mlx, t_draw *draw, t_map *map);
void	draw_vertical(t_data *mlx, t_draw *draw, t_map *map);

///////////		fdf_cleanup		///////////

int		mlx_close(t_data *mlx);
void	clear_screen(t_data *mlx);
void	int_cleanup(int **intmap, int line);
void	char_cleanup(char **charmap, int line);

///////////		fdf_util			///////////

int		abs_val(int val);
double	deg_to_rad(double angle);
double	rad_to_deg(double radian);
void	invert_coordinates(t_draw *draw);
void	ft_sleep(void);
// this ft_sleep is yolo, real sleep() isn't allowed for FdF

///////////		fdf_util2			///////////

size_t	ft_splitcheck(char **split, size_t	wordcount);
size_t	ft_digitcount(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int		calc_height_delta(t_map *map);

///////////		🦜			///////////

void	ft_parrot(t_data *mlx);
void	parrot_zero(t_data *mlx);
void	parrot_one(t_data *mlx);
void	parrot_two(t_data *mlx);
void	parrot_three(t_data *mlx);

void	parrot_four(t_data *mlx);
void	parrot_five(t_data *mlx);
void	parrot_six(t_data *mlx);
void	parrot_seven(t_data *mlx);
void	parrot_eight(t_data *mlx);

void	parrot_nine(t_data *mlx);
void	ft_42(t_data *mlx);

#endif
