/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:43:49 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/25 13:27:57 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_first_backup(char *backup, int fd)
{
	int		help;
	char	*buffer;

	help = 1;
	while (!ft_strchr(backup, '\n') && help != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		help = read(fd, buffer, BUFFER_SIZE);
		if (help == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[help] = '\0';
		backup = free_join(backup, buffer);
		free(buffer);
	}
	return (backup);
}

char	*ft_get_str(char *backup)
{
	char	*new_line;

	if (!backup)
		return (NULL);
	if (ft_find_newline(backup) >= 0)
		new_line = ft_substr(backup, 0, ((ft_find_newline(backup) + 1)));
	else
		new_line = ft_substr(backup, 0, ft_strlen(backup));
	return (new_line);
}

int	ft_find_newline(char *str)
{
	int	i;

	i = -1;
	if (!(str))
		return (-1);
	while (str[++i])
	{
		if (str[i] == '\n')
			return (i);
	}
	return (-1);
}

char	*ft_next_line(char *backup)
{
	int		i;
	char	*new;

	i = (ft_strlen(backup) - ft_find_newline(backup));
	if (!backup || ft_find_newline(backup) == -1)
	{
		free(backup);
		return (NULL);
	}
	else
		new = ft_substr(backup, (ft_find_newline(backup) + 1), i);
	free(backup);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*backup[1024];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup[fd] = ft_first_backup(backup[fd], fd);
	if (!backup[fd])
		return (NULL);
	str = ft_get_str(backup[fd]);
	backup[fd] = ft_next_line(backup[fd]);
	return (str);
}

/* #include "get_next_line.h"

int    main(void)
{
	int        fd1;
	int        fd2;
	int        fd3;
	int        run;
	char    	*str;

	fd1 = open("test1.txt", O_RDWR);
	fd2 = open("test2.txt", O_RDWR);
	fd3 = open("test3.txt", O_RDWR);
	run = 0;
	while (run != 3)
	{
		
		str = get_next_line(fd1);
		if (str != NULL)
		{
			printf("main FD1 --> %s\n", str);
			free (str);
			str = NULL;
		}
		else
			run++;
		str = get_next_line(fd2);
		if (str != NULL)
		{
			printf("main FD2 --> %s\n", str);
			free (str);
			str = NULL;
		}
		else
			run++;
		str = get_next_line(fd3);
		if (str != NULL)
		{
			printf("main FD3 --> %s\n", str);
			free (str);
			str = NULL;
		}
		else
			run++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
 */