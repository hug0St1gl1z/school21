/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:54:12 by aalannys          #+#    #+#             */
/*   Updated: 2022/01/29 21:25:00 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_win	*init_win(void)
{
	t_win	*win;

	win = malloc(sizeof(t_win));
	if (!win)
		error_exit(MEM_ALLOC_ERR);
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
	{
		free(win);
		error_exit(INIT_WIN_ERR);
	}
	win->height = PLANE_HEIGHT;
	win->width = PLANE_WIDTH;
	win->win_ptr = mlx_new_window(win->mlx_ptr,
			win->width, win->height, "Cub3D");
	return (win);
}

t_img	*init_img(t_win *win)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
	{
		free(win);
		error_exit(MEM_ALLOC_ERR);
	}
	img->img = mlx_new_image(win->mlx_ptr, win->width, win->height);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp),
			&(img->line_len), &(img->endian));
	return (img);
}

t_setup	*init_all(void)
{
	t_setup		*setup;
	t_win		*win;
	t_img		*img;
	int			i;

	win = init_win();
	img = init_img(win);
	setup = malloc(sizeof(t_setup));
	if (!setup)
	{
		free(img);
		free(win);
		error_exit(MEM_ALLOC_ERR);
	}
	i = 0;
	while (i < 4)
	{
		setup->texture[i].texture = NULL;
		i++;
	}
	setup->image = img;
	setup->win = win;
	return (setup);
}
