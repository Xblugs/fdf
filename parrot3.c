/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parrot3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cczerwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:00:36 by cczerwin          #+#    #+#             */
/*   Updated: 2025/03/23 16:00:37 by cczerwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parrot_nine(t_data *mlx);
void	ft_42(t_data *mlx);

void	parrot_nine(t_data *mlx)
{
	int	x;
	int	y;

	x = mlx->x / 2;
	y = mlx->y / 2;
	ft_sleep();
	clear_screen(mlx);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 8), BROWN, PARROT_F9_L1);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 7), BROWN, PARROT_F9_L2);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 6), BROWN, PARROT_F9_L3);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 5), BROWN, PARROT_F9_L4);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 4), BROWN, PARROT_F9_L5);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 3), BROWN, PARROT_F9_L6);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 2), BROWN, PARROT_F9_L7);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 1), BROWN, PARROT_F9_L8);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 0), BROWN, PARROT_F9_L9);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 1), BROWN, PARROT_F9_LA);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 2), BROWN, PARROT_F9_LB);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 3), BROWN, PARROT_F9_LC);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 4), BROWN, PARROT_F9_LD);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 5), BROWN, PARROT_F9_LE);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 6), BROWN, PARROT_F9_LF);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 7), BROWN, PARROT_F9_LG);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 8), BROWN, PARROT_F9_LH);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 9), BROWN, PARROT_F9_LI);
}

// completely not a function hiding
void	ft_42(t_data *mlx)
{
	int	x;
	int	y;

	x = mlx->x / 6;
	y = mlx->y / 2;
	mlx_string_put(mlx->mlx, mlx->win, x, y - 48, CYAN, HEAD1);
	mlx_string_put(mlx->mlx, mlx->win, x, y - 32, CYAN, HEAD2);
	mlx_string_put(mlx->mlx, mlx->win, x, y - 16, CYAN, HEAD3);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 0, CYAN, HEAD4);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 16, CYAN, HEAD5);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 32, CYAN, HEAD6);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 48, CYAN, HEAD7);
}
