/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_word_table_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:46:37 by behiraux          #+#    #+#             */
/*   Updated: 2018/11/22 17:48:17 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_word_table_fd(char **str, int fd)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putstr_fd(str[i], fd);
		i++;
	}
}
