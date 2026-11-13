/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cczerwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:53:51 by cczerwin          #+#    #+#             */
/*   Updated: 2025/03/06 17:54:09 by cczerwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_isometric(t_data *mlx, t_draw *draw, t_map *map);
void	draw_horizontal(t_data *mlx, t_draw *draw, t_map *map);
void	draw_vertical(t_data *mlx, t_draw *draw, t_map *map);

void	draw_isometric(t_data *mlx, t_draw *draw, t_map *map)
{
	draw_data_init(mlx, draw, map);
	draw_data_reset(mlx, draw, map);
	draw_horizontal(mlx, draw, map);
	draw_data_reset(mlx, draw, map);
	draw_vertical(mlx, draw, map);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img,
		mlx->pos_x, mlx->pos_y);
}

void	draw_horizontal(t_data *mlx, t_draw *draw, t_map *map)
{
	int	i[3];

	i[1] = 0;
	while (i[1] != map->line)
	{
		i[0] = 1;
		draw->angle = 30 + draw->angle_off;
		while (i[0] < map->col)
		{
			draw_data_precalc(draw, map, i[0], i[1]);
			draw_line(mlx->img, draw);
			i[0]++;
		}
		i[1]++;
		draw_data_reset(mlx, draw, map);
		draw->angle = 120 + draw->angle_off;
		i[2] = 0;
		while (i[2] < i[1] && i[1] != map->line)
		{
			draw_data_precalc(draw, map, 0, i[1]);
			i[2]++;
		}
	}
}

void	draw_vertical(t_data *mlx, t_draw *draw, t_map *map)
{
	int	i[3];

	i[0] = 0;
	while (i[0] != map->col)
	{
		i[1] = 1;
		draw->angle = 120 + draw->angle_off;
		while (i[1] < map->line)
		{
			draw_data_precalc(draw, map, i[0], i[1]);
			draw_line(mlx->img, draw);
			i[1]++;
		}
		i[0]++;
		draw_data_reset(mlx, draw, map);
		draw->angle = 30 + draw->angle_off;
		i[2] = 0;
		while (i[2] < i[0] && i[0] != map->col)
		{
			draw_data_precalc(draw, map, i[0], 0);
			i[2]++;
		}
	}
}
