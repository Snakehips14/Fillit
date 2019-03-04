/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:01:22 by behiraux          #+#    #+#             */
/*   Updated: 2019/03/04 15:04:06 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_pos_max_left(char *tetri)
{
	int i;
	int pos;
	int diese;

	i = 0;
	pos = 10;
	diese = 0;
	while (tetri[i])
	{
		if (tetri[i] == '#')
		{
			diese++;
			if (i % 4 < pos)
				pos = i % 4;
			if (diese == 4)
				return (pos);
		}
		i++;
	}
	return (pos);
}

static int	ft_pos_max_right(char *tetri)
{
	int i;
	int pos;
	int diese;

	i = 0;
	pos = 0;
	diese = 0;
	while (tetri[i])
	{
		if (tetri[i] == '#')
		{
			diese++;
			if (i % 4 > pos)
				pos = i % 4;
			if (diese == 4)
				return (pos);
		}
		i++;
	}
	return (pos);
}

static char	*ft_tetri_3d(char *tetri, int pos_left)
{
	char	*tetri_3d;
	int		i;
	int		j;
	int		x;
	int		diese;

	i = 0;
	j = ft_idxof(tetri, '#');
	x = j;
	diese = 0;
	if (!(tetri_3d = (char *)ft_strnew(sizeof(char) * 8)))
		return (NULL);
	while (j-- % 4 > pos_left)
		tetri_3d[i++] = '.';
	return (tetri_3d);
}

static char	*ft_tetri_3d2(char *tetri, char *tetri_3d, int pos_l, int pos_r)
{
	int i;
	int j;
	int x;

	i = 0;
	x = ft_idxof(tetri, '#');
	while (tetri_3d[i] == '.')
		i++;
	j = x % 4;
	while (i < 8)
	{
		while (j++ <= pos_r)
		{
			tetri_3d[i++] = tetri[x++];
			if (ft_strcount(tetri_3d, '#') == 4)
				return (tetri_3d);
		}
		while (x % 4 != pos_l)
			x++;
		j = pos_l;
		tetri_3d[i++] = '\n';
	}
	return (tetri_3d);
}

char		**ft_parse(char **tetri, int nb_t)
{
	int		left;
	int		right;
	int		i;
	char	**final_tetri;

	i = 0;
	if (!(final_tetri = (char **)malloc(sizeof(char *) * (nb_t + 1))))
		return (NULL);
	while (tetri[i] != 0)
	{
		left = ft_pos_max_left(tetri[i]);
		right = ft_pos_max_right(tetri[i]);
		final_tetri[i] = ft_tetri_3d(tetri[i], left);
		final_tetri[i] = ft_tetri_3d2(tetri[i], final_tetri[i], left, right);
		i++;
	}
	final_tetri[i] = 0;
	ft_deltab(tetri);
	return (final_tetri);
}
