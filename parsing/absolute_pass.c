/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute_pass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:59:39 by tpotillion        #+#    #+#             */
/*   Updated: 2023/11/09 11:47:11 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// char **is_absolute_pass(char **argv)
// {
// 	char	**map;

// 	map = NULL;
// 	if (verif_relatif_pass(argv) == -1)
// 		return (NULL);
// 	map = get_map_relative_pass(argv);
// 	return (map);
// }

// int	verif_relatif_pass(char **argv)
// {
// 	int		i;
//     int		j;
// 	int		token;

//     i = ((j = 0));
// 	token = 0;
//     while(argv[i])
//         i++;
//     i--;
//     while (argv[i][j])
//     {
// 		if (argv[i][j] == '/')
// 			token++;
//         j++;
//     }
// 	if (token == 0)
// 		return (-1);
//     else if (verif_pass_ber(argv, i, j) == -1)
// 		return (-1);
//     return (1);
// }

// int	verif_pass_ber(char **argv, int i, int j)
// {
// 	char	*name;
// 	int		c;

// 	c = 0;
// 	j = j - 4;
// 	name = ".ber";
//     while (argv[i][j])
//     {
//         if (argv[i][j] != name[c])
// 			return (-1);
// 		j++;
// 		c++;
//     }
// 	return (0);
// }

// char **get_map_relative_pass(char **argv)
// {
// 	char	*buf;
// 	int		fd;
// 	int		len;

// 	if (fd < 0)
// 		return (NULL);
// 	fd = open(argv[], O_RDONLY);
// 	buf = get_next_line();
// 	return (buf);
// }