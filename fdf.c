/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cczerwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:13:47 by cczerwin          #+#    #+#             */
/*   Updated: 2025/02/21 16:13:50 by cczerwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_map(char *file, t_map *map);
// fdf_parsing is debording

// read data from file and return int**
int	get_map(char *file, t_map *map)
{
	char	**charmap;
	int		val;

	charmap = copy_map(file, &map->line, &map->col);
	if (charmap == NULL)
		return (1);
	val = ft_splitcheck(charmap, map->line - 1);
	if (val == 0)
		return (ft_printf("\e[31mCopy_map malloc failed\e[0m\n"), 1);
	ft_printf("\e[1;31mClosing \"%s\"\n\e[0m", file);
	ft_printf("\e[1;37m%d lines found of %d symbols\n", map->line, map->col);
	val = convert_map(charmap, map);
	char_cleanup(charmap, map->line);
	if (val == 1)
		return (ft_printf("\e[31mConvert_map malloc failed\e[0m\n"), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	mlx;
	t_img	img;
	t_draw	draw;
	t_map	map;
	int		val;

	if (argc == 2)
	{
		val = get_map(argv[1], &map);
		if (val != 0)
			ft_printf("\e[1;31mIncorrect file or format, closing\e[0m\n");
		else
		{
			data_init(&mlx, &img, &draw, &map);
			draw_isometric(&mlx, &draw, &map);
			mlx_loop(mlx.mlx);
		}
	}
	return (0);
}
