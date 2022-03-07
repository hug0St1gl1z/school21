/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:55:02 by namina            #+#    #+#             */
/*   Updated: 2022/01/29 20:56:44 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_map	*create_config(void)
{
	t_map	*config;

	config = malloc(sizeof(t_map));
	if (!config)
		return (NULL);
	config->player = malloc(sizeof(t_player));
	config->plane = malloc(sizeof(t_point));
	config->texture_array = ft_calloc(5, sizeof(char *));
	if (!config->player || !config->plane || !config->texture_array)
		return (free_config(config));
	config->player->pos.x = -1;
	config->player->pos.y = -1;
	config->player->dir.x = -1;
	config->player->dir.y = -1;
	config->plane->x = -1;
	config->plane->y = -1;
	config->ceil_color = -1;
	config->floor_color = -1;
	config->map = NULL;
	config->map_size = 1;
	config->max_line = 0;
	return (config);
}

int	is_colors_texture_setted(t_map *config)
{
	if (!config)
		return (0);
	if (!config->texture_array || config->ceil_color == -1
		|| config->floor_color == -1)
		return (0);
	if (!(config->texture_array[0]) || !(config->texture_array[1])
		|| !(config->texture_array[2]) || !(config->texture_array[3]))
		return (0);
	return (1);
}

int	skip_to_map(t_map *config, int file_fd, int lines_to_map)
{
	char	*line;
	char	*tmp_str;

	while (get_next_line(file_fd, &line))
	{
		tmp_str = NULL;
		tmp_str = ft_strtrim(line, " ");
		if (!tmp_str)
		{
			exit_error(MEM_ALLOC_ERR);
			return (-1);
		}
		if (*tmp_str)
		{
			config->max_line = ft_strlen(line);
			free(tmp_str);
			free(line);
			break ;
		}
		lines_to_map++;
		free(line);
		free(tmp_str);
	}
	return (lines_to_map);
}

int	add_spaces(t_map *config, int i)
{
	char	*tmp;
	int		len;

	len = ft_strlen(config->map[i]);
	if (len < config->max_line && len)
	{
		tmp = config->map[i];
		config->map[i] = ft_calloc((config->max_line + 1), sizeof(char));
		if (config->map[i] == NULL)
			return (-1);
		ft_memset(config->map[i], ' ', config->max_line);
		ft_memcpy(config->map[i], tmp, len);
		free(tmp);
	}
	return (0);
}

int	fill_map_config(t_map *config, int lines_to_map, int file_fd)
{
	int		i;
	char	*line;
	int		gnl_res;

	config->map = malloc((config->map_size + 1) * sizeof(char *));
	if (config->map == NULL)
		return (-1);
	gnl_res = 1;
	i = 1;
	while (i < lines_to_map)
	{
		get_next_line(file_fd, &line);
		free(line);
		i++;
	}
	i = 0;
	while (gnl_res)
	{
		gnl_res = get_next_line(file_fd, &(config->map[i]));
		if (add_spaces(config, i) == -1)
			return (-1);
		i++;
	}
	config->map[config->map_size] = NULL;
	return (0);
}
