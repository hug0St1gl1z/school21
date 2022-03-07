/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:10:28 by namina            #+#    #+#             */
/*   Updated: 2022/01/29 18:13:41 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	set_player_ns(t_map *config, char char_for_check)
{
	if (char_for_check == 'N')
	{
		config->player->dir.x = 0.0;
		config->player->dir.y = -1.0;
		config->plane->x = FOV;
		config->plane->y = 0.0;
	}
	if (char_for_check == 'S')
	{
		config->player->dir.x = 0.0;
		config->player->dir.y = 1.0;
		config->plane->x = -FOV;
		config->plane->y = 0.0;
	}
}

void	set_player_ew(t_map *config, char char_for_check)
{
	if (char_for_check == 'E')
	{
		config->player->dir.x = 1.0;
		config->player->dir.y = 0.0;
		config->plane->x = 0.0;
		config->plane->y = FOV;
	}
	if (char_for_check == 'W')
	{
		config->player->dir.x = -1.0;
		config->player->dir.y = 0.0;
		config->plane->x = 0.0;
		config->plane->y = -FOV;
	}
}

int	setup_player_pos(t_map *config, char char_for_check, int x_i, int y_i)
{
	if (config->player->pos.x != -1)
		return (-1);
	if (char_for_check == 'N' || char_for_check == 'S')
		set_player_ns(config, char_for_check);
	else if (char_for_check == 'E' || char_for_check == 'W')
		set_player_ew(config, char_for_check);
	config->player->pos.x = x_i + 0.5;
	config->player->pos.y = y_i + 0.5;
	return (0);
}

int	is_player_setted(t_map *config)
{
	int	player_x;
	int	player_y;

	player_x = config->player->pos.x;
	player_y = config->player->pos.y;
	if (player_x == -1 || player_x == -1)
	{
		exit_error(NO_PLAYER_POSITION);
		return (-1);
	}
	player_x -= 0.5;
	player_y -= 0.5;
	if (player_y == 0 || player_x == 0
		|| config->map[player_y - 1][player_x] == ' '
		|| config->map[player_y + 1][player_x] == ' '
		|| config->map[player_y][player_x - 1] == ' '
		|| config->map[player_y][player_x + 1] == ' ')
	{
		printf(PLAYER_ON_BORDER);
		return (-1);
	}
	return (0);
}

int	check_top_bottom_borders(t_map *config)
{
	int	x_i;

	x_i = 0;
	while (x_i <= config->max_line)
	{
		if (config->map[0][x_i] == '0'
			|| config->map[config->map_size - 1][x_i] == '0')
			return (-1);
		x_i++;
	}
	return (0);
}
