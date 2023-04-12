/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_fire.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:05:59 by crepou            #+#    #+#             */
/*   Updated: 2023/04/12 16:23:40 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_fire_up(t_system *system)
{
	if (system->map->map_info->direction == 9)
	{
		if (system->map->map_info->fire_y > system->map->map_info->fire_stop_y)
		{
			system->map->map_info->fire_y -= 0.25;
			system->images[7]->instances->y -= 17;
			if ((system->images[7]->instances->y >= \
				(system->map->map_info->enemy_y) * 66 \
				&& system->images[7]->instances->y \
				< (system->map->map_info->enemy_y + 1) * 66) && \
				system->map->map_info->player_x == \
				system->map->map_info->enemy_x)
				delete_enemy(system);
		}
		else
		{
			mlx_delete_image(system->window, system->images[7]);
			system->images[7] = NULL;
		}
	}
}

void	move_fire_down(t_system *system)
{
	if (system->map->map_info->direction == 10)
	{
		if (system->map->map_info->fire_y < system->map->map_info->fire_stop_y)
		{
			system->map->map_info->fire_y += 0.25;
			system->images[7]->instances->y += 17;
			if ((system->images[7]->instances->y >= \
				system->map->map_info->enemy_y * 66 \
				&& system->images[7]->instances->y \
				< (system->map->map_info->enemy_y + 1) * 66) && \
				system->map->map_info->player_x == \
				system->map->map_info->enemy_x)
				delete_enemy(system);
		}
		else
		{
			mlx_delete_image(system->window, system->images[7]);
			system->images[7] = NULL;
		}
	}
}

void	move_fire_left(t_system *system)
{
	if (system->map->map_info->direction == 8)
	{
		if (system->map->map_info->fire_x > system->map->map_info->fire_stop_x)
		{
			system->map->map_info->fire_x -= 0.25;
			system->images[7]->instances->x -= 17;
			if ((system->images[7]->instances->x >= \
				(system->map->map_info->enemy_x) * 69 \
				&& system->images[7]->instances->x \
				< (system->map->map_info->enemy_x + 1) * 69) && \
				system->map->map_info->player_y == \
				system->map->map_info->enemy_y)
				delete_enemy(system);
		}
		else
		{
			mlx_delete_image(system->window, system->images[7]);
			system->images[7] = NULL;
		}
	}
}

void	move_fire_right(t_system *system)
{
	if (system->map->map_info->direction == 4)
	{
		if (system->map->map_info->fire_x < system->map->map_info->fire_stop_x)
		{
		system->map->map_info->fire_x += 0.25;
		system->images[7]->instances->x += 17;
			if ((system->images[7]->instances->x >= \
				system->map->map_info->enemy_x * 69 \
				&& system->images[7]->instances->x \
				< (system->map->map_info->enemy_x + 1) * 69) && \
				system->map->map_info->player_y == \
				system->map->map_info->enemy_y)
				delete_enemy(system);
		}
		else
		{
			mlx_delete_image(system->window, system->images[7]);
			system->images[7] = NULL;
		}
	}
}
