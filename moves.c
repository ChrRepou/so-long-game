/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:03:11 by crepou            #+#    #+#             */
/*   Updated: 2023/04/12 17:25:39 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_over_empty_space2(t_system *system, int type, int x, int y)
{
	if (system->map->map_info->direction != type)
	{
		system->images[system->map->map_info->direction]->\
			instances->enabled = 0;
		system->images[type]->instances->enabled = 1;
	}
	if (type == 4)
	{
		system->map->map_info->player_x += 1;
		update_elem_value(&(system->map), 'P', x + 1, y);
		system->images[type]->instances[0].x = (x + 1) * 69;
		system->images[type]->instances[0].y = y * 66;
	}
	else
	{
		system->map->map_info->player_x -= 1;
		update_elem_value(&(system->map), 'P', x - 1, y);
		system->images[type]->instances[0].x = (x - 1) * 69;
		system->images[type]->instances[0].y = y * 66;
	}
}

void	move_over_empty_space(t_system *system, int type, int x, int y)
{
	update_elem_value(&(system->map), '0', x, y);
	if (system->map->map_info->direction != type)
	{
		system->images[system->map->map_info->direction]->\
			instances->enabled = 0;
		system->images[type]->instances->enabled = 1;
	}
	if (type == 9)
	{
		system->map->map_info->player_y -= 1;
		update_elem_value(&(system->map), 'P', x, y - 1);
		system->images[type]->instances[0].y = (y - 1) * 66;
		system->images[type]->instances[0].x = x * 69;
	}
	else if (type == 10)
	{
		system->map->map_info->player_y += 1;
		update_elem_value(&(system->map), 'P', x, y + 1);
		system->images[type]->instances[0].y = (y + 1) * 66;
		system->images[type]->instances[0].x = x * 69;
	}
	else
		move_over_empty_space2(system, type, x, y);
	system->map->map_info->direction = type;
}

void	enable_exit(t_system *system)
{
	system->map->map_info->exit_enabled = 1;
	system->images[1]->instances->enabled = 0;
	mlx_image_to_window(system->window, system->images[11], \
		system->map->map_info->exit_x * 69, system->map->map_info->exit_y * 66);
}

void	move_over_collectible(t_system *system, int type)
{
	t_coordinates	*elem;
	int				x;
	int				y;
	char			*score_str;
	char			*score;

	move_over_empty_space(system, type, system->map->map_info->player_x, \
		system->map->map_info->player_y);
	x = system->map->map_info->player_x;
	y = system->map->map_info->player_y;
	elem = elem_identify(system->map, x, y);
	system->images[0]->instances[elem->instance_index - 1].enabled = 0;
	system->map->map_info->score++;
	mlx_delete_image(system->window, system->map->map_info->score_img);
	score = ft_itoa(system->map->map_info->score);
	score_str = ft_strjoin("score: ", score);
	system->map->map_info->score_img = \
		mlx_put_string(system->window, score_str, 5, \
		system->map->map_info->co_y * 66 - 43);
	free(score);
	free(score_str);
	if (system->map->map_info->score == system->map->map_info->collectibles)
		enable_exit(system);
}
