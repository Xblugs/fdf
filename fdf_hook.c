/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cczerwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:26:40 by cczerwin          #+#    #+#             */
/*   Updated: 2025/02/27 12:26:42 by cczerwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_hook(t_data *mlx);
int		mouse_io(t_data *mlx);
int		mouse_handler(int button, int x, int y, t_data *mlx);
int		key_handler(int keycode, t_data *mlx);
int		s_key_handler(int keycode, t_data *mlx);

void	set_hook(t_data *mlx)
{
	mlx_key_hook(mlx->win, &key_handler, mlx);
	mlx_hook(mlx->win, ON_ENTER, 1L << 4, &mouse_io, mlx);
	mlx_hook(mlx->win, ON_LEAVE, 1L << 5, &mouse_io, NULL);
	mlx_hook(mlx->win, ON_DESTROY, 0L, &mlx_close, mlx);
	mlx_mouse_hook(mlx->win, &mouse_handler, mlx);
}

int	mouse_io(t_data *mlx)
{
	if (mlx != NULL)
		ft_printf("\e[0;36mCursor locked in!\n\e[0m");
	else if (mlx == NULL)
		ft_printf("\e[0;35mCursor escaped!\n\e[0m");
	return (0);
}

// 1 = left_click, 4 = scroll_up , 5 = scroll_down, 2 = wheel_click
int	mouse_handler(int mouse, int x, int y, t_data *mlx)
{
	if (mouse == 1)
		ft_printf("Cursor at (x, y) = [%d, %d]\n", x, y);
	else if (mouse == 4 || mouse == 5 || mouse == 2)
		zoom_handler(mouse, mlx);
	return (0);
}

//mlx_mouse_hide() leaks :(
/*
else if (keycode == 'h')
		mlx_mouse_hide(mlx->mlx, mlx->win);
else if (keycode == 'm')
		mlx_mouse_show(mlx->mlx, mlx->win);
*/
int	key_handler(int keycode, t_data *mlx)
{
	if (keycode == ESC)
	{
		ft_printf("%c[31mESC pressed, closing...\n\e[0m", keycode);
		mlx_close(mlx);
	}
	else if (keycode >= 0xFF00)
		s_key_handler(keycode, mlx);
	else if (keycode == SPACE)
		reset_handler(keycode, mlx);
	else if (keycode == 'a' || keycode == 'd' || keycode == 'x')
		rotation_handler(keycode, mlx);
	if (keycode != ENTER)
		ft_printf("Key press = [%d 0x%X '%c']\n", keycode, keycode, keycode);
	return (0);
}

int	s_key_handler(int keycode, t_data *mlx)
{
	if (keycode == NUM_UP || keycode == NUM_MID || keycode == NUM_DOWN)
		move_handler(keycode, mlx);
	else if (keycode == NUM_LEFT || keycode == NUM_RIGHT)
		move_handler(keycode, mlx);
	else if ((keycode >= LEFT && keycode <= DOWN) || keycode == NUM_ZERO)
		translation_handler(keycode, mlx);
	else if (keycode == F1 || keycode == F2)
		ft_42(mlx);
	else if (keycode == F3)
		ft_parrot(mlx);
	return (0);
}
