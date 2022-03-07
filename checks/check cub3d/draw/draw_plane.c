/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:55:09 by aalannys          #+#    #+#             */
/*   Updated: 2022/01/29 18:36:05 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	get_color(t_setup *setup, int x, int y)
{
	int			color;
	t_texture	tex;

	tex = setup->texture[setup->col->wall_dir];
	color = tex.texture[y * tex.width + x];
	return (color);
}

int	get_texture_x(t_setup *setup, t_raycaster *r)
{
	double	wall_hit_x;
	int		texture_x;

	wall_hit_x = setup->player->pos.x + r->wall_dist * r->ray_dir.x;
	if (setup->col->vertical_hit == 0)
	wall_hit_x = setup->player->pos.y + r->wall_dist * r->ray_dir.y;
	wall_hit_x -= floor(wall_hit_x);
	texture_x = (int)(wall_hit_x * setup->texture[setup->col->wall_dir].width);
	if ((setup->col->vertical_hit == 0 && r->ray_dir.x > 0)
		|| (setup->col->vertical_hit == 1 && r->ray_dir.y < 0))
		texture_x = setup->texture[setup->col->wall_dir].width - texture_x - 1;
	return (texture_x);
}

void	draw_column(t_setup *s, t_raycaster *r, int wall_top, int tex_x)
{
	t_point	curr_pix;
	int		y;
	double	y_step;
	int		color;

	curr_pix.x = tex_x;
	curr_pix.y = 0;
	y_step = 1.0 * s->texture[s->col->wall_dir].height
		/ (double)r->wall_height;
	y = curr_pix.y;
	while (y < r->wall_height)
	{
		color = get_color(s, (int)curr_pix.x, (int)curr_pix.y);
		my_pix_put(s->image, s->col->no, wall_top + y, color);
		curr_pix.y = curr_pix.y + y_step;
		y++;
	}
}

void	draw_floor_ceil(t_setup *setup)
{
	t_rectangle	floor;
	t_rectangle	ceil;

	floor.x = 0;
	floor.y = PLANE_CENTER;
	floor.width = PLANE_WIDTH;
	floor.height = PLANE_CENTER;
	ceil.x = 0;
	ceil.y = 0;
	ceil.width = PLANE_WIDTH;
	ceil.height = PLANE_CENTER;
	draw_rectangle(setup->image, &floor, setup->map->floor_color);
	draw_rectangle(setup->image, &ceil, setup->map->ceil_color);
}

void	draw_plane(t_setup *setup)
{
	int			column;
	t_column	col;

	column = 0;
	setup->col = &col;
	draw_floor_ceil(setup);
	while (column < PLANE_WIDTH)
	{
		col = (t_column){0};
		col.no = column;
		render(setup);
		column += 1;
	}
}
