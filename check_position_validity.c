/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position_validity.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:53:56 by crepou            #+#    #+#             */
/*   Updated: 2023/04/12 18:29:18 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_up(t_map *mp, int x, int y)
{
	t_lines_table	*element;
	t_coordinates	**line;
	char			value;
	int				i;

	i = 0;
	element = mp->lines_table;
	while (i < y - 1)
	{
		element = element->next;
		i++;
	}
	line = element->points;
	value = line[x]->val;
	if (value != '1' && value != 'E')
		return (1);
	return (0);
}

int	validate_down(t_map *mp, int x, int y)
{
	t_lines_table	*element;
	t_coordinates	**line;
	char			value;
	int				i;

	i = 0;
	element = mp->lines_table;
	while (i < y + 1)
	{
		element = element->next;
		i++;
	}
	line = element->points;
	value = line[x]->val;
	if (value != '1' && value != 'E')
		return (1);
	return (0);
}

int	validate_left(t_map *mp, int x, int y)
{
	t_lines_table	*element;
	t_coordinates	**line;
	char			value;
	int				i;

	i = 0;
	element = mp->lines_table;
	while (i < y)
	{
		element = element->next;
		i++;
	}
	line = element->points;
	value = line[x - 1]->val;
	if (value != '1' && value != 'E')
		return (1);
	return (0);
}

int	validate_right(t_map *mp, int x, int y)
{
	t_lines_table	*element;
	t_coordinates	**line;
	char			value;
	int				i;

	i = 0;
	element = mp->lines_table;
	while (i < y)
	{
		element = element->next;
		i++;
	}
	line = element->points;
	if (x < mp->map_info->co_x)
		value = line[x + 1]->val;
	else
		value = line[x]->val;
	if (value != '1' && value != 'E')
		return (1);
	return (0);
}

void	set_elem_position(t_map **map, t_coordinates *elem, int i, int line_no)
{
	if (elem->val == 'P')
	{
		(*map)->map_info->player_x = i;
		(*map)->map_info->player_y = line_no;
	}
	else if (elem->val == 'B')
	{
		(*map)->map_info->enemy_x = i;
		(*map)->map_info->enemy_y = line_no;
	}
	else if (elem->val == 'E')
	{
		(*map)->map_info->exit_x = i;
		(*map)->map_info->exit_y = line_no;
	}
}
