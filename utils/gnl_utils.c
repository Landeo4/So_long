/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:44:03 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/25 15:33:02 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*free_join(char *backup, char *buffer)
{
	char	*stash;

	stash = ft_strjoin(backup, buffer);
	free(backup);
	return (stash);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*str;

	if (!s || len < 0)
	{
		str = NULL;
		return (str);
	}
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len && (start + i) < ft_strlen(s))
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}
