/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:31:06 by crepou            #+#    #+#             */
/*   Updated: 2022/12/22 16:14:32 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	ft_count_digits(unsigned int num)
{
	unsigned int	dig;
	int				count;

	count = 0;
	while (num > 0)
	{
		dig = num % 10;
		num = num / 10;
		count++;
	}
	return (count);
}

static unsigned int	ft_pow(int unsigned n, int unsigned p)
{
	unsigned int	num;

	num = 1;
	while (p > 0)
	{
		num *= n;
		p--;
	}
	return (num);
}

static unsigned int	ft_digit(unsigned int *n, int count)
{
	unsigned int		d;
	unsigned int		digit;

	d = ft_pow(10, (count - 1));
	digit = (*n / d);
	*n = *n % d;
	return (digit);
}

static char	*ft_imalloc(int count)
{
	char	*s;

	if (count == 0)
	{
		s = (char *)malloc(2);
		if (s == NULL)
			return (NULL);
		s[0] = '0';
	}
	else
		s = (char *)malloc(count + 1);
	return (s);
}

char	*ft_itoa_u(unsigned int n)
{
	int		count;
	char	*s;
	int		i;

	count = ft_count_digits(n);
	s = ft_imalloc(count);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (count > 0)
	{
		s[i] = ft_digit(&n, count) + 48;
		i++;
		count --;
	}
	if (s[0] == '0')
		i++;
	s[i] = '\0';
	return (s);
}
