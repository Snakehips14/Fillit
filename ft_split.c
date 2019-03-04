/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:46:41 by behiraux          #+#    #+#             */
/*   Updated: 2019/03/04 15:02:34 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_count_tetri(char *str)
{
	int		i;
	int		nb;
	int		len;

	len = ft_strlen(str) - 10;
	i = 0;
	nb = 1;
	while (i < len - 10)
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			nb++;
		i++;
	}
	return (nb);
}

static char	*ft_tetri(char *str, int pos)
{
	char	*tetri;
	int		i;

	if (!(tetri = (char *)malloc(sizeof(char) * (16 + 1))))
		return (NULL);
	i = 0;
	while (str[pos])
	{
		if (str[pos] == '\n' && (str[pos + 1] == '\n' || str[pos + 1] == '\0'))
		{
			tetri[i] = '\0';
			return (tetri);
		}
		if (str[pos] != '\n')
			tetri[i++] = str[pos];
		pos++;
	}
	return (NULL);
}

char		**ft_split(char *str)
{
	char	**tetri;
	int		t_nb;
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	t_nb = ft_count_tetri(str);
	if (!(tetri = (char **)malloc(sizeof(char *) * (t_nb + 1))))
		return (NULL);
	while (i < t_nb)
	{
		tetri[i] = ft_tetri(str, pos);
		pos = pos + 21;
		i++;
	}
	tetri[i] = NULL;
	free(str);
	return (tetri);
}
