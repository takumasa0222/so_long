/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 04:08:38 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/01 04:21:17 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <mlx.h>
#include "render_func.h"
//#include "../utilities/"

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
	vars->map[vars->m_info->y][vars->m_info->x] = EMPTY;
	vars->map[y][x] = PLAYER;
	vars->m_info->x = x;
	vars->m_info->y = y;
}

end_game(t_vars *vars)
{	
	close_window(vars);
}

close_window(t_vars *vars)
{
	free_map(vars->map);
	free(vars->mlx);
}
