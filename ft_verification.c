/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verification.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:18:18 by behiraux          #+#    #+#             */
/*   Updated: 2019/02/13 16:40:51 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_input(char *input, int pos)
{
	int		x;
	char	*str;
	int		len;
	int		i;

	str = ft_strdup(input);
	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		x = pos + 20;
		if (x > len)
			x = len;
		while (pos <= x)
		{
			if (i == len && str[i] == '\0')
				return (1);
			if ((pos == x || pos == (x - 1) || pos == (x - 6) ||
					pos == (x - 11) || pos == (x - 16)) && str[i] != '\n')
			{
				printf("i = %d len = %d et gros fail a pos %d\n", i, len, pos);
				ft_strdel(&str);
				return (0);
			}
			i++;
			pos++;
		}
		pos = 0;
	}
	return (1);
}

int	ft_check_tetri(char *input, int pos)
{
	char	*str;
	int		diese;
	int		x;
	int		len;
	int		i;

	str = ft_strdup(input);
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		diese = 0;
		x = pos + 20;
		if (x > len)
			x = len;
		while (pos <= x)
		{
			if (input[i] == '#')
				diese++;
			pos++;
			i++;
		}
		if (diese != 4)
		{
			printf("diese = %d, i = %d fail 2 a pos %d\n", diese, i, pos);
			ft_strdel(&str);
			return (0);
		}
		pos = 0;
	}
	return (1);
}

int		ft_check_all_2(char *file)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if ((i = ft_check_input(file, 0)) == 1)
	{
		if ((j = ft_check_tetri(file, 0)) == 1) 
		{
			printf("i = %d et j = %d\n", i, j);
			return (1);
		}
	}
	printf("str =\n%s", file);
	return (0);
}
