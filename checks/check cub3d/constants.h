/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:36:51 by namina            #+#    #+#             */
/*   Updated: 2022/01/29 21:06:38 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

/* world */
# define PLANE_WIDTH 960
# define PLANE_HEIGHT 690
# define PLANE_CENTER 345
# define PLAYER_SPEED 0.59
# define ROTATION_SPEED 0.33
# define FOV 0.66

/* orientation */
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

/* keys */
# define KEYCODE_ESC 53
# define KEYCODE_W 13
# define KEYCODE_A 0
# define KEYCODE_S 1
# define KEYCODE_D 2
# define KEYCODE_LEFT 123
# define KEYCODE_RIGHT 124

/* messages */
# define MEM_ALLOC_ERR "Error\nFailed to allocate memory\n"
# define INIT_WIN_ERR "Error\nFailed to initialize window\n"
# define TEXTURE_ERR "Error\nFailed to parse texture\n"
# define WRONG_MAP_FILE_FORMAT "Error\nWrong file format\n"
# define OPEN_MAP_ERROR "Error\nOpen file error\n"
# define INCORRECT_PARAMS "Error\nParams are incorrect\n"
# define INCORRECT_MAP "Error\nMap is incorrect\n"
# define MAP_OPEN_ERROR "Error\nMap isn't close\n"
# define NO_PLAYER_POSITION "Error\nNo player position\n"
# define PLAYER_ON_BORDER "Error\nPlayer position on border\n"

/* minimap */
# define MINI_MAP_WIDTH 150
# define MINI_MAP_HEIGHT 150
# define MINI_MAP_SLOTS 10
# define DRAW_MINIMAP_GRID 1

#endif
