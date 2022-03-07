/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:41:48 by namina            #+#    #+#             */
/*   Updated: 2022/01/29 18:41:49 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

void	assign_rotation(double *cos_r, double *sin_r, bool left)
{
	if (left)
	{
		*cos_r = cos(-ROTATION_SPEED);
		*sin_r = sin(-ROTATION_SPEED);
	}
	else
	{
		*cos_r = cos(ROTATION_SPEED);
		*sin_r = sin(ROTATION_SPEED);
	}
}

void	dda_rotate(t_setup *setup, bool left)
{
	double		old_dir_x;
	double		old_plane_x;
	double		cos_r;
	double		sin_r;
	t_player	*p;

	p = setup->player;
	old_dir_x = setup->player->dir.x;
	old_plane_x = setup->plane->x;
	assign_rotation(&cos_r, &sin_r, left);
	p->dir.x = (p->dir.x * cos_r) - (p->dir.y * sin_r);
	p->dir.y = (old_dir_x * sin_r) + (p->dir.y * cos_r);
	setup->plane->x = (setup->plane->x * cos_r) - (setup->plane->y * sin_r);
	setup->plane->y = (old_plane_x * sin_r) + (setup->plane->y * cos_r);
	draw_plane(setup);
	mlx_put_image_to_window(setup->win->mlx_ptr, setup->win->win_ptr,
		setup->image->img, 0, 0);
	draw_minimap(setup);
}
