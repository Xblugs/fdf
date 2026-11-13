/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cczerwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:47:08 by cczerwin          #+#    #+#             */
/*   Updated: 2025/03/25 13:47:09 by cczerwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_splitcheck(char **split, size_t	wordcount);
size_t	ft_digitcount(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int		calc_height_delta(t_map *map);

// Copy pasted from ft_split: if a malloc fails, clear all
size_t	ft_splitcheck(char **split, size_t	wordcount)
{
	size_t	i;
	size_t	isvalid;

	i = 0;
	isvalid = 1;
	while (i < wordcount)
	{
		if (split[i] == NULL)
			isvalid = 0;
		i++;
	}
	if (isvalid == 0)
	{
		while (i > 0)
		{
			free(split[i]);
			i--;
		}
	}
	return (isvalid);
}

// Copy pasted from ft_split + consider '\n' the same as '\0'
size_t	ft_digitcount(char const *s, char c)
{
	size_t	i;
	size_t	new_word;
	size_t	count;

	i = 0;
	new_word = 0;
	count = 0;
	while (s[i] != 0 && s[i] != '\n')
	{
		if (s[i] != c && ft_isdigit(s[i]) && new_word == 0)
			new_word = 1;
		if (s[i] == c && new_word == 1)
		{
			new_word = 0;
			count++;
		}
		i++;
	}
	if ((s[i] == 0 || s[i] == '\n') && new_word == 1)
		count++;
	return (count);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = NULL;
	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

int	calc_height_delta(t_map *map)
{
	int	min;
	int	max;
	int	i;
	int	j;

	i = 0;
	min = map->map[0][0];
	max = map->map[0][0];
	while (i < map->line)
	{
		j = 0;
		while (j < map->col)
		{
			if (map->map[i][j] > max)
				max = map->map[i][j];
			if (map->map[i][j] < min)
				min = map->map[i][j];
			j++;
		}
		i++;
	}
	return (max - min);
}
