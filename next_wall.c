/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:09:02 by crepou            #+#    #+#             */
/*   Updated: 2023/04/12 16:52:07 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coordinates	*next_wall_left(int x, int y, t_system *system)
{
	int				i;
	t_lines_table	*lines_table;

	i = 0;
	lines_table = system->map->lines_table;
	while (i < y)
	{
		lines_table = lines_table->next;
		i++;
	}
	i = x;
	while (i > 0)
	{
		if (lines_table->points[i]->val == '1')
			return (lines_table->points[i]);
		i--;
	}
	return (lines_table->points[i]);
}

t_coordinates	*next_wall_right(int x, int y, t_system *system)
{
	int				i;
	t_lines_table	*lines_table;

	i = 0;
	lines_table = system->map->lines_table;
	while (i < y)
	{
		lines_table = lines_table->next;
		i++;
	}
	i = x;
	while (i < system->map->map_info->co_x)
	{
		if (lines_table->points[i]->val == '1')
			return (lines_table->points[i]);
		i++;
	}
	return (lines_table->points[i]);
}

t_coordinates	*next_wall_up(int x, int y, t_system *system)
{
	int				i;
	t_lines_table	*lines_table;
	t_coordinates	*elem;

	i = 0;
	lines_table = system->map->lines_table;
	while (i < y)
	{
		if (lines_table->points[x]->val == '1')
			elem = lines_table->points[x];
		lines_table = lines_table->next;
		i++;
	}
	return (elem);
}

t_coordinates	*next_wall_down(int x, int y, t_system *system)
{
	int				i;
	t_lines_table	*lines_table;

	i = 0;
	lines_table = system->map->lines_table;
	while (i < y)
	{
		lines_table = lines_table->next;
		i++;
	}
	while (i < system->map->map_info->co_y)
	{
		if (lines_table->points[x]->val == '1')
			return (lines_table->points[x]);
		lines_table = lines_table->next;
		i++;
	}
	return (lines_table->points[x]);
}
