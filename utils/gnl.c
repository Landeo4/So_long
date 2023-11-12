/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:43:49 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/12 10:16:04 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i), sizeof(char));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	line = ft_calloc(ft_strlen(buffer) + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *result)
{
	char	*buffer;
	int		byte_read;

	if (!result)
		result = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(buffer);
			free(result);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		result = ft_free(result, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	if (!line)
		return (free(buffer), NULL);
	if (ft_strlen(line) == 1)
		free(buffer);
	return (line);
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