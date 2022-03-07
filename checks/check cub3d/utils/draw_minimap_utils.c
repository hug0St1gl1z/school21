/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:03:15 by namina            #+#    #+#             */
/*   Updated: 2022/01/29 18:06:21 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_grid(t_img *img, t_rectangle *params, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < params->height)
	{
		j = 0;
		while (j < params->width)
		{
			if (!i || i == params->height - 1 || !j || j == params->width - 1)
				my_pix_put(img, params->x + j, params->y + i, color);
			j++;
		}
		i++;
	}
}

void	set_img_rec(t_setup *setup, t_minimap *minimap)
{
	minimap->rec.width = (MINI_MAP_WIDTH - MINI_MAP_WIDTH
			% minimap->inner_map_size) / (minimap->inner_map_size);
	minimap->rec.height = (MINI_MAP_HEIGHT - MINI_MAP_HEIGHT
			% minimap->inner_map_size) / minimap->inner_map_size;
	minimap->img.img = mlx_new_image(setup->win->mlx_ptr,
			MINI_MAP_WIDTH - MINI_MAP_WIDTH % minimap->inner_map_size,
			MINI_MAP_HEIGHT - MINI_MAP_HEIGHT % minimap->inner_map_size);
	minimap->img.addr = mlx_get_data_addr(minimap->img.img,
			&(minimap->img.bpp),
			&(minimap->img.line_len),
			&(minimap->img.endian));
}

void	get_inner_map_size(t_setup *setup, t_minimap *minimap)
{
	if (setup->map->map_size < MINI_MAP_SLOTS
		|| setup->map->max_line < MINI_MAP_SLOTS)
	{
		if (setup->map->map_size < setup->map->max_line)
			minimap->inner_map_size = setup->map->map_size;
		else
			minimap->inner_map_size = setup->map->max_line;
	}
	else
		minimap->inner_map_size = MINI_MAP_SLOTS;
}

void	get_player_position(t_setup *setup, t_minimap *minimap)
{
	minimap->player_x = setup->player->pos.x;
	minimap->player_y = setup->player->pos.y;
}

void	set_map_start(t_setup *setup, t_minimap *minimap)
{
	int	inner_map_size;
	int	i;

	inner_map_size = minimap->inner_map_size;
	i = 0;
	minimap->map_start_y = 0;
	while (minimap->map_start_y + inner_map_size < setup->map->map_size
		&& (minimap->player_y - minimap->map_start_y) > inner_map_size / 2)
		(minimap->map_start_y)++;
	minimap->map_start_x = 0;
	while (minimap->map_start_x + inner_map_size < setup->map->max_line
		&& (minimap->player_x - minimap->map_start_x) > inner_map_size / 2)
		(minimap->map_start_x)++;
}
