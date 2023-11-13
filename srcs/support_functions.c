/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 07:58:58 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/13 08:17:04 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**cpy_map(char **map)
{
	int		i;
	int		j;
	int		len;
	char	**tmp;

	i = ((len = 0));
	while (map[len])
		len++;
	tmp = malloc(sizeof (char *) * (len + 1));
	if (!tmp)
		return (NULL);
	j = 0;
	tmp = cpy_map_help(map, tmp, i, j);
	tmp[len] = NULL;
	return (tmp);
}

char	**cpy_map_help(char **map, char **tmp, int i, int j)
{
	while (map[i])
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
	return (tmp);
}

int	nb_exit(char **map)
{
	int	i;
	int	j;
	int	item;

	i = 0;
	j = 0;
	item = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			j++;
			if (map[i][j] == 'E')
				item++;
		}
		i++;
		j = 0;
	}
	return (item);
}

void	player_pos(char **map, t_game *ptr)
{
	int		i;
	int		j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				ptr->p_x = j;
				ptr->p_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	ptr->p_x = -1;
}

int	nb_player(char **map)
{
	int	i;
	int	j;
	int	play;

	i = 0;
	j = 0;
	play = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			j++;
			if (map[i][j] == 'P')
				play++;
		}
		i++;
		j = 0;
	}
	return (play);
}
