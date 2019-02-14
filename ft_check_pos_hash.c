/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pos_hash.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:01:41 by behiraux          #+#    #+#             */
/*   Updated: 2019/02/14 16:45:39 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_shape(int *t)
{
	if ((t[1] == t[0] + 1 && t[2] == t[1] + 3 && t[3] == t[2] + 1) ||
			(t[1] == t[0] + 1 && t[2] == t[1] + 5 && t[3] == t[2] + 1) ||
			(t[1] == t[0] + 5 && t[2] == t[1] + 1 && t[3] == t[2] + 5) ||
			(t[1] == t[0] + 4 && t[2] == t[1] + 1 && t[3] == t[2] + 4) ||
			(t[1] == t[0] + 1 && t[2] == t[1] + 4 && t[3] == t[2] + 5) ||
			(t[1] == t[0] + 1 && t[2] == t[1] + 1 && t[3] == t[2] + 5) ||
			(t[1] == t[0] + 5 && t[2] == t[1] + 4 && t[3] == t[2] + 1) ||
			(t[1] == t[0] + 5 && t[2] == t[1] + 1 && t[3] == t[2] + 1) ||
			(t[1] == t[0] + 5 && t[2] == t[1] + 5 && t[3] == t[2] + 5) ||
			(t[1] == t[0] + 1 && t[2] == t[1] + 1 && t[3] == t[2] + 1) ||
			(t[1] == t[0] + 1 && t[2] == t[1] + 4 && t[3] == t[2] + 1) ||
			(t[1] == t[0] + 4 && t[2] == t[1] + 1 && t[3] == t[2] + 1) ||
			(t[1] == t[0] + 1 && t[2] == t[1] + 1 && t[3] == t[2] + 4) ||
			(t[1] == t[0] + 4 && t[2] == t[1] + 1 && t[3] == t[2] + 5) ||
			(t[1] == t[0] + 5 && t[2] == t[1] + 1 && t[3] == t[2] + 4) ||
			(t[1] == t[0] + 5 && t[2] == t[1] + 5 && t[3] == t[2] + 1) ||
			(t[1] == t[0] + 1 && t[2] == t[1] + 5 && t[3] == t[2] + 5) ||
			(t[1] == t[0] + 1 && t[2] == t[1] + 1 && t[3] == t[2] + 3) ||
			(t[1] == t[0] + 3 && t[2] == t[1] + 1 && t[3] == t[2] + 1))
		return (1);
	return (0);
}

int		ft_check_all_3(char **tetri, int nb_t)
{
	int		tab[4];
	int		ret;
	int		i;
	int		j;
	int		k;

	printf("nb_t = %d\n", nb_t);
	j = 0;
	while (j < nb_t)
	{
		i = 0;
		k = 0;
		while (tetri[j][k])
		{
			if (tetri[j][k] == '#')
				tab[i++] = k;
			k++;
		}
		if ((ret = ft_check_shape(tab)) == 0)
		{
			printf("mauvais tetri numero %d\n", j + 1);
			return (0);
		}
		j++;
	}
	return (1);
}
