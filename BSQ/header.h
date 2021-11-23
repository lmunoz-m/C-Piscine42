/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 07:11:38 by guvargas          #+#    #+#             */
/*   Updated: 2021/10/14 13:33:27 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct t_s{
	int		i;
	int		j;
	int		length;
	int		obstaclenum;
	int		nl;
	int		nc;
	int		coordyfin;
	int		coordxfin;
	char	**portion_to_check;

}t_s;

typedef struct t_mi_struct_2{
	int		i;
	int		j;
	int		fd;
	char	c;
	char	**dicc;

}t_mi_struct_2;

typedef struct t_main{
	int		i;
	char	**fl;
}t_main;

void	bsq(char **str);
char	**extract_portion(char **map, int length, int x, int y);
char	**copy_portion(char **orig_portion, int length);
void	put_sqr(char **map, int length, int x, int y);
int		obstacle(char **sqr, char **map, int length);
void	printMap(char **str);
void	ft_putstr(char *str);
void	create_map(void);
int		numRows(char **table);
int		numCol(char **table);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
char	characterIndex(char **table);
char	obstacleIndex(char **table);
int		c_l(char *str, int argc);
int		c_c(char *str);
char	**memory_allocation(int lines, int characters);
char	**arr_asg(char *str, int lines, int characters);
int		m_cr(char **map);
int		it_numCol(char **table, int i);
void	free_mem(int lines, char **dicc);
int		m_f(char **map);
int		m_c(char **map);
void	free_mem2(int lines, char **dicc);
int		checkOpen(char *str);
int		func_fail(void);
void	free_mem3(char **line);
void	func_aux(char **argv, char **file, int i);
void	func_aux2(char **argv, char **file, int i, int argc);
void	set_main(t_main *init);

#endif
