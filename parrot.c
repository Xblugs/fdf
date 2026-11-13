/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parrot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cczerwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:49:32 by cczerwin          #+#    #+#             */
/*   Updated: 2025/03/23 14:49:34 by cczerwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_parrot(t_data *mlx);
void	parrot_zero(t_data *mlx);
void	parrot_one(t_data *mlx);
void	parrot_two(t_data *mlx);
void	parrot_three(t_data *mlx);

void	ft_parrot(t_data *mlx)
{
	int	i;

	i = 0;
	ft_printf("\e[3;35mCoco \e[3;31mwant \e[3;36mbiscuit!\e[0m 🦜\n");
	while (i < 5)
	{
		parrot_zero(mlx);
		parrot_one(mlx);
		parrot_two(mlx);
		parrot_three(mlx);
		parrot_four(mlx);
		parrot_five(mlx);
		parrot_six(mlx);
		parrot_seven(mlx);
		parrot_eight(mlx);
		parrot_nine(mlx);
		i++;
	}
	clear_screen(mlx);
}

//I should have put the COLOR in (int z) for easier color palette testing
void	parrot_zero(t_data *mlx)
{
	int	x;
	int	y;

	x = mlx->x / 2;
	y = mlx->y / 2;
	ft_sleep();
	clear_screen(mlx);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 8), WHITE, PARROT_F0_L1);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 7), WHITE, PARROT_F0_L2);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 6), WHITE, PARROT_F0_L3);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 5), WHITE, PARROT_F0_L4);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 4), WHITE, PARROT_F0_L5);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 3), WHITE, PARROT_F0_L6);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 2), WHITE, PARROT_F0_L7);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 1), WHITE, PARROT_F0_L8);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 0), WHITE, PARROT_F0_L9);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 1), WHITE, PARROT_F0_LA);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 2), WHITE, PARROT_F0_LB);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 3), WHITE, PARROT_F0_LC);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 4), WHITE, PARROT_F0_LD);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 5), WHITE, PARROT_F0_LE);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 6), WHITE, PARROT_F0_LF);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 7), WHITE, PARROT_F0_LG);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 8), WHITE, PARROT_F0_LH);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 9), WHITE, PARROT_F0_LI);
}

void	parrot_one(t_data *mlx)
{
	int	x;
	int	y;

	x = mlx->x / 2;
	y = mlx->y / 2;
	ft_sleep();
	clear_screen(mlx);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 8), PURPLE, PARROT_F1_L1);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 7), PURPLE, PARROT_F1_L2);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 6), PURPLE, PARROT_F1_L3);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 5), PURPLE, PARROT_F1_L4);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 4), PURPLE, PARROT_F1_L5);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 3), PURPLE, PARROT_F1_L6);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 2), PURPLE, PARROT_F1_L7);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 1), PURPLE, PARROT_F1_L8);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 0), PURPLE, PARROT_F1_L9);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 1), PURPLE, PARROT_F1_LA);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 2), PURPLE, PARROT_F1_LB);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 3), PURPLE, PARROT_F1_LC);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 4), PURPLE, PARROT_F1_LD);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 5), PURPLE, PARROT_F1_LE);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 6), PURPLE, PARROT_F1_LF);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 7), PURPLE, PARROT_F1_LG);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 8), PURPLE, PARROT_F1_LH);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 9), PURPLE, PARROT_F1_LI);
}

void	parrot_two(t_data *mlx)
{
	int	x;
	int	y;

	x = mlx->x / 2;
	y = mlx->y / 2;
	ft_sleep();
	clear_screen(mlx);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 8), RED, PARROT_F2_L1);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 7), RED, PARROT_F2_L2);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 6), RED, PARROT_F2_L3);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 5), RED, PARROT_F2_L4);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 4), RED, PARROT_F2_L5);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 3), RED, PARROT_F2_L6);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 2), RED, PARROT_F2_L7);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 1), RED, PARROT_F2_L8);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 0), RED, PARROT_F2_L9);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 1), RED, PARROT_F2_LA);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 2), RED, PARROT_F2_LB);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 3), RED, PARROT_F2_LC);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 4), RED, PARROT_F2_LD);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 5), RED, PARROT_F2_LE);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 6), RED, PARROT_F2_LF);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 7), RED, PARROT_F2_LG);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 8), RED, PARROT_F2_LH);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 9), RED, PARROT_F2_LI);
}

void	parrot_three(t_data *mlx)
{
	int	x;
	int	y;

	x = mlx->x / 2;
	y = mlx->y / 2;
	ft_sleep();
	clear_screen(mlx);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 8), ORANGE, PARROT_F3_L1);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 7), ORANGE, PARROT_F3_L2);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 6), ORANGE, PARROT_F3_L3);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 5), ORANGE, PARROT_F3_L4);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 4), ORANGE, PARROT_F3_L5);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 3), ORANGE, PARROT_F3_L6);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 2), ORANGE, PARROT_F3_L7);
	mlx_string_put(mlx->mlx, mlx->win, x, y - (16 * 1), ORANGE, PARROT_F3_L8);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 0), ORANGE, PARROT_F3_L9);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 1), ORANGE, PARROT_F3_LA);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 2), ORANGE, PARROT_F3_LB);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 3), ORANGE, PARROT_F3_LC);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 4), ORANGE, PARROT_F3_LD);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 5), ORANGE, PARROT_F3_LE);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 6), ORANGE, PARROT_F3_LF);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 7), ORANGE, PARROT_F3_LG);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 8), ORANGE, PARROT_F3_LH);
	mlx_string_put(mlx->mlx, mlx->win, x, y + (16 * 9), ORANGE, PARROT_F3_LI);
}
