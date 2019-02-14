/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:24:58 by behiraux          #+#    #+#             */
/*   Updated: 2019/02/14 18:02:38 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	ft_deltab(char **tab)
{
	int i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free (tab);
}
