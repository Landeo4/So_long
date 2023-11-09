/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:40:15 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/09 11:22:14 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char *tmp)
{
	char	**map;
	char	*buf;
	int		fd;
	ssize_t	byte;

	buf = malloc(sizeof(char) * 500);
	if (!buf)
		return (NULL);
	buf = ft_memset(buf, 0, 500);
	fd = open(tmp, O_RDONLY);
	if (fd < 0)
	{
		free(buf);
		pr_error("wrong fd\n");
		return (NULL);
	}
	byte = read(fd, buf, 499);
	if (byte == -1)
		ft_printf("problem\n");
	else
		buf[byte] = '\0';
	map = ft_split(buf, '\n');
	free(buf);
	return (map);
}

/*int verif_size_img(char **map, t_game *ptr)
{
	char	*width
	char	*height;

	
	width = get_next_line(tiles/floor.xpm);
	if (!width || !height)
		return (-1);
	height = 
	if (width != 16 || height != 16)
		return (-1);
	
	//verif toutes les tailles = 16 pixels
	return (0);
}*/

int	verif_map_manager(char **map)
{
	if (verif_square(map) == -1)
		return (-1);
	if (verif_map_outline(map) == -1)
		return (-1);
	return (1);
}

int	verif_square(char **map)
{
	int	i;
	int	tk;
	int	jt;

	i = 0;
	tk = 0;
	jt = 0;
	while (map[i] && map[i + 1])
	{
		tk = ft_strlen(map[i]);
		jt = ft_strlen(map[i + 1]);
		if (tk != jt)
		{
			ft_printf("Error\nmap_is_not_a_square\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	verif_map_outline(char **map)
{
	if (map_out_help(map) == -1)
	{
		ft_printf("wrong first line or last\n");
		return (-1);
	}
	if (verif_map_middle(map) == -1)
	{
		ft_printf("wrong map character\n");
		return (-1);
	}
	return (0);
}

int	verif_map_middle(char **map)
{
	int	j;
	int i;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != 'P' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != '1')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
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
