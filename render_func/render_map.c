/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:49:11 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/01 04:15:46 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <mlx.h>
#include "render_func.h"

int	init_render(char **map, t_map_info	*m_inf)
{
	t_vars	vars;
	int		win_wid;
	int		win_height;

	win_wid = m_inf->col_num * PIX;
	win_height = m_inf->row_num * PIX;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, win_wid, win_height, WIN_TITLE);
	vars.map = map;
	vars.m_info = m_inf;
	render_map(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}

int	key_hook(int keycode, t_vars *vars)
{
	int	mv_ret;

	mv_ret = 0;
	if (UP_KEY <= keycode && key_hook <= RIGHT_KEY)
	{
		mv_ret = move_player(key_hook, vars);
		show_nb_move();
		if (mv_ret == GAME_END)
			end_game(vars);
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
		return (0);
	check_collective(vars);
	is_end = check_end(vars);
	set_map_position(keycode, vars);
	render_map(vars);
	if (is_end)
		return (GAME_END);
	return (0);
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
			render_component_img(vars->map[j][i], vars, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

void	*render_component_img(char comp, t_vars *vars, int i, int j)
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
}
