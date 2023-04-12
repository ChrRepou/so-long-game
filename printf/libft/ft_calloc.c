/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:12:17 by crepou            #+#    #+#             */
/*   Updated: 2022/11/25 14:08:02 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*************************************************************************
 * void	*ft_calloc --> allocates memory for nitems of size size each and then 
 * sets this memory with zeros
 *
 * @params size_t nitmes --> the number of items that
 *  I want to allocate memory for
 * @params size_t size --> the size of each item
 *
 * if SIZE_MAX / size < nitems that means that we don't have enough 
 * space to allocate so we return NULL
 **************************************************************************/

void	*ft_calloc(size_t nitems, size_t size)
{
	void			*p;

	if (size && SIZE_MAX / size < nitems)
		return (NULL);
	p = malloc(nitems * size);
	if (p == NULL)
		return (NULL);
	p = ft_memset(p, 0, (nitems * size));
	return (p);
}
