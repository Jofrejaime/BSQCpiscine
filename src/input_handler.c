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

void	handle_input(char *filename)
{
	t_map	map;

	if (!parse_map(filename, &map))
		print_map_error();
	else
	{
		// solve_map(&map);
		// print_result(&map);
		free_map(&map);
	}
}

void	handle_multiple_files(char **files, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		handle_input(files[i]);
		if (i < count - 1)
			ft_putchar('\n');
		i++;
	}
}
