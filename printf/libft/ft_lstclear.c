/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:59:06 by crepou            #+#    #+#             */
/*   Updated: 2022/11/19 17:20:11 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;

	if (lst == NULL)
		return ;
	if ((*lst) != NULL)
	{
		while ((*lst)->next != NULL)
		{
			p = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			(*lst) = p;
		}
		del((*lst)->content);
		free(*lst);
	}
	*lst = NULL;
}
