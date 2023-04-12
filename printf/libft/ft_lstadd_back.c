/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:46:46 by marvin            #+#    #+#             */
/*   Updated: 2022/11/19 17:18:52 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (lst == NULL)
		return ;
	head = *lst;
	if (head != NULL)
	{
		while (head->next != NULL)
		{
			head = head->next;
		}
		head->next = new;
	}
	else
		(*lst) = new;
}
