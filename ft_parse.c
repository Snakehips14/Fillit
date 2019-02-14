/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:17:13 by behiraux          #+#    #+#             */
/*   Updated: 2019/02/14 17:58:21 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_pos_max_left(char *tetri)
{
	int		i;
	int		y;
	int		pos;
	int		diese;

	i = 0;
	y = 0;
	pos = 30;
	diese = 0;
	while (tetri[i])
	{
		if (tetri[i] == '#')
		{
			diese++;
			if (y < pos)
				pos = y;
			if (diese == 4)
				return (pos);
		}
		i++;
		y++;
		if (tetri[i] == '\n')
			y = -1;
	}
	return (pos);
}

int		ft_compare(char *tetri)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tetri[i] != '#')
	{
		if (tetri[i] == '\n')
			j = -1;
		j++;
		i++;
	}
	return (j);
}

char	*ft_tetri_2d(char *tetri, int pos, int j)
{
	char	*tetri_2d;
	int		i;
	int		x;

	i = ft_idxof(tetri, '#');
	x = 0;
	if (!(tetri_2d = (char *)malloc(sizeof(char) * 14)))
		return (NULL);
	while (j-- > pos)
		tetri_2d[x++] = '.';
	while (x < 13)
	{
		while (tetri[i] && x < 13)
		{
			if (tetri[i] == '#' || tetri[i] == '.')
				tetri_2d[x++] = tetri[i++];
			else
				i++;
		}
		if (x < 13)
			tetri_2d[x++] = '.';
	}
	tetri_2d[x] = '\0';
	return (tetri_2d);
}

char	*ft_tetri_letter(char *tetri_2d, char c)
{
	int i;

	i = 0;
	while (tetri_2d[i])
	{
		if (tetri_2d[i] == '#')
			tetri_2d[i] = c;
		i++;
	}
	return (tetri_2d);
}

char	**ft_parse(char **tetri, int nb_t)
{
	int		i;
	int		j;
	int		pos;
	char	**final_tetri;
	char	c;

	i = 0;
	c = 'A';
	if (!(final_tetri = (char **)ft_memalloc(sizeof(char *) * (nb_t + 1))))
		return (NULL);
	while (tetri[i] != 0)
	{
		j = ft_compare(tetri[i]);
		pos = ft_pos_max_left(tetri[i]);
		final_tetri[i] = ft_tetri_2d(tetri[i], pos, j);
		final_tetri[i] = ft_tetri_letter(final_tetri[i], c);
		c++;
		i++;
	}
	final_tetri[i] = 0;
	ft_deltab(tetri);
	return (final_tetri);
}

/*int		main(void)
{
	char	*tetri_2d;
	int		pos;
	int		j;
	char	*str = "....\n##..\n.##.\n....";
	char	*str2 = "..#.\n..#.\n..#.\n..#.";
	char	*str3 = "....\n....\n####\n....";
	char	*str4 = "....\n.##.\n.##.\n....";
	char	*str5 = "....\n....\n.###\n...#";
	char	*str6 = "....\n.###\n..#.\n....";
	char	*str7 = ".##.\n##..\n....\n....";
	char	*str8 = "..#.\n.###\n....\n....";
	char	*str9 = "....\n....\n....\n####";

	j = ft_compare(str7);
	pos = ft_pos_max_left(str7);
	printf("pos = %d\n", pos);
	tetri_2d = ft_tetri_2d(str7, pos, j);
	printf("tetri = %s\n", tetri_2d);
	tetri_2d = ft_tetri_letter(tetri_2d, 'A');
	printf("tetri = %s\n", tetri_2d);


	return (0);
}*/
