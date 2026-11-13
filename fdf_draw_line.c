/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cczerwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:32:29 by cczerwin          #+#    #+#             */
/*   Updated: 2025/02/27 17:32:31 by cczerwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//	-> [line] -> [precalc] -> [draw_low]	-> [pixel_put]
//						   -> [draw_high]	-> [pixel_put]
void	draw_line(t_img *img, t_draw *draw);
void	draw_precalc(t_draw *draw);
void	draw_low(t_img *img, t_draw draw);
void	draw_high(t_img *img, t_draw draw);
void	pixel_put(t_img *img, int x, int y, int color);

void	draw_line(t_img *img, t_draw *draw)
{
	if (abs_val(draw->y[1] - draw->y[0]) < abs_val(draw->x[1] - draw->x[0]))
	{
		if (draw->x[0] > draw->x[1])
		{
			invert_coordinates(draw);
			draw_low(img, *draw);
			invert_coordinates(draw);
		}
		else
			draw_low(img, *draw);
	}
	else
	{
		if (draw->y[0] > draw->y[1])
		{
			invert_coordinates(draw);
			draw_high(img, *draw);
			invert_coordinates(draw);
		}
		else
			draw_high(img, *draw);
	}
}

void	draw_precalc(t_draw *draw)
{
	draw->x[2] = draw->x[1] - draw->x[0];
	draw->y[2] = draw->y[1] - draw->y[0];
	if (abs_val(draw->z[2]) == 0)
		draw->color = WHITE;
	else if (abs_val(draw->z[2]) < 4)
		draw->color = GREEN;
	else if (abs_val(draw->z[2]) < 7)
		draw->color = YELLOW;
	else if (abs_val(draw->z[2]) < 10)
		draw->color = ORANGE;
	else if (abs_val(draw->z[2]) >= 50)
		draw->color = BROWN;
	else if (abs_val(draw->z[2]) >= 30)
		draw->color = CYAN;
	else if (abs_val(draw->z[2]) >= 20)
		draw->color = RED;
	else if (abs_val(draw->z[2]) >= 10)
		draw->color = PURPLE;
}

// x[3] = {x0 x1 dx} = {start end (end - start)}
void	draw_low(t_img *img, t_draw draw)
{
	int	d;
	int	yi;

	draw_precalc(&draw);
	yi = 1;
	if (draw.y[2] < 0)
	{
		yi = -1;
		draw.y[2] = -draw.y[2];
	}
	d = (2 * draw.y[2]) - draw.x[2];
	while (draw.x[0] != draw.x[1])
	{
		pixel_put(img, draw.x[0], draw.y[0], draw.color);
		if (d > 0)
		{
			draw.y[0] = draw.y[0] + yi;
			d = d + (2 * (draw.y[2] - draw.x[2]));
		}
		else
			d = d + 2 * draw.y[2];
		draw.x[0]++;
	}
}

void	draw_high(t_img *img, t_draw draw)
{
	int	d;
	int	xi;

	draw_precalc(&draw);
	xi = 1;
	if (draw.x[2] < 0)
	{
		xi = -1;
		draw.x[2] = -draw.x[2];
	}
	d = (2 * draw.x[2]) - draw.y[2];
	while (draw.y[0] != draw.y[1])
	{
		pixel_put(img, draw.x[0], draw.y[0], draw.color);
		if (d > 0)
		{
			draw.x[0] = draw.x[0] + xi;
			d = d + (2 * (draw.x[2] - draw.y[2]));
		}
		else
			d = d + 2 * draw.x[2];
		draw.y[0]++;
	}
}

// put pixel except if we're outside the window to prevent issues
void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= img->x || y >= img->y)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
