/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:12:30 by jmutumbu          #+#    #+#             */
/*   Updated: 2025/05/13 18:12:36 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include "bsq.h"

void	print_map_error(void)
{
	ft_putstr("map error\n");
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		handle_input(NULL);
	else
		handle_multiple_files(argv + 1, argc - 1);
	return (0);
}
