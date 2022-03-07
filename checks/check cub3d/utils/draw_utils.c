/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:06:29 by namina            #+#    #+#             */
/*   Updated: 2022/01/29 18:06:30 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_pix_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0)
	{
		dst = img->addr + (y * img->line_len) + (x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_rectangle(t_img *img, t_rectangle *params, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < params->height)
	{
		j = 0;
		while (j < params->width)
		{
			my_pix_put(img, params->x + j, params->y + i, color);
			j++;
		}
		i++;
	}
}
