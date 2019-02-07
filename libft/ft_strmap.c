/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:36:17 by behiraux          #+#    #+#             */
/*   Updated: 2018/11/19 17:09:32 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s2;

	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	if (!(s2 = (char *)malloc(sizeof(*s2) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		s2[i] = (*f)(s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
