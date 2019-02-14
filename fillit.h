/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:49:31 by behiraux          #+#    #+#             */
/*   Updated: 2019/02/14 17:43:34 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_input_len(char *input);
char	*ft_give_input(char *input);
int		ft_check_input(char *input, int pos);
int		ft_check_tetri(char *input, int pos);
char    *ft_check_all(char *file);
int		ft_check_all_2(char *file);
int		ft_count_tetri(char *str);
char	**ft_build_tetri(char *str);
char	*ft_tetri(char *str, int pos);
int		*ft_pos_tab(char **tetri, int indice);
int		ft_check_shape(int *t);
int		ft_check_all_3(char **tetri, int nb_t);
char	**ft_map(int nb_t);
int		ft_sqrtmap(int nb_t);
int		ft_compare(char *tetri);
int		ft_pos_max_left(char *tetri);
char	*ft_tetri_2d(char *tetri, int pos, int j);
char	*ft_tetri_letter(char *tetri_2d, char c);
char    **ft_parse(char **tetri, int nb_t);
#endif
