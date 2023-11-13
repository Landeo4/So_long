/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:10:13 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/13 09:32:30 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_manager(char *argv[])
{
	char	**map;

	if (is_empty(argv) == -1)
		return (pr_error("no argument\n"), NULL);
	map = is_absolute_pass(argv);
	if (!map)
		return (NULL);
	return (map);
}

int	is_empty(char **argv)
{
	char	*str;
	int		i;
	int		j;

	str = "./so_long";
	i = ((j = 0));
	while (argv[i])
		i++;
	i--;
	while (argv[i][j])
	{
		if (argv[i][j] != str[j])
			return (0);
		j++;
	}
	return (-1);
}

char	*str_join_free(char *path, char *cmd)
{
	char	*str;

	str = ft_strjoin(path, cmd);
	free(path);
	return (str);
}

int	map_out_help(char **map)
{
	int	i;
	int	last;
	int	j;

	j = 0;
	i = 0;
	last = 0;
	while (map[last])
		last++;
	last--;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (-1);
		j++;
	}
	i = 0;
	while (map[last][i])
	{
		if (map[last][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	verif_size_img(int fd)
{
	char	*tmp;
	int		i;
	int		j;

	i = ((j = 0));
	tmp = NULL;
	while (i < 3)
	{
		tmp = get_next_line(fd, j);
		i++;
		if (i == 3)
			break ;
		free(tmp);
	}
	if (tmp[1] != '3' && tmp[2] != '2'
		&& tmp[5] != '3' && tmp[6] != '2')
		return (free(tmp), get_next_line(fd, 1), -1);
	free(tmp);
	close(fd);
	get_next_line(fd, 1);
	return (0);
}
