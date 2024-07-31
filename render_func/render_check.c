/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 03:29:50 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/01 04:08:47 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <mlx.h>
#include "render_func.h"

int	movable_check(t_vars *vars, int keycode)
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
	if (x >= vars->m_info->row_num || x <= 0 || \
	y <= 0 || vars->m_info->col_num <= y)
		return (NO_MOVE);
	else if (vars->map[y][x] == WALL)
		return (NO_MOVE);
	else if (vars->map[y][x] == EXIT && vars->m_info->c_cnt)
		return (NO_MOVE);
	else
		return (MOVE);
}

int	check_collective(t_vars *vars, int keycode)
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
	if (vars->map[y][x] == COLLECTIBLE)
		vars->m_info->c_cnt--;
	return (0);
}

int	check_end(t_vars *vars, int keycode)
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
	if (vars->map[y][x] == EXIT && !vars->m_info->c_cnt)
		return (GAME_END);
	return (0);
}
