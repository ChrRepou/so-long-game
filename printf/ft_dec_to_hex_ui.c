/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex_ui.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:27:06 by crepou            #+#    #+#             */
/*   Updated: 2022/12/22 16:16:56 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_num_ui(char *num)
{
	int		erval;
	char	*ptr;
	int		len;

	ptr = num;
	while (*ptr == 'k')
		ptr++;
	len = ft_strlen(ptr);
	erval = write(1, ptr, len);
	free(num);
	if (erval == -1)
		return (-1);
	return (len);
}

static char	*create_hex_ui(void)
{
	char	*hex;
	int		i;

	hex = (char *)malloc(9);
	if (hex == NULL)
		return (NULL);
	i = 0;
	while (i < 9)
	{
		hex[i] = 'k';
		i++;
	}
	return (hex);
}

static char	*fill_hex_ui(char *hex, unsigned int num, char type, int *i)
{
	while (num > 0)
	{
		if (type == 'x')
			hex[(*i)--] = HEX[num % 16];
		else
			hex[(*i)--] = HEX_UPPER[num % 16];
		num = num / 16;
	}
	return (hex);
}

int	ft_dec_to_hex_ui(unsigned int val, char type)
{
	unsigned int	num;
	int				i;
	char			*hexadecimal_number;

	hexadecimal_number = create_hex_ui();
	if (hexadecimal_number == NULL)
		return (-1);
	num = val;
	if (num < 0)
		num *= -1;
	i = 7;
	if (num == 0)
	{
		i--;
		hexadecimal_number[7] = '0';
	}
	if (num > 0)
	{
		hexadecimal_number = fill_hex_ui(hexadecimal_number, num, type, &i);
	}
	hexadecimal_number[8] = '\0';
	return (write_num_ui(hexadecimal_number));
}
