/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cczerwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:12:31 by cczerwin          #+#    #+#             */
/*   Updated: 2024/12/28 13:12:34 by cczerwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c);
int	ft_isset(char const *s, char const *set);
int	ft_int_strlen(const char *s);

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isset(char const *s, char const *set)
{
	char	*iset;

	if (set == NULL)
		return (1);
	iset = (char *)set;
	while (*iset != 0)
	{
		if (*iset == (char)*s)
			return (1);
		iset++;
	}
	return (0);
}

int	ft_int_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
