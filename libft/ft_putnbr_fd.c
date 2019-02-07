/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:56:18 by behiraux          #+#    #+#             */
/*   Updated: 2018/11/27 19:45:37 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int i;

	i = 1000000000;
	if ((-2147483648 < nb) && (nb < 0))
	{
		ft_putchar_fd('-', fd);
		nb = nb * (-1);
	}
	if ((0 <= nb) && (nb <= 2147483647))
	{
		while (i > nb)
			i = i / 10;
		while (i > 1)
		{
			ft_putchar_fd(((nb / i) + '0'), fd);
			nb = nb % i;
			i = i / 10;
		}
		ft_putchar_fd((nb + '0'), fd);
	}
	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
}