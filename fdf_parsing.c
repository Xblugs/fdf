/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cczerwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:55:14 by cczerwin          #+#    #+#             */
/*   Updated: 2025/03/03 18:55:16 by cczerwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**copy_map(char *file, int *i, int *j);
int		get_line_count(char *file);
void	check_map(char **map, int *fd, int *i, int *j);
int		convert_map(char **charmap, t_map *map);
void	convert_map2(char **charmap, t_map *map);

// Alloc ,copy and check char data
char	**copy_map(char *file, int *i, int *j)
{
	int		fd;
	char	**map;

	*i = get_line_count(file);
	if (*i <= 0)
		return (NULL);
	map = ft_calloc(*i, sizeof(char *));
	fd = open(file, O_RDONLY);
	if (map == NULL || fd == -1)
		return (ft_printf("\e[0;36mmalloc or open failed\n\e[0m"), NULL);
	check_map(map, &fd, i, j);
	close(fd);
	return (map);
}

void	check_map(char **map, int *fd, int *i, int *j)
{
	char	*ret;

	*i = 1;
	ret = get_next_line(*fd);
	map[0] = ft_strdup(ret);
	*j = ft_digitcount(map[0], ' ');
	while (ret != NULL)
	{
		free(ret);
		ret = get_next_line(*fd);
		if (ret != NULL)
		{
			map[*i] = ft_strdup(ret);
			if (*j > (int)ft_digitcount(map[*i], ' '))
				*j = ft_digitcount(map[*i], ' ');
		}
		*i = *i + 1;
	}
	*i = *i - 1;
	free(ret);
}

// needed to know how much to malloc later
// + print the source
int	get_line_count(char *file)
{
	int		fd;
	char	*ret;
	int		i;

	i = 0;
	ft_printf("\e[1;92mOpening \"%s\"\n\e[0m", file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	ret = get_next_line(fd);
	while (ret != NULL)
	{
		ft_printf("%s", ret);
		free(ret);
		ret = get_next_line(fd);
		i++;
	}
	free(ret);
	close(fd);
	ft_printf("\n\e[3;37mDone reading.\e[0m\n");
	return (i);
}

// memory allocation
int	convert_map(char **charmap, t_map *map)
{
	int	i;

	i = 0;
	map->map = ft_calloc((map->line), sizeof(int *));
	if (map->map == NULL)
		return (1);
	while (i < map->line)
	{
		map->map[i] = ft_calloc((map->col), sizeof(int));
		if (map->map[i] == NULL)
			return (1);
		i++;
	}
	convert_map2(charmap, map);
	return (0);
}

// memory filling
void	convert_map2(char **charmap, t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < map->line)
	{
		j = 0;
		k = 0;
		while (j < map->col)
		{
			while (!ft_isdigit(charmap[i][j + k]) && charmap[i][j + k] != '-')
				k++;
			map->map[i][j] = (int)ft_atoi(&charmap[i][j + k]);
			if (charmap[i][j + k] == '-')
				k++;
			k += ft_rec_expo(map->map[i][j]);
			j++;
		}
		i++;
	}
}
