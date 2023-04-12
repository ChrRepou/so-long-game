/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:31:50 by crepou            #+#    #+#             */
/*   Updated: 2022/10/18 16:04:35 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int arg)
{
	int	upper;
	int	lower;
	int	digit;

	upper = (arg >= 65 && arg <= 90);
	lower = (arg >= 97 && arg <= 122);
	digit = (arg >= 48 && arg <= 57);
	return (lower || upper || digit);
}
