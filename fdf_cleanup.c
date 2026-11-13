/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_cleanup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cczerwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:23:55 by cczerwin          #+#    #+#             */
/*   Updated: 2025/03/04 18:23:57 by cczerwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mlx_close(t_data *mlx);
void	clear_screen(t_data *mlx);
void	int_cleanup(int **intmap, int line);
void	char_cleanup(char **charmap, int line);

int	mlx_close(t_data *mlx)
{
	if (mlx->img->img != NULL)
		mlx_destroy_image(mlx->mlx, mlx->img->img);
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx != NULL)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	if (mlx->map->map != NULL)
		int_cleanup(mlx->map->map, mlx->map->line);
	exit(0);
	return (0);
}

void	clear_screen(t_data *mlx)
{
	void	*black_screen;

	black_screen = mlx_new_image(mlx->mlx, mlx->x, mlx->y);
	mlx_put_image_to_window(mlx->mlx, mlx->win, black_screen, 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img,
		mlx->pos_x, mlx->pos_y);
	mlx_destroy_image(mlx->mlx, black_screen);
}

// could have bzero instead
void	int_cleanup(int **intmap, int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		if (intmap[i] != NULL)
			free(intmap[i]);
		i++;
	}
	free(intmap);
}

void	char_cleanup(char **charmap, int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		if (charmap[i] != NULL)
			free(charmap[i]);
		i++;
	}
	free(charmap);
}
