/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:45:47 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/07/31 06:05:41 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_map_info_col(t_map_info *map_info, unsigned int col)
{
	map_info->col_num = col;
}

void	set_map_info_row(t_map_info *map_info, unsigned int row)
{
	map_info->row_num = row;
}

void	set_map_info_c_cnt(t_map_info *map_info, unsigned int c_cnt)
{
	map_info->c_cnt = c_cnt;
}

void	set_map_info_p_cnt(t_map_info *map_info, unsigned int p_cnt)
{
	map_info->p_cnt = p_cnt;
}

void	set_map_info_e_cnt(t_map_info *map_info, unsigned int e_cnt)
{
	map_info->e_cnt = e_cnt;
}
