/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cczerwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:45:39 by cczerwin          #+#    #+#             */
/*   Updated: 2025/02/27 11:45:43 by cczerwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		abs_val(int val);
double	deg_to_rad(double angle);
double	rad_to_deg(double radian);
void	invert_coordinates(t_draw *draw);
void	ft_sleep(void);

int	abs_val(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

// M_PI defined in math.h
double	deg_to_rad(double angle)
{
	return ((angle) * M_PI / 180.0);
}

double	rad_to_deg(double radian)
{
	return ((radian) * 180.0 / M_PI);
}

void	invert_coordinates(t_draw *draw)
{
	int	swap;

	swap = draw->x[0];
	draw->x[0] = draw->x[1];
	draw->x[1] = swap;
	swap = draw->y[0];
	draw->y[0] = draw->y[1];
	draw->y[1] = swap;
}

// VERY hacky solution to replace the real sleep()
// O3 flag kills this function
void	ft_sleep(void)
{
	unsigned long	i;

	i = 0;
	while (i < 3e7)
		i++;
}
