/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:02:35 by namina            #+#    #+#             */
/*   Updated: 2022/01/29 22:36:46 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	error_exit(char *message)
{
	write(2, message, ft_strlen(message));
	exit(1);
}

void	trim_str_arr(t_map *config)
{
	int	last_line;

	last_line = config->map_size - 1;
	while (!ft_strlen(config->map[last_line]))
	{
		free(config->map[last_line]);
		config->map[last_line] = NULL;
		config->map_size--;
		last_line--;
	}
}

int	check_texture_files(t_map *config)
{
	int	i;
	int	fd;

	i = 0;
	while (i < 4)
	{
		if (config->texture_array[i])
		{
			fd = open(config->texture_array[i], O_RDONLY);
			if (fd == -1)
				return (-1);
			close(fd);
		}
		i++;
	}
	return (0);
}

int	check_color_str(char *str)
{
	char	*trimmed_str;
	int		i;

	i = 0;
	trimmed_str = ft_strtrim(str, " \t");
	while (trimmed_str[i])
	{
		if (!ft_isdigit(trimmed_str[i]))
		{
			free(trimmed_str);
			return (-1);
		}
		i++;
	}
	free(trimmed_str);
	return (0);
}

int	check_color_arr(char **arr)
{
	while (*arr)
	{
		if (check_color_str(*arr) == -1)
			return (-1);
		arr++;
	}
	return (0);
}
