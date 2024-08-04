/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 04:08:38 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/04 22:59:50 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <mlx.h>
#include "render_func.h"
#include "../utilities/so_long_utils.h"

void	set_map_position(int keycode, t_vars *vars)
{
	size_t	x;
	size_t	y;

	x = vars->m_info->x;
	y = vars->m_info->y;
	if (keycode == UP_KEY)
		x = x - 1;
	else if (keycode == RIGHT_KEY)
		y = y + 1;
	else if (keycode == LEFT_KEY)
		y = y - 1;
	else if (keycode == DOWN_KEY)
		x = x + 1;
	vars->map[vars->m_info->x][vars->m_info->y] = EMPTY;
	vars->map[x][y] = PLAYER;
	vars->m_info->x = x;
	vars->m_info->y = y;
}

void	end_game(t_vars *vars)
{	
	close_window(vars);
}

void	close_window(t_vars *vars)
{
	free_map(&(vars->map), vars->m_info->row_num);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	exit(0);
}
