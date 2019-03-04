/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:21:11 by behiraux          #+#    #+#             */
/*   Updated: 2019/02/26 18:20:51 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	if (!(s = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (i <= size)
		s[i++] = 0;
	return ((void *)s);
}
