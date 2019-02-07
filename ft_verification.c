/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verification.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:18:18 by behiraux          #+#    #+#             */
/*   Updated: 2019/02/07 17:51:35 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_input(char *input, int pos)
{
	int		x;
	char	*str;
	int		len;

	str = ft_strdup(input);
	len = ft_strlen(str);
	x = pos + 20;
	if (x > len)
		x = len;
	while (pos <= x)
	{
		if ((pos == x || pos == (x - 1) || pos == (x - 6) ||
				pos == (x - 11) || pos == (x - 16)) && str[pos] != '\n')
		{
			printf("fail a pos %d\n", pos);
			ft_strdel(&str);
			return (0);
		}
		if (str[pos] == '\n' && str[pos + 1] == '\0' && pos == len - 1)
		{
			ft_strdel(&str);
			return (1);
		}
		pos++;
	}
	ft_check_input(str, pos);
	return (1);
}

int	ft_check_tetri(char *input, int pos)
{
	int		diese;
	int		x;
	int		len;

	diese = 0;
	len = ft_strlen(input);
	x = pos + 20;
	if (x > len)
		x = len;
	while (pos <= x)
	{
		if (input[pos] == '#')
			diese++;
		pos++;
	}
	if (diese != 4)
	{
		printf("fail 2 a pos %d\n", pos);
		return (0);
	}
	if (pos == len + 1)
		return (1);
	ft_check_tetri(input, pos);
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
