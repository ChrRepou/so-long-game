/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:39:56 by crepou            #+#    #+#             */
/*   Updated: 2022/11/25 14:27:05 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
static int ft_count_digits --> this function counts the digits of a number
if the number is negative it must be converted into a positive as a devision
with a negative returns a negative result

@params int num --> the number that we want to count its digits
*****************************************************************************
static int	ft_pow --> calculates the integer n in the power of integer p 
*****************************************************************************
static int	ft_digit --> returns the first digit of a number

@params int *n --> a pointer to a number
@params int count --> the unit of multiplication derives from count_digits
*****************************************************************************
static char	*ft_imalloc --> mallocs the memory fot the number
*****************************************************************************
char	*ft_itoa --> convert integer n to a string
*/

static int	ft_count_digits(int num)
{
	int	dig;
	int	count;

	count = 0;
	if (num < 0)
	{
		num = (num + 1) * -1;
		if (num + 1 > 0)
			num += 1;
	}
	while (num > 0)
	{
		dig = num % 10;
		num = num / 10;
		count++;
	}
	return (count);
}

static int	ft_pow(int n, int p)
{
	int	num;

	num = 1;
	while (p > 0)
	{
		num *= n;
		p--;
	}
	return (num);
}

static int	ft_digit(int *n, int count)
{
	int		d;
	int		digit;

	d = ft_pow(10, (count - 1));
	digit = (*n / d) * -1;
	if (digit < 0)
		digit *= -1;
	*n = *n % d;
	return (digit);
}

static char	*ft_imalloc(int count, int n)
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
	{
		if (n < 0)
		{
			s = (char *)malloc(count + 2);
			if (s == NULL)
				return (NULL);
			s[0] = '-';
		}
		else
		{
			s = (char *)malloc(count + 1);
		}
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*s;
	int		i;

	count = ft_count_digits(n);
	s = ft_imalloc(count, n);
	if (s == NULL)
		return (NULL);
	if (n > 0)
		i = 0;
	else
		i = 1;
	while (count > 0)
	{
		s[i] = ft_digit(&n, count) + 48;
		i++;
		count --;
	}
	s[i] = '\0';
	return (s);
}
