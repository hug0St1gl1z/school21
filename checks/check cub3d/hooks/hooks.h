/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:40:35 by namina            #+#    #+#             */
/*   Updated: 2022/01/29 18:40:36 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H
# include "../cub3D.h"

void	dda_move_forward_backward(t_setup *setup, bool forward);
void	dda_move_left_right(t_setup *setup, bool left);
void	dda_rotate(t_setup *setup, bool left);

#endif
