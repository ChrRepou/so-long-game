/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:15:51 by crepou            #+#    #+#             */
/*   Updated: 2022/12/22 16:05:34 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_u(va_list args)
{
	char			*num;
	int				retval;
	size_t			len;
	unsigned int	n;

	n = va_arg(args, unsigned int);
	num = ft_itoa_u(n);
	if (num == NULL)
		return (-1);
	len = ft_strlen(num);
	retval = write(1, num, ft_strlen(num));
	free(num);
	if (retval == -1)
		return (-1);
	return (len);
}
