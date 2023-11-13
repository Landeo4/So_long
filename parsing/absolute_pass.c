/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute_pass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:59:39 by tpotillion        #+#    #+#             */
/*   Updated: 2023/11/13 17:49:26 by tpotilli         ###   ########.fr       */
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
	fd = open(argv[len], O_RDONLY);
	if (fd < 0)
		return (pr_error("problem with your fd\n"), NULL);
	if (verif_pass_ber(argv) == -1)
		return (pr_error("not a .ber\n"), close(fd), NULL);
	buf = get_map_relative_pass(fd);
	if (check_map_single(buf) == -1)
		return (pr_error("map is wrong\n"), close(fd), free(buf), NULL);
	if (ft_strlen(buf) >= 2000)
		return (pr_error("map is too wide\n"), close(fd), NULL);
	split = ft_split(buf, '\n');
	free(buf);
	close(fd);
	// if (check_map_characters(split) == -1)
	// 	return (free_db_tab(split), pr_error("map have empty line\n"), NULL);
	return (split);
}

int	check_map_single(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] != '0' && buf[i] != 'P' && buf[i] != 'C'
			&& buf[i] != 'E' && buf[i] != '1' && buf[i] != '\n')
			return (-1);
		i++;
	}
	return (0);
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
	else if (verif_pass_ber(argv) == -1)
		return (-1);
	return (1);
}

int	verif_pass_ber(char **argv)
{
	char	*name;
	int		i;
	int		j;
	int		c;

	i = ((j = 0));
	c = 0;
	while (argv[i])
		i++;
	i--;
	while (argv[i][j])
		j++;
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

	i = ((j = 0));
	tmp = calloc(3000, sizeof(char));
	while (4)
	{
		buf = get_next_line(fd, i);
		if (buf == NULL)
			break ;
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
