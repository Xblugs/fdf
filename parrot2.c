/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parrot2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cczerwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:03:35 by cczerwin          #+#    #+#             */
/*   Updated: 2025/03/23 15:03:36 by cczerwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parrot_four(t_data *mlx);
void	parrot_five(t_data *mlx);
void	parrot_six(t_data *mlx);
void	parrot_seven(t_data *mlx);
void	parrot_eight(t_data *mlx);

void	parrot_four(t_data *mlx)
{
	int	x;
	int	y;

	x = mlx->x / 2;
	y = mlx->y / 2;
	ft_sleep();
	clear_screen(mlx);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 8), YELLOW, PARROT_F4_L1);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 7), YELLOW, PARROT_F4_L2);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 6), YELLOW, PARROT_F4_L3);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 5), YELLOW, PARROT_F4_L4);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 4), YELLOW, PARROT_F4_L5);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 3), YELLOW, PARROT_F4_L6);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 2), YELLOW, PARROT_F4_L7);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 1), YELLOW, PARROT_F4_L8);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 0), YELLOW, PARROT_F4_L9);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 1), YELLOW, PARROT_F4_LA);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 2), YELLOW, PARROT_F4_LB);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 3), YELLOW, PARROT_F4_LC);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 4), YELLOW, PARROT_F4_LD);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 5), YELLOW, PARROT_F4_LE);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 6), YELLOW, PARROT_F4_LF);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 7), YELLOW, PARROT_F4_LG);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 8), YELLOW, PARROT_F4_LH);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 9), YELLOW, PARROT_F4_LI);
}

void	parrot_five(t_data *mlx)
{
	int	x;
	int	y;

	x = mlx->x / 2;
	y = mlx->y / 2;
	ft_sleep();
	clear_screen(mlx);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 8), LIME, PARROT_F5_L1);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 7), LIME, PARROT_F5_L2);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 6), LIME, PARROT_F5_L3);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 5), LIME, PARROT_F5_L4);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 4), LIME, PARROT_F5_L5);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 3), LIME, PARROT_F5_L6);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 2), LIME, PARROT_F5_L7);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 1), LIME, PARROT_F5_L8);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 0), LIME, PARROT_F5_L9);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 1), LIME, PARROT_F5_LA);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 2), LIME, PARROT_F5_LB);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 3), LIME, PARROT_F5_LC);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 4), LIME, PARROT_F5_LD);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 5), LIME, PARROT_F5_LE);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 6), LIME, PARROT_F5_LF);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 7), LIME, PARROT_F5_LG);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 8), LIME, PARROT_F5_LH);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 9), LIME, PARROT_F5_LI);
}

void	parrot_six(t_data *mlx)
{
	int	x;
	int	y;

	x = mlx->x / 2;
	y = mlx->y / 2;
	ft_sleep();
	clear_screen(mlx);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 8), GREEN, PARROT_F6_L1);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 7), GREEN, PARROT_F6_L2);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 6), GREEN, PARROT_F6_L3);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 5), GREEN, PARROT_F6_L4);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 4), GREEN, PARROT_F6_L5);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 3), GREEN, PARROT_F6_L6);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 2), GREEN, PARROT_F6_L7);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 1), GREEN, PARROT_F6_L8);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 0), GREEN, PARROT_F6_L9);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 1), GREEN, PARROT_F6_LA);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 2), GREEN, PARROT_F6_LB);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 3), GREEN, PARROT_F6_LC);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 4), GREEN, PARROT_F6_LD);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 5), GREEN, PARROT_F6_LE);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 6), GREEN, PARROT_F6_LF);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 7), GREEN, PARROT_F6_LG);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 8), GREEN, PARROT_F6_LH);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 9), GREEN, PARROT_F6_LI);
}

void	parrot_seven(t_data *mlx)
{
	int	x;
	int	y;

	x = mlx->x / 2;
	y = mlx->y / 2;
	ft_sleep();
	clear_screen(mlx);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 8), CYAN, PARROT_F7_L1);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 7), CYAN, PARROT_F7_L2);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 6), CYAN, PARROT_F7_L3);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 5), CYAN, PARROT_F7_L4);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 4), CYAN, PARROT_F7_L5);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 3), CYAN, PARROT_F7_L6);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 2), CYAN, PARROT_F7_L7);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 1), CYAN, PARROT_F7_L8);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 0), CYAN, PARROT_F7_L9);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 1), CYAN, PARROT_F7_LA);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 2), CYAN, PARROT_F7_LB);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 3), CYAN, PARROT_F7_LC);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 4), CYAN, PARROT_F7_LD);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 5), CYAN, PARROT_F7_LE);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 6), CYAN, PARROT_F7_LF);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 7), CYAN, PARROT_F7_LG);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 8), CYAN, PARROT_F7_LH);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 9), CYAN, PARROT_F7_LI);
}

void	parrot_eight(t_data *mlx)
{
	int	x;
	int	y;

	x = mlx->x / 2;
	y = mlx->y / 2;
	ft_sleep();
	clear_screen(mlx);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 8), BLUE, PARROT_F8_L1);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 7), BLUE, PARROT_F8_L2);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 6), BLUE, PARROT_F8_L3);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 5), BLUE, PARROT_F8_L4);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 4), BLUE, PARROT_F8_L5);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 3), BLUE, PARROT_F8_L6);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 2), BLUE, PARROT_F8_L7);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 1), BLUE, PARROT_F8_L8);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 0), BLUE, PARROT_F8_L9);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 1), BLUE, PARROT_F8_LA);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 2), BLUE, PARROT_F8_LB);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 3), BLUE, PARROT_F8_LC);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 4), BLUE, PARROT_F8_LD);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 5), BLUE, PARROT_F8_LE);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 6), BLUE, PARROT_F8_LF);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 7), BLUE, PARROT_F8_LG);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 8), BLUE, PARROT_F8_LH);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 9), BLUE, PARROT_F8_LI);
}
