/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:45:07 by behiraux          #+#    #+#             */
/*   Updated: 2019/03/04 14:27:56 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_error(int i)
{
	ft_putendl("usage: ./fillit source_file");
	return (i);
}

int			main(int argc, char **argv)
{
	char	*str;
	char	**tetri;
	char	*map;
	int		nb_t;

	if (argc != 2)
		return (ft_error(0));
	if ((str = ft_read(argv[1])) == NULL || ft_verification(str) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	nb_t = ft_count_tetri(str);
	tetri = ft_split(str);
	if (ft_check_pos_hash(tetri, nb_t) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	tetri = ft_parse(tetri, nb_t);
	map = ft_map(nb_t, tetri);
	ft_putendl(map);
	free(map);
	ft_deltab(tetri);
	return (0);
}
