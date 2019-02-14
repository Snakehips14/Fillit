/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:37:50 by behiraux          #+#    #+#             */
/*   Updated: 2019/02/14 17:47:13 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrtmap(int nb_t)
{
	int i;

	i = 2;
	nb_t = nb_t * 4;
	while (i * i < nb_t)
		i++;
	return (i);
}

char	**ft_map(int nb_t)
{
	int		x;
	int		y;
	int		size;
	char	**map;

	x = 0;
	y = 0;
	size = ft_sqrtmap(nb_t);
	if (!(map = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	while (x < size)
	{
		if (!(map[x] = (char *)malloc(sizeof(char *) * (size + 1))))
			return (NULL);
		x++;
	}
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
			map[x][y++] = '.';
		map[x][y] = '\0';
		x++;
	}
	return (map);
}

char	**ft_expand_map(char **map, int size)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(map = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	while (x < size)
	{
		if (!(map[x] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		x++;
	}
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
			map[x][y++] = '.';
		map[x][y] = '\0';
		x++;
	}
	return (map);	
}
