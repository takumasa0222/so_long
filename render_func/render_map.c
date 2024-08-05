/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:49:11 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/06 02:32:53 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <mlx.h>
#include "render_func.h"

int	init_render(char **map, t_map_info	*m_inf)
{
	t_vars		vars;
	int			win_wid;
	int			win_height;
	t_char_info	*char_info;

	char_info = malloc(1 * sizeof(t_char_info));
	if (!char_info)
		return (MEM_ALLOCATION_ERR);
	char_info->mov_cnt = 0;
	win_wid = m_inf->col_num * PIX;
	win_height = m_inf->row_num * PIX;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, win_wid, win_height, WIN_TITLE);
	vars.map = map;
	vars.m_info = m_inf;
	vars.c_info = char_info;
	render_map(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	int	mv_ret;

	mv_ret = 0;
	if (UP_KEY <= keycode && keycode <= RIGHT_KEY)
	{
		mv_ret = move_player(keycode, vars);
		if (mv_ret == GAME_END)
		{
			show_move_count(vars, MOVE);
			end_game(vars);
		}
		else if (mv_ret == NO_MOVE)
			return (0);
		else
			show_move_count(vars, MOVE);
	}
	if (keycode == ESC)
		close_window(vars);
	return (0);
}

int	move_player(int keycode, t_vars *vars)
{
	int	is_end;

	is_end = 0;
	if (!movable_check(vars, keycode))
		return (NO_MOVE);
	check_collective(vars, keycode);
	is_end = check_end(vars, keycode);
	set_map_position(keycode, vars);
	render_map(vars);
	if (is_end)
		return (GAME_END);
	return (MOVE);
}

int	render_map(t_vars *vars)
{
	unsigned int	x;
	unsigned int	y;
	size_t			i;
	size_t			j;

	i = 0;
	x = vars->m_info->row_num;
	y = vars->m_info->col_num;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			render_component_img(vars->map[i][j], vars, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

void	render_component_img(char comp, t_vars *vars, int i, int j)
{
	void	*image;
	int		width;
	int		height;

	width = 0;
	height = 0;
	image = NULL;
	if (comp == PLAYER)
		image = mlx_xpm_file_to_image(vars->mlx, PLAYER_XPM, &width, &height);
	else if (comp == WALL)
		image = mlx_xpm_file_to_image(vars->mlx, WALL_XPM, &width, &height);
	else if (comp == EMPTY)
		image = mlx_xpm_file_to_image(vars->mlx, EMPTY_XPM, &width, &height);
	else if (comp == COLLECTIBLE)
		image = mlx_xpm_file_to_image(vars->mlx, COLCTIB_XPM, &width, &height);
	else if (comp == EXIT)
		image = mlx_xpm_file_to_image(vars->mlx, EXIT_XPM, &width, &height);
	if (image)
		mlx_put_image_to_window(vars->mlx, vars->win, image, j * PIX, i * PIX);
	mlx_destroy_image(vars->mlx, image);
}
