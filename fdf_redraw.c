/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_translation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cczerwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:42:44 by cczerwin          #+#    #+#             */
/*   Updated: 2025/03/26 17:42:46 by cczerwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_handler(int keycode, t_data *mlx);
void	translation_handler(int keycode, t_data *mlx);
void	zoom_handler(int mouse, t_data *mlx);
void	rotation_handler(int keycode, t_data *mlx);
void	reset_handler(int keycode, t_data *mlx);

// Actually doesn't redraw the whole picture
// is CPU friendly
void	move_handler(int keycode, t_data *mlx)
{
	if (keycode == NUM_UP)
		mlx->pos_y -= mlx->y / 10;
	else if (keycode == NUM_DOWN)
		mlx->pos_y += mlx->y / 10;
	else if (keycode == NUM_LEFT)
		mlx->pos_x -= mlx->x / 10;
	else if (keycode == NUM_RIGHT)
		mlx->pos_x += mlx->x / 10;
	else if (keycode == NUM_MID)
	{
		mlx->pos_x = 0;
		mlx->pos_y = 0;
	}
	ft_printf("\n\e[5;95mMoving image...\e[0m\n");
	ft_printf("\e[95mImage Offset (x,y) = (%d,%d)\e[0m\n", mlx->pos_x,
		mlx->pos_y);
	clear_screen(mlx);
}

// Actually redraw the whole picture
// isn't CPU friendly
void	translation_handler(int keycode, t_data *mlx)
{
	if (keycode == UP)
		mlx->draw->off_y -= mlx->y / 10;
	else if (keycode == DOWN)
		mlx->draw->off_y += mlx->y / 10;
	else if (keycode == LEFT)
		mlx->draw->off_x -= mlx->x / 10;
	else if (keycode == RIGHT)
		mlx->draw->off_x += mlx->x / 10;
	else if (keycode == NUM_ZERO)
	{
		mlx->draw->off_x = 0;
		mlx->draw->off_y = 0;
	}
	ft_printf("\n\e[5;93mTranslation...\e[0m\n");
	ft_printf("\e[93mOffset (x,y) = (%d,%d)\e[0m\n", mlx->draw->off_x,
		mlx->draw->off_y);
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	mlx->img->img = mlx_new_image(mlx->mlx, mlx->x, mlx->y);
	draw_isometric(mlx, mlx->draw, mlx->map);
}

// 1 = left_click, 4 = scroll_up , 5 = scroll_down, 2 = wheel_click
void	zoom_handler(int mouse, t_data *mlx)
{
	if (mouse == 5)
		mlx->draw->scale--;
	else if (mouse == 4)
		mlx->draw->scale++;
	else if (mouse == 2)
		mlx->draw->scale = 1;
	ft_printf("\n\e[5;94mZoom...\e[0m\n");
	ft_printf("\e[94mScaling = %d\e[0m\n", mlx->draw->scale);
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	mlx->img->img = mlx_new_image(mlx->mlx, mlx->x, mlx->y);
	draw_isometric(mlx, mlx->draw, mlx->map);
}

void	rotation_handler(int keycode, t_data *mlx)
{
	if (keycode == 'a')
		mlx->draw->angle_off -= 10;
	else if (keycode == 'd')
		mlx->draw->angle_off += 10;
	else if (keycode == 'x')
		mlx->draw->angle_off = 0;
	if (mlx->draw->angle_off == 360 || mlx->draw->angle_off == -360)
		mlx->draw->angle_off = 0;
	ft_printf("\n\e[5;92mRotation...\e[0m\n");
	ft_printf("\e[92mAngle offset = %d\e[0m\n", mlx->draw->angle_off);
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	mlx->img->img = mlx_new_image(mlx->mlx, mlx->x, mlx->y);
	draw_isometric(mlx, mlx->draw, mlx->map);
}

void	reset_handler(int keycode, t_data *mlx)
{
	if (keycode == SPACE)
	{
		mlx->pos_x = 0;
		mlx->pos_y = 0;
		mlx->draw->off_x = 0;
		mlx->draw->off_y = 0;
		mlx->draw->scale = 1;
		mlx->draw->angle_off = 0;
	}
	ft_printf("\n\e[1;37mReset view...\e[0m\n");
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	mlx->img->img = mlx_new_image(mlx->mlx, mlx->x, mlx->y);
	draw_isometric(mlx, mlx->draw, mlx->map);
}
