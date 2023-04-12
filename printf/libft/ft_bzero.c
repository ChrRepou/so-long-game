/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:40:54 by crepou            #+#    #+#             */
/*   Updated: 2022/11/25 14:43:49 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ********************************************************
 * void	ft_bzero --> it sets a memory of n chars with zeros
 *
 * @params void *s --> a pointer to a memory we want to set
 * @params size_t n --> the number of chars in the memory 
 * that we want to set with 0
 ******************************************************** */

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
