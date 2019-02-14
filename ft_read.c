/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:29:24 by behiraux          #+#    #+#             */
/*   Updated: 2019/02/13 16:34:20 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// fonction qui renvoie la taille de l'input et verifie s'il n y a pas plu de 26
// tetriminos.
int		ft_input_len(char *input)
{
	int		len;
	int		fd;
	char	buf;

	len = 0;
	fd = open(input, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, &buf, 1) != '\0')
	{
		if (buf != '.' && buf != '#' && buf != '\n')
			return (-1);
		len++;
	}
	if (len > 545)
		return (-1);
	return (len);
}

// alloue a new la taille de l'input, et assigne son contenu, puis renvoie new
char	*ft_give_input(char *input)
{
	int		fd;
	int		len;
	int		i;
	char	buf;
	char	*new;

	fd = open(input, O_RDONLY);
	i = 0;
	len = ft_input_len(input);
	if (len == -1)
		return (NULL);
	new = ft_strnew(len);
	while (read(fd, &buf, 1) != '\0')
	{
		new[i] = buf;
		if (new[i] != '.' && new[i] != '#' && new[i] != '\n')
			return (NULL);
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_check_all(char *file)
{
	char	*str;

	str = ft_give_input(file);
	if (str == NULL)
		return (NULL);
	return (str);
}
