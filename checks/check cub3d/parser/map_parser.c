/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:54:26 by namina            #+#    #+#             */
/*   Updated: 2022/01/29 20:53:39 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	set_texture_color(int file_fd, t_map *config)
{
	char	*line;
	int		i;

	i = 1;
	line = NULL;
	while (get_next_line(file_fd, &line))
	{
		i++;
		if (handle_line(config, &line) == -1)
			break ;
		if (is_colors_texture_setted(config))
			return (i);
	}
	if (line)
		free(line);
	if (!is_colors_texture_setted(config))
	{
		exit_error(INCORRECT_PARAMS);
		return (-1);
	}
	return (i);
}

int	set_map_config(int file_fd, t_map *config, char *filename)
{
	int		lines_to_map;

	lines_to_map = set_texture_color(file_fd, config);
	if (lines_to_map == -1)
		return (-1);
	lines_to_map = skip_to_map(config, file_fd, lines_to_map);
	if (lines_to_map == -1)
		return (-1);
	set_map_width_height(file_fd, config);
	close(file_fd);
	file_fd = open(filename, O_RDONLY);
	if (file_fd == -1)
		return (-1);
	if (fill_map_config(config, lines_to_map, file_fd) == -1)
		return (-1);
	close(file_fd);
	return (0);
}

t_map	*parser(char *filename)
{
	int		file_fd;
	t_map	*config;

	if (check_filename(filename) == -1)
		return (exit_error(WRONG_MAP_FILE_FORMAT));
	file_fd = open(filename, O_RDONLY);
	if (file_fd == -1)
		return (exit_error(OPEN_MAP_ERROR));
	config = create_config();
	if (!config)
		return (exit_error(MEM_ALLOC_ERR));
	if (set_map_config(file_fd, config, filename) == -1)
	{
		close(file_fd);
		return (free_config(config));
	}
	trim_str_arr(config);
	if (validation(config) == -1)
		return (free_config(config));
	return (config);
}

/* check_texture file??*/