/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:43:38 by behiraux          #+#    #+#             */
/*   Updated: 2018/12/09 19:26:34 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (i < n && s1[i])
	{
		while (s2[j] == s1[i + j] && ((i + j) < n))
		{
			j++;
			if (!s2[j])
				return ((char *)s1 + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
