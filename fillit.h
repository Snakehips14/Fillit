/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:49:31 by behiraux          #+#    #+#             */
/*   Updated: 2019/03/04 15:08:49 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

int			main(int argc, char **argv);
char		*ft_read(char *file);
int			ft_verification(char *file);
int			ft_count_tetri(char *str);
char		**ft_split(char *str);
int			ft_check_pos_hash(char **tetri, int nb_t);
char		*ft_map(int nb_t, char **tetri);
char		**ft_parse(char **tetri, int nb_t);
void		ft_fill(char *tetrimino, char *map, int pos, char c);
int			ft_solver(char **tetri, char *map, int len, int i);

#endif
