/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:14:08 by jmutumbu          #+#    #+#             */
/*   Updated: 2025/05/13 19:14:17 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	**create_dp_matrix(int rows, int cols)
{
	int	**dp;
	int	i;

	dp = (int **)malloc(sizeof(int *) * rows);
	if (!dp)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		dp[i] = (int *)malloc(sizeof(int) * cols);
		if (!dp[i])
			return (NULL);
		i++;
	}
	return (dp);
}

static void	update_max_square(t_square *max, int i, int j, int size)
{
	if (size > max->size)
	{
		max->x = j;
		max->y = i;
		max->size = size;
	}
}

static void	free_dp(int ***dp, t_map **map)
{
	i = 0;
	while (i < map->lines)
		free(dp[i++]);
	free(dp);
}

static void	create_local_dp(int ***dp, int **map)
{
	dp = create_dp_matrix(map->lines, map->cols);
	if (!dp)
		return ;
}

void	solve_map(t_map *map, t_square *max)
{
	int	**dp;
	int	i;
	int	j;

	create_local_dp(&dp, &map);
	max->size = 0;
	i = -1;
	while (++i < map->lines)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->grid[i][j] == map->obstacle)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = 1 + ft_min(dp[i - 1][j],
						dp[i][j - 1],
						dp[i - 1][j - 1]);
			update_max_square(max, i, j, dp[i][j]);
		}
	}
	free_dp(&dp, &map);
}
