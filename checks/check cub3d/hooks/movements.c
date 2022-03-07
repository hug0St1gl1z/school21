/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:40:49 by namina            #+#    #+#             */
/*   Updated: 2022/01/29 19:00:02 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

void	dda_move_forward_backward(t_setup *setup, bool forward)
{
	t_player	*p;
	double		delta_x;
	double		delta_y;

	p = setup->player;
	delta_x = p->dir.x * PLAYER_SPEED;
	delta_y = p->dir.y * PLAYER_SPEED;
	if (!forward)
	{
		delta_x *= -1;
		delta_y *= -1;
	}
	if (!check_wall(setup->map, (int)(setup->player->pos.x),
		(int)(setup->player->pos.y + delta_y)))
		setup->player->pos.y += delta_y;
	if (!check_wall(setup->map, (int)(setup->player->pos.x + delta_x),
		(int)(setup->player->pos.y)))
		setup->player->pos.x += delta_x;
	draw_plane(setup);
	mlx_put_image_to_window(setup->win->mlx_ptr, setup->win->win_ptr,
		setup->image->img, 0, 0);
	draw_minimap(setup);
}

void	dda_move_left_right(t_setup *setup, bool left)
{
	double		delta_x;
	double		delta_y;

	delta_x = setup->plane->x * PLAYER_SPEED;
	delta_y = setup->plane->y * PLAYER_SPEED;
	if (left)
	{
		delta_x *= -1;
		delta_y *= -1;
	}
	if (!check_wall(setup->map, (int)(setup->player->pos.x),
		(int)(setup->player->pos.y + delta_y)))
		setup->player->pos.y += delta_y;
	if (!check_wall(setup->map, (int)(setup->player->pos.x + delta_x),
		(int)(setup->player->pos.y)))
		setup->player->pos.x += delta_x;
	draw_plane(setup);
	mlx_put_image_to_window(setup->win->mlx_ptr, setup->win->win_ptr,
		setup->image->img, 0, 0);
	draw_minimap(setup);
}
