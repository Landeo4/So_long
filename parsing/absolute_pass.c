/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute_pass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:59:39 by tpotillion        #+#    #+#             */
/*   Updated: 2023/11/10 15:58:38 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**is_absolute_pass(char **argv)
{
	char	*buf;
	char	**split;
	int		fd;
	int		len;

	len = 0;
	while (argv[len])
		len++;
	len--;
	ft_printf("je passe par la \n");
	fd = open("./so_long_banger/maps/map.ber", O_RDONLY);
	ft_printf("%s\n %d\n", argv[len], fd);
	if (fd < 0)
		return (NULL);
	buf = get_next_line(fd);
	ft_printf("buf %s\n", buf);
	split = ft_split(buf, '\n');
	return (split);
}

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

char	*get_map_relative_pass(char **argv)
{
	char	*buf;
	int		fd;
	int		len;

	len = 0;
	while (argv[len])
		len++;
	len--;
	fd = open(argv[len], O_RDONLY);
	if (fd < 0)
		return (NULL);
	buf = get_next_line(fd);
	ft_printf("buf %s\n", buf);
	return (buf);
}
