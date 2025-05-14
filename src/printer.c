/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:15:52 by jmutumbu          #+#    #+#             */
/*   Updated: 2025/05/13 18:15:57 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	fill_square_on_map(t_map *map, t_square *square)
{
	int	i;
	int	j;

	i = 0;
	while (i < square->size)
	{
		j = 0;
		while (j < square->size)
		{
			map->grid[square->y - i][square->x - j] = map->full;
			j++;
		}
		i++;
	}
}

void	print_result(t_map *map, t_square *square)
{
	int	i;

	fill_square_on_map(map, square);
	i = 0;
	while (i < map->lines)
	{
		ft_putstr(map->grid[i]);
		ft_putchar('\n');
		i++;
	}
}
