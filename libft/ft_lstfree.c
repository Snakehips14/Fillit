/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:41:58 by behiraux          #+#    #+#             */
/*   Updated: 2018/11/27 16:53:48 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **alst)
{
	t_list *fri;
	t_list *tmp;

	tmp = *alst;
	fri = *alst;
	if (!*alst)
		return ;
	while (tmp)
	{
		fri = tmp;
		tmp = tmp->next;
		free(fri->content);
		fri->content = NULL;
		free(fri);
		fri = NULL;
	}
	alst = NULL;
}
