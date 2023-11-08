/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:10:13 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/08 12:42:45 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_manager(char *argv[], char *env[])
{
	char	*tmp;
	char	**map;

	tmp = ft_get_path(env);
	if (!tmp)
		return (NULL);
	tmp = get_final_path_map(argv, tmp);
	tmp = get_perfect_pass(tmp);
	map = get_map(tmp);
	
	free(tmp);
	return (map);
}

char	*get_perfect_pass(char *tmp)
{
	char	*buff;
	int		i;
	int		j;

	i = 4;
	j = 0;
	buff = malloc(sizeof(char) * ft_strlen(tmp) - 3);
	if (!buff)
		return (NULL);
	while (tmp[i])
	{
		buff[j] = tmp[i];
		i++;
		j++;
	}
	buff[j] = '\0';
	free(tmp);
	return (buff);
}

char	*get_final_path_map(char *argv[], char *tmp)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 0;
	path = malloc(sizeof(char) * ft_strlen(tmp) + ft_strlen(argv[1]) + 2);
	if (!path)
		return (NULL);
	while (tmp[i])
	{
		path[j] = tmp[i];
		i++;
		j++;
	}
	i = 0;
	path[j] = '/';
	j++;
	while (argv[1][i])
	{
		path[j] = argv[1][i];
		j++;
		i++;
	}
	free(tmp);
	path[j] = '\0';
	return (path);
}

char	*ft_get_path(char **env)
{
	int		i;
	char	*path;
	char	*dos;
	int		j;

	i = 0;
	j = 0;
	while (ft_strncmp(env[i], "PWD", 3) != 0)
		i++;
	dos = "/maps";
	path = malloc(sizeof(char) * ft_strlen(env[i]) + 6);
	if (!path)
		return (NULL);
	while (env[i][j])
	{
		path[j] = env[i][j];
		j++;
	}
	i = 0;
	while (dos[i])
	{
		path[j] = dos[i];
		i++;
		j++;
	}
	path[j] = '\0';
	return (path);
}

char	*str_join_free(char *path, char *cmd)
{
	char	*str;

	str = ft_strjoin(path, cmd);
	free(path);
	return (str);
}
