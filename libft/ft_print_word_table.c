/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_word_table.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:41:16 by behiraux          #+#    #+#             */
/*   Updated: 2019/02/07 17:45:23 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_word_table(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		ft_putstr(str[i]);
		ft_putchar('\n');
		ft_putchar('\n');
		i++;
	}
}
