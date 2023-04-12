/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:31:33 by crepou            #+#    #+#             */
/*   Updated: 2022/10/15 14:04:58 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int argument)
{
	int	upper;
	int	lower;

	upper = (argument >= 65 && argument <= 90);
	lower = (argument >= 97 && argument <= 122);
	return (upper || lower);
}
