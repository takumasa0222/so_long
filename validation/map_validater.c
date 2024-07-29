/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 03:23:28 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/07/30 03:29:17 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_validator(char **map, t_map_info *map_info)
{
	int	err_no;

	err_no = 0;
	err_no = check_wall_elclosure(map, map_info);
	if (!err_no)
		return (err_no);
	err_no = check_elements_integrity(map, map_info);
	if (!err_no)
		return (err_no);
	err_no = check_valid_path(map, map_info);
	return (err_no);
}

int	check_wall_elclosure(char **bermap, t_map_info *m_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < m_info->row_num)
	{
		if (bermap[m_info->row_num - 1][i] != WALL || bermap[0][i] != WALL)
			return (MAP_IS_NOT_ENCLOSED);
		j = 0;
		if (i == 0 || i == (m_info->row_num - 1))
		{
			while (j < m_info->col_num)
			{
				if (bermap[j][i] != WALL)
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
	t_map_info	*map_check;
	char		**map_tmp;
	int			err_no;

	err_no = init_tmp_map(&map_tmp, &map_check, m_info);
	if (!err_no)
		return (err_no);
}

int	check_elements_integrity(char **bermap, t_map_info *m_info)
{
	ssize_t	i;

	i = 0;
	while (i < m_info->row_num)
	{
		set_map_info_e_cnt(m_info, m_info->e_cnt + cnt_word(bermap[i], 'E'));
		if (cnt_word(bermap[i], 'P'))
		{
			set_map_info_p_cnt(m_info, m_info->p_cnt + cnt_word(bermap[i], 'P'));
			set_map_info_x(m_info, ft_char_find_place(bermap[i], 'P'));
			set_map_info_y(m_info, i);
		}
		set_map_info_c_cnt(m_info, m_info->c_cnt + cnt_word(bermap[i], 'C'));
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

void	dfs(char ***tmp_map, char **map, t_map_info *tmp_map_inf)
{
	if (x < 0 || x >= tmp_map_inf->col_num || y < 0 \
	|| y >= tmp_map_inf->row_num || map[y][x] == '1' || (*tmp_map)[y][x])
		return;
	(*tmp_map)[y][x] = '1';
	if (map[y][x] == 'C') 
	tmp_map_inf->c_cnt++;
	if (map[y][x] == 'E')
	tmp_map_inf->e_cnt++;
	dfs(x + 1, y, tmp_map, map, tmp_map_inf);
	dfs(x - 1, y, tmp_map, map, tmp_map_inf);
	dfs(x, y + 1, tmp_map, map, tmp_map_inf);
	dfs(x, y - 1, tmp_map, map, tmp_map_inf);
}
int	ft_char_find_place(char const *set, int s)
{
	int	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i])
	{
		if (set[i] == s)
			return (i);
		i++;
	}
	return (0);
}