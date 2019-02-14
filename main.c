/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:45:07 by behiraux          #+#    #+#             */
/*   Updated: 2019/02/14 18:02:42 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	*str;
	char	**tetri;
	char	**map;
	int		i;
	int 	nb_t;

	i = 0;
	if (argc != 2)
	{
		ft_putendl("usage: executable argument");
		return (0);
	}
	str = ft_check_all(argv[1]); 
	if (str	== NULL)
	{
		printf("erreur de lecture");
		return (0);
	}
	if ((i = ft_check_all_2(str)) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	else
	{
		ft_putendl("c'est correct");
		printf("i = %d\n", i);
	}
	nb_t = ft_count_tetri(str);
	tetri = ft_build_tetri(str);
	printf("et\n");
	ft_print_word_table(tetri);
	printf("voila\n");
	i = ft_check_all_3(tetri, nb_t);
	printf("LOOOL\n");
	if (i == 0)
	{
		printf("erreur de forme de tetri\n");
		return (0);
	}
	printf("tests valides\n");
	map = ft_map(nb_t);
	printf("haha\n");
	ft_print_word_table(map);
	printf("hoho\n");
	tetri = ft_parse(tetri, nb_t);
	ft_print_word_table(tetri);
	return (0);
}
