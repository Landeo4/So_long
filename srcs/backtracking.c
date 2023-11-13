/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:00:32 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/13 13:07:09 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_backtracking(char **tmp, t_game *ptr, int y, int x)
{
	if (backtracking_map(tmp, y, x) == 0)
	{
		if (tmp[y][x] == 'C')
			ptr->nb_item--;
		else if (tmp[y][x] == 'E')
			ptr->nb_exit--;
		tmp[y][x] = '2';
		game_backtracking(tmp, ptr, y, (x + 1));
		game_backtracking(tmp, ptr, y, (x - 1));
		game_backtracking(tmp, ptr, (y + 1), x);
		game_backtracking(tmp, ptr, (y - 1), x);
	}
	if (backtracking_map_finish(tmp) == 0)
		return (-1);
	if (ptr->nb_item != 0 || ptr->nb_exit != 0)
		return (-1);
	return (0);
}

char	**map_fill(char **tmp, int y, int x, t_game *ptr)
{
	if (tmp[y][x] == 'C')
		ptr->nb_item--;
	else if (tmp[y][x] == 'E')
		ptr->nb_exit--;
	tmp[y][x] = '2';
	return (tmp);
}

int	backtracking_map_finish(char **tmp)
{
	int		i;
	int		j;

	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] != '1' || tmp[i][j] != '2')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	backtracking_map(char **tmp, int y, int x)
{
	if (tmp[y][x] == '1'
		|| tmp[y][x] == '2')
		return (-1);
	return (0);
}
