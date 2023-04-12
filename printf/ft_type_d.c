/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:13:54 by crepou            #+#    #+#             */
/*   Updated: 2022/12/22 15:32:00 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_d(va_list args)
{
	char	*num;
	int		retval;
	size_t	len;

	num = ft_itoa(va_arg(args, int));
	if (num == NULL)
		return (-1);
	len = ft_strlen(num);
	retval = write(1, num, ft_strlen(num));
	free(num);
	if (retval == -1)
		return (-1);
	return (len);
}
