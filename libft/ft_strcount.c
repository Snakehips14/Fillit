/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:57:59 by behiraux          #+#    #+#             */
/*   Updated: 2019/02/21 22:02:50 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcount(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
