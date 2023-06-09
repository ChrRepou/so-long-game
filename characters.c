/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:32:06 by crepou            #+#    #+#             */
/*   Updated: 2023/04/10 16:40:30 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*create_player_right(mlx_t *mlx)
{
	xpm_t			*player_texture;
	mlx_image_t		*img;

	player_texture = mlx_load_xpm42("./icons/magician-right.xpm42");
	if (!player_texture)
		return (NULL);
	img = mlx_texture_to_image(mlx, &player_texture->texture);
	mlx_delete_texture(&player_texture->texture);
	if (!img)
		return (NULL);
	return (img);
}

mlx_image_t	*create_player_left(mlx_t *mlx)
{
	xpm_t			*player_texture;
	mlx_image_t		*img;

	player_texture = mlx_load_xpm42("./icons/magician-left.xpm42");
	if (!player_texture)
		return (NULL);
	img = mlx_texture_to_image(mlx, &player_texture->texture);
	mlx_delete_texture(&player_texture->texture);
	if (!img)
		return (NULL);
	return (img);
}

mlx_image_t	*create_player_up(mlx_t *mlx)
{
	xpm_t			*player_texture;
	mlx_image_t		*img;

	player_texture = mlx_load_xpm42("./icons/magician-up.xpm42");
	if (!player_texture)
		return (NULL);
	img = mlx_texture_to_image(mlx, &player_texture->texture);
	mlx_delete_texture(&player_texture->texture);
	if (!img)
		return (NULL);
	return (img);
}

mlx_image_t	*create_player_down(mlx_t *mlx)
{
	xpm_t			*player_texture;
	mlx_image_t		*img;

	player_texture = mlx_load_xpm42("./icons/magician-down.xpm42");
	if (!player_texture)
		return (NULL);
	img = mlx_texture_to_image(mlx, &player_texture->texture);
	mlx_delete_texture(&player_texture->texture);
	if (!img)
		return (NULL);
	return (img);
}

mlx_image_t	*create_enemy(mlx_t *mlx)
{
	xpm_t		*enemy_texture;
	mlx_image_t	*img;

	enemy_texture = mlx_load_xpm42("./icons/bad.xpm42");
	if (!enemy_texture)
		return (NULL);
	img = mlx_texture_to_image(mlx, &enemy_texture->texture);
	mlx_delete_texture(&enemy_texture->texture);
	if (!img)
		return (NULL);
	return (img);
}
