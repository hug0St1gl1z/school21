/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:37:57 by anisiaklime       #+#    #+#             */
/*   Updated: 2022/03/13 17:49:14 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_textures(void)
{
	g_game.img.floor.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/floor.XPM", &g_game.img.floor.h, &g_game.img.floor.w);
	g_game.img.wall.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/wall.XPM", &g_game.img.wall.h, &g_game.img.wall.w);
	g_game.img.exit_a.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/exit_a.XPM", &g_game.img.exit_a.h, &g_game.img.exit_a.w);
	g_game.img.exit_d.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/exit_d.XPM", &g_game.img.exit_d.h, &g_game.img.exit_d.w);
	g_game.img.player_left.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/player_left.XPM", &g_game.img.player_left.h,
			&g_game.img.player_left.w);
	g_game.img.player_right.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/player_right.XPM", &g_game.img.player_right.h,
			&g_game.img.player_right.w);
	g_game.img.obsticles.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/collect.XPM", &g_game.img.obsticles.h,
			&g_game.img.obsticles.w);
	g_game.img.cplay.img = g_game.img.player_right.img;
}

void	get_map(char *path)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	g_game.map = malloc(sizeof(char *) * (g_game.h + 1));
	while (i < g_game.h)
	{
		g_game.map[i] = ft_strdup(line);
		if (!g_game.map[i])
		{
			free_map(i);
			return ;
		}
		i++;
		line = get_next_line(fd);
	}
	g_game.map[i] = NULL;
}

void	put_image(t_image texture, int x, int y)
{
	static int	n;

	mlx_put_image_to_window(g_game.mlx, g_game.win, texture.img,
		2 + x * 30, y * 30);
	if (texture.img == g_game.img.player_left.img
		|| texture.img == g_game.img.player_right.img)
	{
		g_game.x = x;
		g_game.y = y;
		g_game.img.cplay.img = texture.img;
		printf("Numbur of mooves: %d\n", n);
		n++;
	}
}

void	init_map(void)
{
	int		i;
	int		j;

	i = -1;
	init_textures();
	while (++i < g_game.h)
	{
		j = -1;
		while (++j < g_game.w)
		{
			if (g_game.map[i][j] == '1')
				put_image(g_game.img.wall, j, i);
			else if (g_game.map[i][j] == 'E')
				put_image(g_game.img.exit_d, j, i);
			else
				put_image(g_game.img.floor, j, i);
			if (g_game.map[i][j] == 'C')
			{
				put_image(g_game.img.obsticles, j, i);
				g_game.img.tocollect++;
			}
			if (g_game.map[i][j] == 'P')
				put_image(g_game.img.player_right, j, i);
		}
	}
}
