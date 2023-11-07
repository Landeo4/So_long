/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:00:32 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/07 18:25:27 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
int game_backtracking(char **tmp, t_game *ptr, int y, int x)
{
	int token;

	token = 0;
	while (backtracking_map_finish(tmp) == 0)
	{
		if (backtracking_map(tmp, y, (x + 1)) == 0)
		{
			tmp = map_fill(tmp, y, (x + 1), ptr);
			x++;
			token = 0;
		}
		else if (backtracking_map(tmp, y, (x - 1)) == 0)
		{
			tmp = map_fill(tmp, y, (x - 1), ptr);
			x--;
			token = 0;
		}
		else if (backtracking_map(tmp, (y + 1), x) == 0)
		{
			tmp = map_fill(tmp, (y + 1), x, ptr);
			y++;
			token = 0;
		}
		else if (backtracking_map(tmp, (y - 1), x) == 0)
		{
			tmp = map_fill(tmp, (y - 1), x, ptr);
			y--;
			token = 0;
		}
		if (ptr->nb_item == 0 && ptr->nb_exit == 0)
			return (0);
		show_db_tab(tmp);
		ft_printf("y %d x %d\n", y, x);
		token++;
		if (token == 4)
		{
			x = ptr->p_x;
			y = ptr->p_y;
		}
		else if (token == 5)
			return (-1);
	}
	return (-1);
*/

int	game_backtracking(char **tmp, t_game *ptr, int y, int x)
{
	if (backtracking_map(tmp, y, x) == 0)
	{
		if (tmp[y][x] == 'C')
			ptr->nb_item--;
		else if (tmp[y][x] == 'S')
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
	else if (tmp[y][x] == 'S')
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

/*char **cpy_map_outline(char **map)
{
	int		i;
	int		j;
	int		len;
	char	**tmp;

	i = 0;
	len = 0;
	while (map[i])
	{
		i++;
		len++;
	}
	i = 0;
	tmp = malloc(sizeof (char *) * (len + 1));
	if (!tmp)
		return (NULL);
	while (map[i] && map[i])
	{
		tmp[i] = malloc(sizeof(char) * (ft_strlen(map[i]) + 1));
		if (!tmp[i])
			return (NULL);
		j = 0;
		while (map[i][j])
		{
			tmp[i][j] = map[i][j];
			j++;
		}
		tmp[i][j] = '\0';
		i++;
	}
	tmp[i] = NULL;
	ft_printf("map copier sans contour\n");
	show_db_tab(map);
	return (tmp);
}*/

/*
int game_backtracking(char **tmp, t_game *ptr)
{
	int		x;
	int		y;

	x = ptr->p_x;
	y = ptr->p_y;
	while (backtracking_map_finish(tmp) == 0)
	{
		if (backtracking_map(tmp, y, (x + 1)) == 0)
			tmp = map_fill(tmp, y, (x + 1), ptr);
		else if (backtracking_map(tmp, y, (x - 1)) == 0)
			tmp = map_fill(tmp, y, (x - 1), ptr);
		else if (backtracking_map(tmp, (y + 1), x) == 0)
			tmp = map_fill(tmp, (y + 1), x, ptr);
		else if (backtracking_map(tmp, (y - 1), x) == 0)
			tmp = map_fill(tmp, (y - 1), x, ptr);
		if (tmp[y][x + 1] != '1' && tmp[y][x + 1] != '2')
			x++;
		else if (tmp[y][x - 1] != '1' && tmp[y][x - 1] != '2')
			x--;
		if (tmp[y + 1][x] != '1' && tmp[y + 1][x] != '2')
			y++;
		if (tmp[y - 1][x] != '1' && tmp[y - 1][x] != '2')
			y--;
		if (ptr->nb_item == 0 && ptr->nb_exit == 0)
			return (0);
		show_db_tab(tmp);
		ft_printf("y %d x %d\n", y, x);
	}
	return (-1);
}

char **map_fill(char **tmp, int y, int x, t_game *ptr)
{
	if (tmp[y][x] == 'C')
		ptr->nb_item--;
	else if (tmp[y][x] == 'S')
		ptr->nb_exit--;
	tmp[y][x] = '2';
	return (tmp);
}

int backtracking_map_finish(char **tmp)
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
				return (0);
			j++;
		}
		i++;
	}
	return (-1);
}

int backtracking_map(char **tmp, int y, int x)
{
	if (tmp[y][x] == '1'
		|| tmp[y][x] == '2')
		return (-1);
	return (0);
}

char **cpy_map_outline(char **map)
{
	int		i;
	int		j;
	int		len;
	char	**tmp;

	i = 0;
	len = 0;
	while (map[i])
	{
		i++;
		len++;
	}
	i = 0;
	tmp = malloc(sizeof (char *) * (len + 1));
	if (!tmp)
		return (NULL);
	while (map[i] && map[i])
	{
		tmp[i] = malloc(sizeof(char) * (ft_strlen(map[i]) + 1));
		if (!tmp[i])
			return (NULL);
		j = 0;
		while (map[i][j])
		{
			tmp[i][j] = map[i][j];
			j++;
		}
		tmp[i][j] = '\0';
		i++;
	}
	tmp[i] = NULL;
	ft_printf("map copier sans contour\n");
	show_db_tab(map);
	return (tmp);
}
*/
