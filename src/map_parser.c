/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:29:33 by jmutumbu          #+#    #+#             */
/*   Updated: 2025/05/13 18:30:17 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	read_header(int fd, t_map *map)
{
	char	buffer[32];
	int		i;
	int		ret;

	i = 0;
	while (i < 31 && (read(fd, &buffer[i], 1) == 1))
	{
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	buffer[i] = '\0';
	if (i < 4)
		return (0);
	map->empty = buffer[i - 3];
	map->obstacle = buffer[i - 2];
	map->full = buffer[i - 1];
	buffer[i - 3] = '\0';
	map->lines = ft_atoi(buffer);
	if (map->lines <= 0 || map->empty == map->obstacle
		|| map->empty == map->full
		|| map->obstacle == map->full)
		return (0);
	return (1);
}

int	read_grid(int fd, t_map *map)
{
	int	i;
	int	len;
	int	expected;

	if (!alloc_grid(map))
		return (0);
	i = 0;
	expected = -1;
	while (i < map->lines)
	{
		if (!read_line_into_grid(fd, map->grid[i], &len))
			return (0);
		if (expected == -1)
			expected = len;
		else if (len != expected)
			return (0);
		i++;
	}
	map->cols = expected;
	return (1);
}

static int	open_file_or_stdin(char *filename)
{
	int	fd;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

int	parse_map(char *filename, t_map *map)
{
	int	fd;
	int	ok;

	if (filename)
		fd = open_file_or_stdin(filename);
	else
		fd = 0;
	if (fd < 0)
		return (0);
	if (read_header(fd, map) && read_grid(fd, map))
		ok = 1;
	else
		ok = 0;
	if (filename)
		close(fd);
	if (!ok)
	{
		free_map(map);
		return (0);
	}
	return (1);
}
