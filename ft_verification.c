/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verification.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:18:18 by behiraux          #+#    #+#             */
/*   Updated: 2019/03/04 14:22:41 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_input(char *input, int pos)
{
	int		x;
	int		len;
	int		i;

	len = ft_strlen(input);
	i = 0;
	while (i < len)
	{
		x = pos + 20;
		if (x > len)
			x = len;
		while (pos <= x)
		{
			if (i == len && input[i] == '\0')
				return (1);
			if ((pos == x || pos == (x - 1) || pos == (x - 6) ||
					pos == (x - 11) || pos == (x - 16)) && input[i] != '\n')
				return (0);
			i++;
			pos++;
		}
		pos = 0;
	}
	return (1);
}

static int	ft_check_tetri(char *input, int pos)
{
	int		diese;
	int		x;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(input);
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
			return (0);
		pos = 0;
	}
	return (1);
}

int			ft_verification(char *file)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if ((i = ft_check_input(file, 0)) == 1)
	{
		if ((j = ft_check_tetri(file, 0)) == 1)
			return (1);
	}
	free(file);
	return (0);
}
