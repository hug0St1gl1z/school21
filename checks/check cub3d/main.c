/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:38:44 by namina            #+#    #+#             */
/*   Updated: 2022/01/29 21:21:12 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_setup	*setup;
	t_map	*map;

	if (argc < 2)
		return (1);
	map = parser(argv[1]);
	if (map == NULL)
		return (1);
	setup = init_all();
	setup->player = map->player;
	setup->plane = map->plane;
	setup->map = map;
	load_textures(setup);
	mlx_key_hook(setup->win->win_ptr, key_hook, setup);
	mlx_hook(setup->win->win_ptr, 17, 0L, exit_procedure, setup);
	draw_plane(setup);
	mlx_put_image_to_window(setup->win->mlx_ptr, setup->win->win_ptr,
		setup->image->img, 0, 0);
	draw_minimap(setup);
	mlx_loop(setup->win->mlx_ptr);
	free_config(map);
	return (0);
}
