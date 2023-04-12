/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:34:52 by crepou            #+#    #+#             */
/*   Updated: 2022/12/22 16:16:50 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_num(char *num)
{
	int		erval;
	char	*ptr;
	int		len;

	ptr = num;
	while (*ptr == 'k')
		ptr++;
	len = ft_strlen(ptr);
	erval = write(1, "0x", 2);
	if (erval == -1)
		return (free(num), -1);
	erval = write(1, ptr, len);
	free(num);
	if (erval == -1)
		return (erval);
	return (erval + 2);
}

static char	*create_hex(void)
{
	char	*hex;
	int		i;

	hex = (char *)malloc(17);
	if (hex == NULL)
		return (NULL);
	i = 0;
	while (i < 17)
	{
		hex[i] = 'k';
		i++;
	}
	return (hex);
}

static char	*fill_hex(char *hex, size_t num, int *i)
{
	while (num > 0)
	{
		hex[(*i)--] = HEX[num % 16];
		num = num / 16;
	}
	return (hex);
}

int	ft_dec_to_hex(size_t val)
{
	size_t	num;
	int		i;
	char	*hexadecimal_number;

	hexadecimal_number = create_hex();
	if (hexadecimal_number == NULL)
		return (-1);
	num = val;
	if (num < 0)
		num *= -1;
	i = 15;
	if (num == 0)
	{
		i--;
		hexadecimal_number[15] = '0';
	}
	if (num > 0)
	{
		hexadecimal_number = fill_hex(hexadecimal_number, num, &i);
	}
	hexadecimal_number[16] = '\0';
	return (write_num(hexadecimal_number));
}
