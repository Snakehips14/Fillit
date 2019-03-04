/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:29:24 by behiraux          #+#    #+#             */
/*   Updated: 2019/03/04 14:20:46 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_input_len(char *input)
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
	if (len > 545 || len < 20 || len % 21 != 20)
		return (-1);
	return (len);
}

static char	*ft_give_input(char *input)
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
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
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

char		*ft_read(char *file)
{
	char	*str;

	str = ft_give_input(file);
	if (str == NULL)
		return (NULL);
	return (str);
}
