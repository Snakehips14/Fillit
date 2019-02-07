/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:44:45 by behiraux          #+#    #+#             */
/*   Updated: 2018/11/27 16:45:09 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstlen(t_list *start)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (!start)
		return (0);
	tmp = start;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
