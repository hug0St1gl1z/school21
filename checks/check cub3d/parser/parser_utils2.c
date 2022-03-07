/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:54:14 by namina            #+#    #+#             */
/*   Updated: 2022/01/29 22:25:54 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	*exit_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (NULL);
}

int	check_for_colors(char *line, int *color_el, char color_place)
{
	char	**tmp_arr;

	while (*line == ' ')
		line++;
	if (*line == color_place)
	{
		line++;
		tmp_arr = ft_split(line, ',');
		if (!tmp_arr)
			return (-1);
		if (!tmp_arr || tmp_arr[3] || check_color_arr(tmp_arr) == -1
			|| !tmp_arr[0] || !tmp_arr[1] || !tmp_arr[2])
		{
			free_arr(tmp_arr);
			return (0);
		}
		*color_el = create_trgb(0, ft_atoi(tmp_arr[0]), ft_atoi(tmp_arr[1]),
				ft_atoi(tmp_arr[2]));
		free_arr(tmp_arr);
	}
	return (0);
}

void	check_for_texture(char *line, t_map *config)
{
	char	**arr_line;

	arr_line = ft_split(line, ' ');
	if (!arr_line)
		return ;
	if (!arr_line || !(*arr_line) || !(**arr_line))
	{
		free_arr(arr_line);
		return ;
	}
	if (arr_line[1] && !ft_strncmp(*arr_line, "NO", 3))
		config->texture_array[0] = ft_strdup(arr_line[1]);
	if (arr_line[1] && !ft_strncmp(*arr_line, "SO", 3))
		config->texture_array[1] = ft_strdup(arr_line[1]);
	if (arr_line[1] && !ft_strncmp(*arr_line, "WE", 3))
		config->texture_array[2] = ft_strdup(arr_line[1]);
	if (arr_line[1] && !ft_strncmp(*arr_line, "EA", 3))
		config->texture_array[3] = ft_strdup(arr_line[1]);
	free_arr(arr_line);
}

int	handle_line(t_map *config, char **line)
{
	check_for_texture(*line, config);
	if (check_for_colors(*line, &(config->floor_color), 'F') == -1)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	if (check_for_colors(*line, &(config->ceil_color), 'C') == -1)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	free(*line);
	*line = NULL;
	return (0);
}

void	set_map_width_height(int file_fd, t_map *config)
{
	int		current_len;
	char	*line;
	int		gnl_res;

	gnl_res = 1;
	while (gnl_res)
	{
		gnl_res = get_next_line(file_fd, &line);
		current_len = ft_strlen(line);
		if (current_len > config->max_line)
			config->max_line = current_len;
		config->map_size++;
		free(line);
	}
}
