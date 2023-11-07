/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:09:41 by tpotillion        #+#    #+#             */
/*   Updated: 2023/10/27 12:54:04 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function takes as parameters:
**	
**	char *dest -> the string you want to copy src
**	const char *src -> the string you copy in dest
**	size_t size -> the size of the copy
**
**	==========================================================================
**	
**	This function will copy src (source) in dest (destination)
**	Then the function will return the len of the copy
*/

#include "so_long.h"

char	*ft_strlcpy(char *dest, const char *src, int size)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return (0);
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

/*int main()
{
	char *dest = "";
	printf("%ld",ft_strlcpy(dest,"",0));
}*/