/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:01:28 by namina            #+#    #+#             */
/*   Updated: 2022/01/29 18:02:01 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_wall(t_map *config, int x, int y)
{
	if (y >= config->map_size)
		return (0);
	if (x >= (int) ft_strlen(config->map[y]))
		return (0);
	if (config->map[y][x] == '1')
		return (1);
	if (config->map[y][x] == '0')
		return (0);
	return (0);
}
