/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:02:31 by tpotillion        #+#    #+#             */
/*   Updated: 2023/10/25 12:45:38 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
**	This function takes as parameters:
**	
**	size_t nmemb -> the number of elements in the array that it will allocate
**	size_t size -> the size in bytes of each array element
**
**	==========================================================================
**	
**	This function will allocate an array of "nmemb" element of size "size"
**	And will then fill the allocated array with 0 and then return it.
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size > 0 && SIZE_MAX / size < nmemb)
		return (NULL);
	tab = malloc(size * nmemb);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, size * nmemb);
	return (tab);
}
