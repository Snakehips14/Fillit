/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:45:07 by behiraux          #+#    #+#             */
/*   Updated: 2019/02/07 17:40:15 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	*str;
	char	**tetri;
	int		i;
	int 	nb_t;

	i = 0;
	if (argc != 2)
	{
		ft_putendl("usage: executable argument");
		return (0);
	}
	str = ft_check_all(argv[1]);
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
	ft_putendl(str);
	tetri = ft_build_tetri(str);
	//ft_print_word_table(tetri);
	printf("str =\n%s", str);
	nb_t = ft_count_tetri(str);
	i = ft_check_all_3(tetri, str, nb_t);
	printf("i = %d\n", i);
	if (i == 0)
		return (0);
	return (0);
}
