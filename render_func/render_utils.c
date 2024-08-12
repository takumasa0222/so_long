/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 04:08:38 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/12 14:26:50 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <mlx.h>
#include "render_func.h"
#include "../utilities/so_long_utils.h"
#include "../libft/libft.h"

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
	free(vars->c_info);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	show_move_count(t_vars *vars, int mov_cnt)
{
	char	*temp;
	char	*msg;

	temp = NULL;
	msg = NULL;
	vars->c_info->mov_cnt = vars->c_info->mov_cnt + mov_cnt;
	temp = ft_itoa(vars->c_info->mov_cnt);
	if (!temp)
	{
		show_error_msg(MEM_ALLOCATION_ERR);
		close_window(vars);
	}
	msg = ft_strjoin(MOVE_COUNT_MSG, temp);
	if (!msg)
	{
		free(temp);
		show_error_msg(MEM_ALLOCATION_ERR);
		close_window(vars);
	}
	ft_putendl_fd(msg, STDOUT_FILENO);
	free(temp);
	free(msg);
}

int	close_btn_click(t_vars *vars)
{
	close_window(vars);
	return (0);
}
