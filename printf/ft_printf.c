/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:44:11 by crepou            #+#    #+#             */
/*   Updated: 2022/12/22 16:17:14 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(char type, va_list args)
{
	if (type == 'i' || type == 'd')
		return (ft_type_d(args));
	else if (type == 's')
		return (ft_type_s(args));
	else if (type == 'c')
		return (ft_type_c(args));
	else if (type == '%')
		return (ft_type_perc());
	else if (type == 'p')
		return (ft_dec_to_hex((size_t)va_arg(args, void *)));
	else if (type == 'x')
		return (ft_dec_to_hex_ui((unsigned int)va_arg(args, void *), 'x'));
	else if (type == 'X')
		return (ft_dec_to_hex_ui((unsigned int)va_arg(args, void *), 'X'));
	else if (type == 'u')
		return (ft_type_u(args));
	return (0);
}

static int	ft_print_str(const char *str, va_list args)
{
	int	count;
	int	erval;

	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			erval = ft_type(*str, args);
			if (erval == -1)
				return (-1);
			count += erval;
		}
		else
		{
			erval = write(1, str, 1);
			if (erval == -1)
				return (erval);
			count += 1;
		}
		str++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	if (str == NULL)
		return (0);
	return (ft_print_str(str, args));
}
