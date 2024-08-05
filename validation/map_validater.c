/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 03:23:28 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/06 05:11:13 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../utilities/so_long_utils.h"
#include "so_long_validation.h"

int	map_validator(char **map, t_map_info *map_info)
{
	int	err_no;

	err_no = 0;
	err_no = check_wall_elclosure(map, map_info);
	if (err_no)
		return (err_no);
	err_no = check_elements_integrity(map, map_info);
	if (err_no)
		return (err_no);
	err_no = check_valid_path(map, map_info);
	return (err_no);
}

int	check_wall_elclosure(char **bermap, t_map_info *m_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)m_info->row_num)
	{
		if (bermap[m_info->row_num - 1][i] != WALL || bermap[0][i] != WALL)
			return (MAP_IS_NOT_ENCLOSED);
		j = 0;
		if (i == 0 || i == (int)(m_info->row_num - 1))
		{
			while (j < (int)m_info->col_num)
			{
				if (bermap[i][j] != WALL)
					return (MAP_IS_NOT_ENCLOSED);
				j++;
			}
		}
		i++;
	}
	return (0);
}

int	check_valid_path(char **bermap, t_map_info *m_info)
{
	t_map_info	*tmp_map_info;
	char		**tmp_map;
	int			err_no;

	err_no = init_tmp_map(&tmp_map, &tmp_map_info, m_info);
	if (err_no)
		return (err_no);
	err_no = NO_AVAILABLE_PATH;
	set_map_info_x(tmp_map_info, m_info->x);
	set_map_info_y(tmp_map_info, m_info->y);
	set_map_info_row(tmp_map_info, m_info->row_num);
	set_map_info_col(tmp_map_info, m_info->col_num);
	set_map_info_e_cnt(tmp_map_info, 0);
	set_map_info_c_cnt(tmp_map_info, 0);
	dfs_path_check(&tmp_map, bermap, tmp_map_info);
	if (tmp_map_info->c_cnt == m_info->c_cnt && tmp_map_info->e_cnt)
		err_no = 0;
	free(tmp_map_info);
	free_map(&tmp_map, m_info->row_num);
	return (err_no);
}

int	check_elements_integrity(char **map, t_map_info *m_info)
{
	ssize_t	i;

	i = 0;
	while (i < m_info->row_num)
	{
		set_map_info_e_cnt(m_info, m_info->e_cnt + cnt_word(map[i], 'E'));
		if (cnt_word(map[i], 'P'))
		{
			set_map_info_p_cnt(m_info, m_info->p_cnt + cnt_word(map[i], 'P'));
			set_map_info_y(m_info, ft_char_find_place(map[i], 'P'));
			set_map_info_x(m_info, i);
		}
		set_map_info_c_cnt(m_info, m_info->c_cnt + cnt_word(map[i], 'C'));
		if (detect_invalid_char(map[i], VALID_CHAR, m_info->col_num))
			return (MAP_HAS_INVALID_CHAR);
		i++;
	}
	if (m_info->e_cnt == 0 || 1 < m_info->e_cnt)
		return (MAP_HAS_INVALID_NUM_END);
	if (m_info->p_cnt == 0 || 1 < m_info->p_cnt)
		return (MAP_HAS_INVALID_NUM_PLAYER);
	if (m_info->c_cnt == 0)
		return (COLLECTIBLE_NOT_FOUND);
	return (0);
}

void	dfs_path_check(char ***tmp_map, char **map, t_map_info *tmp_m_inf)
{
	ssize_t	x;
	ssize_t	y;

	x = tmp_m_inf->x;
	y = tmp_m_inf->y;
	if (x < 1 || tmp_m_inf->row_num < x || y < 1 \
	|| y >= tmp_m_inf->col_num || map[x][y] == '1' || (*tmp_map)[x][y])
		return ;
	(*tmp_map)[x][y] = '1';
	if (map[x][y] == 'C')
		tmp_m_inf->c_cnt++;
	if (map[x][y] == 'E')
	{
		tmp_m_inf->e_cnt++;
		return ;
	}
	tmp_m_inf->x = x + 1;
	dfs_path_check(tmp_map, map, tmp_m_inf);
	tmp_m_inf->x = x - 1;
	dfs_path_check(tmp_map, map, tmp_m_inf);
	tmp_m_inf->x = x;
	tmp_m_inf->y = y + 1;
	dfs_path_check(tmp_map, map, tmp_m_inf);
	tmp_m_inf->y = y - 1;
	dfs_path_check(tmp_map, map, tmp_m_inf);
}
