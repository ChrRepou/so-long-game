/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:27:40 by crepou            #+#    #+#             */
/*   Updated: 2022/11/25 14:30:13 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************** */
/* int ft_calc_num --> takes the string number 
 * from the end and moves to the start
 * until it converts every character into digit
 *
 * It was easier to convert this string into a num in 
 * this way because the most left
 * digit is the one with the bigger value
 *
 * @params const char *end --> a pointer to the end 
 * of the number string
 * @params int len --> the length of the string 
 * including the symbol (-, +)
 *
 * @return value --> the integer derives from the string
 * ************************************************** */
/* int	ft_allowed_chars --> checks if the current 
 * character of the string is
 * an allowed character (\n \t \r \v \f space)
 *
 * @params char c --> the current character of the string
 *
 * @return value --> 1 if is an allowed char or 0 if it's not
* ******************************************************** */
/* int	ft_atoi(const char *str) --> returns the 
 * conversion of a string into an integer
 *
 * @params const char *str --> a pointer to a string
 *
 * if the string is empty then the return value is 0
 * Then we move the pointer str until we find +,-,0-9 
 * or we reach the end of the string
 * if the string has not allowed characters before we 
 * reach a symbol or a number the
 * function returns 0
 * After that we move the pointer of the string as 
 * we count the number of digits in it
 * The we pass this pointer in the ft_calc_num 
 * function and we return the integer
 * calculated by the function
 */

static int	ft_calc_num(const char *end, int len)
{
	int			num;
	int			mult;

	mult = 1;
	num = 0;
	end--;
	while (len > 0)
	{
		if (*end == '-')
			num *= -1;
		if (ft_isdigit(*end))
		{
			num += mult * (*end - 48);
			mult *= 10;
		}
		len--;
		end--;
	}
	return (num);
}

static int	ft_allowed_charstr(char c)
{
	if (c == '\n' || c == '\t' || c == '\f')
		return (1);
	if (c == '\v' || c == '\r' || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			len;
	int			count;

	len = 0;
	count = 0;
	if (ft_strncmp(str, "\0", 1) == 0)
		return (0);
	while (*str != '\0')
	{
		if (*str == '-' || *str == '+' || ft_isdigit(*str))
			break ;
		if (!(ft_allowed_charstr(*str)))
			return (0);
		count++;
		str++;
	}
	str++;
	len++;
	while (ft_isdigit(*str) && *str != '\0')
	{
		len++;
		str++;
	}
	return (ft_calc_num(str, len));
}
