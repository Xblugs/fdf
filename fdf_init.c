/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cczerwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:39:13 by cczerwin          #+#    #+#             */
/*   Updated: 2025/03/04 14:39:15 by cczerwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	data_init(t_data *mlx, t_img *img, t_draw *draw, t_map *map);
void	data_init2(t_data *mlx, t_img *img, t_draw *draw, t_map *map);
void	draw_data_init(t_data *mlx, t_draw *draw, t_map *map);
void	draw_data_reset(t_data *mlx, t_draw *draw, t_map *map);
void	draw_data_precalc(t_draw *draw, t_map *map, int i, int j);

// init mlx
void	data_init(t_data *mlx, t_img *img, t_draw *draw, t_map *map)
{
	mlx->mlx = mlx_init();
	data_init2(mlx, img, draw, map);
	img->img = mlx_new_image(mlx->mlx, mlx->x, mlx->y);
	mlx->win = mlx_new_window(mlx->mlx, mlx->x, mlx->y, "FdF");
	if (mlx->mlx == NULL || mlx->win == NULL || img->img == NULL)
		mlx_close(mlx);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&(img->line_len), &img->endian);
	set_hook(mlx);
}

// init values
void	data_init2(t_data *mlx, t_img *img, t_draw *draw, t_map *map)
{
	mlx->x = 800;
	mlx->y = 600;
	if (map->col > 30 || map->line > 30)
	{
		mlx->x = 1600;
		mlx->y = 900;
	}
	img->x = mlx->x;
	img->y = mlx->y;
	mlx->pos_x = 0;
	mlx->pos_y = 0;
	mlx->img = img;
	mlx->draw = draw;
	mlx->map = map;
	draw->off_x = 0;
	draw->off_y = 0;
	draw->scale = 1;
	draw->angle_off = 0;
}

// Calculation to auto-scale (window / drawing)
// 18% of the time, it works everytime
void	draw_data_init(t_data *mlx, t_draw *draw, t_map *map)
{
	draw->pix_x = (mlx->x - (mlx->x / 10)) / (map->col * 1.5);
	draw->pix_y = (mlx->y - (mlx->y / 10)) / (map->line * 1.5);
	draw->h_delta = calc_height_delta(map);
	draw->pix_z = draw->h_delta;
	ft_printf("Height Delta = %d\n", draw->h_delta);
	if (draw->pix_z <= 0)
		draw->pix_z++;
	if (draw->h_delta >= 50)
		draw->pix_z /= 50;
	else
	{
		while (draw->pix_z * 2 < draw->pix_y)
			draw->pix_z *= 2;
		while (draw->pix_z > draw->pix_y)
			draw->pix_z /= 2;
	}
	draw->pix_x = draw->pix_x + (draw->scale * 2);
	draw->pix_y = draw->pix_y + (draw->scale * 2);
	draw->pix_z = draw->pix_z + (draw->scale * 2);
	ft_printf("\e[1;37mDelta (x,y,z) = (%d,%d,%d)\e[0m\n\n",
		draw->pix_x, draw->pix_y, draw->pix_z);
}

void	draw_data_reset(t_data *mlx, t_draw *draw, t_map *map)
{
	draw->z[0] = 0;
	draw->z[1] = map->map[0][0];
	draw->z[2] = draw->z[0] - draw->z[1];
	draw->x[0] = 0;
	draw->x[1] = (mlx->x * 35 / 100) + draw->off_x;
	draw->y[0] = 0;
	draw->y[1] = (mlx->y * 5 / 100) + (draw->z[1] * draw->pix_z) + draw->off_y;
}

// Calc next dot coordinates
// Substracting off and adding it back to prevent drifting
void	draw_data_precalc(t_draw *draw, t_map *map, int i, int j)
{
	draw->z[0] = draw->z[1];
	draw->z[1] = map->map[j][i];
	draw->z[2] = draw->z[0] - draw->z[1];
	draw->x[0] = draw->x[1] - draw->off_x;
	draw->x[1] = draw->x[0] + draw->pix_x * cos(deg_to_rad(draw->angle));
	draw->x[0] += draw->off_x;
	draw->x[1] += draw->off_x;
	draw->y[0] = draw->y[1] - draw->off_y;
	draw->y[1] = draw->y[0] + draw->pix_y * sin(deg_to_rad(draw->angle));
	draw->y[0] += draw->off_y;
	draw->y[1] += draw->off_y;
	if (draw->z[2] != 0)
		draw->y[1] = draw->y[1] + (draw->z[2] * draw->pix_z);
}
