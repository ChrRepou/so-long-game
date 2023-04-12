/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:20:04 by crepou            #+#    #+#             */
/*   Updated: 2023/04/12 16:24:53 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coordinates	*next_wall(int x, int y, t_system *system, int direction)
{
	if (direction == 4)
		return (next_wall_right(x, y, system));
	else if (direction == 8)
		return (next_wall_left(x, y, system));
	else if (direction == 9)
		return (next_wall_up(x, y, system));
	else
		return (next_wall_down(x, y, system));
}

void	delete_enemy(t_system *system)
{
	int				i;
	int				j;
	t_coordinates	**line;
	t_lines_table	*table;

	i = 0;
	table = system->map->lines_table;
	while (i < system->map->map_info->co_y)
	{
		line = table->points;
		j = 0;
		while (j < system->map->map_info->co_x)
		{
			if (line[j]->val == 'B')
			{
				line[j]->val = '0';
				mlx_delete_image(system->window, system->images[5]);
			}
			j++;
		}
		table = table->next;
		i++;
	}
}

void	fire_graphic(t_system *system)
{
	if (system->images[7] && system->images[7]->instances != NULL)
	{
		move_fire_up(system);
		move_fire_down(system);
		move_fire_right(system);
		move_fire_left(system);
	}
}

void	shot_fire(mlx_key_data_t keydata, t_system *system)
{
	t_coordinates	*elem;

	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
	{
		if (!system->images[7])
		{
			elem = next_wall(system->map->map_info->player_x, \
				system->map->map_info->player_y, \
				system, system->map->map_info->direction);
			system->map->map_info->fire_stop_x = (float)elem->x;
			system->map->map_info->fire_stop_y = (float)elem->y;
			system->images[7] = create_fire(system->window);
			system->map->map_info->fire_x = system->map->map_info->player_x;
			system->map->map_info->fire_y = system->map->map_info->player_y;
			mlx_image_to_window(system->window, system->images[7], \
				system->map->map_info->player_x * 69, \
				system->map->map_info->player_y * 66 + 16);
		}
	}
}
