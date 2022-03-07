/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:09:15 by namina            #+#    #+#             */
/*   Updated: 2022/01/29 18:09:16 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	assign_dir_map_delta(t_setup *setup, t_raycaster *r)
{
	double	camera_x;

	camera_x = 2 * setup->col->no / (double)PLANE_WIDTH - 1;
	r->ray_dir.x = setup->player->dir.x + setup->plane->x * camera_x;
	r->ray_dir.y = setup->player->dir.y + setup->plane->y * camera_x;
	r->on_map.x = floor(setup->player->pos.x);
	r->on_map.y = floor(setup->player->pos.y);
	r->deltas.x = fabs(1.0 / r->ray_dir.x);
	r->deltas.y = fabs(1.0 / r->ray_dir.y);
}

void	assign_step_dst(t_setup *setup, t_raycaster *r)
{
	r->step = (t_point){.x = 1, .y = 1};
	r->side_dist.x = (r->on_map.x + 1.0 - setup->player->pos.x) * r->deltas.x;
	r->side_dist.y = (r->on_map.y + 1.0 - setup->player->pos.y) * r->deltas.y;
	if (r->ray_dir.x < 0)
	{
		r->step.x = -1;
		r->side_dist.x = (setup->player->pos.x - r->on_map.x) * r->deltas.x;
	}
	if (r->ray_dir.y < 0)
	{
		r->step.y = -1;
		r->side_dist.y = (setup->player->pos.y - r->on_map.y) * r->deltas.y;
	}
}

void	cast_ray(t_setup *setup, t_raycaster *r)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (r->side_dist.x < r->side_dist.y)
		{
			r->side_dist.x += r->deltas.x;
			r->on_map.x += r->step.x;
			setup->col->vertical_hit = 0;
		}
		else
		{
			r->side_dist.y += r->deltas.y;
			r->on_map.y += r->step.y;
			setup->col->vertical_hit = 1;
		}
		hit = check_wall(setup->map, (int)r->on_map.x, (int)r->on_map.y);
	}
}

int	find_wall_top(t_setup *setup, t_raycaster *r)
{
	int		wall_height;
	double	wall_dist;
	int		wall_top;
	int		wall_bottom;

	wall_dist = (r->on_map.y - setup->player->pos.y
			+ (1.0 - r->step.y) / 2.0) / r->ray_dir.y;
	if (setup->col->vertical_hit == 0)
		wall_dist = (r->on_map.x - setup->player->pos.x
				+ (1.0 - r->step.x) / 2.0) / r->ray_dir.x;
	r->wall_dist = wall_dist;
	wall_height = (int)(PLANE_HEIGHT / wall_dist);
	wall_top = -wall_height / 2 + PLANE_HEIGHT / 2;
	if (wall_top < 0)
		wall_top = 0;
	wall_bottom = wall_height / 2 + PLANE_HEIGHT / 2;
	if (wall_bottom >= PLANE_HEIGHT)
		wall_bottom = PLANE_HEIGHT - 1;
	wall_height = wall_bottom - wall_top + 1;
	r->wall_height = wall_height;
	return (wall_top);
}

void	render(t_setup *setup)
{
	t_raycaster	rc;
	int			wall_top;
	int			texture_x;

	assign_dir_map_delta(setup, &rc);
	assign_step_dst(setup, &rc);
	cast_ray(setup, &rc);
	find_wall_dir(setup->col, &(rc.ray_dir));
	wall_top = find_wall_top(setup, &rc);
	texture_x = get_texture_x(setup, &rc);
	draw_column(setup, &rc, wall_top, texture_x);
}
