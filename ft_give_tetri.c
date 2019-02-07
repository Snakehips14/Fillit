/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:46:41 by behiraux          #+#    #+#             */
/*   Updated: 2019/02/07 17:47:29 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_tetri(char *str)
{
	int		i;
	int		nb;
	int		len;
	char	*s;

	printf("ok\n");
	s = ft_strdup(str);
	len = ft_strlen(str) - 10;
	i = 0;
	nb = 1;
	while (i < len - 10)
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			nb++;
		i++;
	}
	free(s);
	printf("nb = %d\n", nb);
	return (nb);
}

char	**ft_build_tetri(char *str)
{
	char	**tetri;
	int		t_nb;
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	t_nb = ft_count_tetri(str);
	if (!(tetri = (char **)malloc(sizeof(char *) * t_nb)))
		return (NULL);
	while (i < t_nb)
	{
		tetri[i] = ft_tetri(str, pos);
		pos = pos + 21;
		i++;
	}
	printf("et voila\n");
	return (tetri);
}

char	*ft_tetri(char *str, int pos)
{
	char	*s;
	char	*tetri;
	int		i;

	s = ft_strdup(str);
	if (!(tetri = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	i = 0;
	while (s[pos])
	{
		if (s[pos] == '\n' && (s[pos + 1] == '\n' || s[pos + 1] == '\0'))
		{
			tetri[i] = '\0';
			ft_strdel(&s);
			return (tetri);
		}
		tetri[i++] = s[pos++];
	}
	return (NULL);
}
