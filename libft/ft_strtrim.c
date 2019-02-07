/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:35:56 by behiraux          #+#    #+#             */
/*   Updated: 2018/11/21 18:17:23 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		l;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	while (s[i] && (s[l - 1] == ' ' || s[l - 1] == '\t' || s[l - 1] == '\n'))
		l--;
	str = ft_strsub(s, i, l - i);
	if (str)
		return (str);
	return (NULL);
}
