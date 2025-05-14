/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:54:06 by jmutumbu          #+#    #+#             */
/*   Updated: 2025/05/13 18:54:07 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	alloc_grid(t_map *map)
{
	int	i;

	map->grid = (char **)malloc(sizeof(char *) * map->lines);
	if (!map->grid)
		return (0);
	i = 0;
	while (i < map->lines)
	{
		map->grid[i] = (char *)malloc(1024);
		if (!map->grid[i])
			return (0);
		i++;
	}
	return (1);
}

int	read_line_into_grid(int fd, char *line, int *length)
{
	char	buffer;
	int		i;

	i = 0;
	while (read(fd, &buffer, 1) == 1 && buffer != '\n')
	{
		line[i] = buffer;
		i++;
	}
	line[i] = '\0';
	*length = i;
	return (1);
}
