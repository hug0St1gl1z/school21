/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:07:38 by namina            #+#    #+#             */
/*   Updated: 2022/01/29 18:08:59 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_player(t_setup *setup, t_minimap *minimap)
{
	double		offset_x;
	double		offset_y;
	t_rectangle	rec;

	rec = minimap->rec;
	offset_x = setup->player->pos.x * rec.width;
	offset_y = setup->player->pos.y * rec.height;
	if (offset_x > rec.width)
		offset_x = 0;
	if (offset_y > rec.height)
		offset_y = 0;
	rec.x = (setup->player->pos.x - minimap->map_start_x) * rec.width;
	rec.y = (setup->player->pos.y - minimap->map_start_y) * rec.height;
	rec.height = 5;
	rec.width = 5;
	draw_rectangle(&(minimap->img), &rec, create_trgb(100, 255, 100, 0));
}

void	draw_map_pixel(t_setup *setup, t_minimap *minimap, int x, int y)
{
	t_rectangle	rec;
	t_img		img;

	rec = minimap->rec;
	img = minimap->img;
	if ((setup->map->map)[y][x] == ' ')
		draw_rectangle(&img, &rec, create_trgb(255, 0, 0, 0));
	else if ((setup->map->map)[y][x] == '1')
		draw_rectangle(&img, &rec, create_trgb(50, 153, 0, 0));
	else if ((setup->map->map)[y][x] != '\0')
		draw_rectangle(&img, &rec, create_trgb(50, 0, 0, 102));
	else if ((setup->map->map)[y][x] == '\0')
		draw_rectangle(&img, &rec, create_trgb(50, 0, 0, 255));
	if (DRAW_MINIMAP_GRID && (setup->map->map)[y][x] != ' ')
		draw_grid(&img, &rec, create_trgb(50, 0, 0, 0));
}

void	draw_map(t_setup *setup, t_minimap *minimap)
{
	int	y_i;
	int	x_i;
	int	map_x_tmp;
	int	map_y_tmp;

	set_img_rec(setup, minimap);
	map_y_tmp = minimap->map_start_y;
	y_i = 0;
	while (y_i < minimap->inner_map_size)
	{
		x_i = 0;
		map_x_tmp = minimap->map_start_x;
		while (x_i < minimap->inner_map_size)
		{
			minimap->rec.x = x_i * minimap->rec.width;
			minimap->rec.y = y_i * minimap->rec.height;
			draw_map_pixel(setup, minimap, map_x_tmp, map_y_tmp);
			map_x_tmp++;
			x_i++;
		}
		map_y_tmp++;
		y_i++;
	}
}

void	draw_minimap(t_setup *setup)
{
	t_minimap	minimap;

	get_player_position(setup, &minimap);
	get_inner_map_size(setup, &minimap);
	set_map_start(setup, &minimap);
	draw_map(setup, &minimap);
	draw_player(setup, &minimap);
	mlx_put_image_to_window(setup->win->mlx_ptr, setup->win->win_ptr,
		minimap.img.img, 15, 15);
}
