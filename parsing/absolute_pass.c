/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute_pass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:59:39 by tpotillion        #+#    #+#             */
/*   Updated: 2023/11/12 08:50:05 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**is_absolute_pass(char **argv)
{
	char	*buf;
	char	**split;
	int		fd;
	int		len;
	int		i;

	len = ((i = 0));
	while (argv[len])
		len++;
	len--;
	ft_printf("argv[len] %s\n", argv[len]);
	fd = open(argv[len], O_RDONLY);
	if (fd < 0)
		return (pr_error("problem with your fd\n"), NULL);
	buf = get_map_relative_pass(fd);
	if (ft_strlen(buf) >= 2000)
		return (pr_error("map is too wide\n"), NULL);
	split = ft_split(buf, '\n');
	free(buf);
	close(fd);
	return (split);
}

// int	is_complete_map(char *map)
// {
// 	int i;

// 	while (map[i])
// 	{
// 		if (map[i] != '0' && map[i] != 'P' && map[i] != 'C'
// 				&& map[i] != 'E' && map[i] != '1')
// 				return (-1);
// 		i++;
// 	}
// 	return (0);
// }

int	verif_relatif_pass(char **argv)
{
	int		i;
	int		j;
	int		token;

	i = ((j = 0));
	token = 0;
	while (argv[i])
		i++;
	i--;
	while (argv[i][j])
	{
		if (argv[i][j] == '/')
			token++;
		j++;
	}
	if (token == 0)
		return (-1);
	else if (verif_pass_ber(argv, i, j) == -1)
		return (-1);
	return (1);
}

int	verif_pass_ber(char **argv, int i, int j)
{
	char	*name;
	int		c;

	c = 0;
	j = j - 4;
	name = ".ber";
	while (argv[i][j])
	{
		if (argv[i][j] != name[c])
			return (-1);
		j++;
		c++;
	}
	return (0);
}

char	*get_map_relative_pass(int fd)
{
	char	*tmp;
	char	*buf;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = calloc(3000, sizeof(char));
    while (4)
	{
        buf = get_next_line(fd);
		if (buf == NULL)
			break;
		while (buf[i])
		{
			tmp[j] = buf[i];
			i++;
			j++;
		}
		i = 0;
		free(buf);
    }
	tmp[j] = '\0';
    close(fd);
	free(buf);
    return (tmp);
}
