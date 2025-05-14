/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:55:51 by jmutumbu          #+#    #+#             */
/*   Updated: 2025/05/13 17:56:23 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
#include <fcntl.h>

typedef struct t_map
{
	char	empty;
	char	obstacle;
	char	full;
	int		lines;
	int		cols;
	char	**grid;
}	t_map;

typedef struct t_square
{
	int		x;
	int		y;
	int		size;
}	t_square;

/* Funções de parsing */
int			parse_map(char *filename, t_map *map);
int			read_header(int fd, t_map *map);
int			read_grid(int fd, t_map *map);

/* Solvers */
void	solve_map(t_map *map, t_square *max);

/* Manipulação de entradas */
void		handle_input(char *filename);
void		handle_multiple_files(char **files, int count);

/* Utilitários */
int			ft_atoi(char *str);
int			ft_strlen(char *str);
int			ft_min(int a, int b, int c);
void		ft_putstr(char *str);
void		ft_putchar(char c);
void		free_map(t_map *map);
void		print_map_error(void);

/* parsers */
int			parse_map(char *filename, t_map *map);
int			read_header(int fd, t_map *map);
int	r		ead_grid(int fd, t_map *map);
/*meomoria utils*/
int			alloc_grid(t_map *map);
int			read_line_into_grid(int fd, char *line,
				int *length);

#endif
