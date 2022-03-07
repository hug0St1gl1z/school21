/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:02:14 by namina            #+#    #+#             */
/*   Updated: 2022/01/29 22:10:19 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_arr(char **arr)
{
	char	**arr_tmp;

	if (!arr)
		return ;
	arr_tmp = arr;
	while (*arr_tmp)
	{
		free(*arr_tmp);
		arr_tmp++;
	}
	free(arr);
}

void	*free_config(t_map *config)
{
	if (!config)
		return (NULL);
	if (config->texture_array)
		free_arr(config->texture_array);
	if (config->map)
		free_arr(config->map);
	if (config->plane)
		free(config->plane);
	if (config->player)
		free(config->player);
	free(config);
	return (NULL);
}

void	clear_setup(t_setup *setup)
{
	int	i;

	i = 0;
	if (setup->map)
		free_config(setup->map);
	mlx_destroy_image(setup->win->mlx_ptr, setup->image->img);
	mlx_destroy_window(setup->win->mlx_ptr, setup->win->win_ptr);
	if (setup->win)
		free(setup->win);
	if (setup->image)
		free(setup->image);
	while (i < 4)
	{
		if (setup->texture[i].texture)
			free(setup->texture[i].texture);
		i++;
	}
	free(setup);
}
