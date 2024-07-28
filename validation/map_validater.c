/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 03:23:28 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/07/28 23:45:45 by tamatsuu         ###   ########.fr       */
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
		if (ft_strchr(bermap[i], 'E') == ft_strrchr(bermap[i], 'E'))
			set_map_info_e_cnt(m_info, m_info->e_cnt + 1);
		else
			return (MAP_HAS_INVALID_NUM_END);
		if (ft_strchr(bermap[i], 'P') == ft_strrchr(bermap[i], 'P'))
			set_map_info_p_cnt(m_info, m_info->p_cnt + 1);
		else
			return (MAP_HAS_INVALID_NUM_PLAYER);
		set_map_info_c_cnt(m_info, m_info->c_cnt + cnt_word(bermap[i], 'C'));
	}
	if (m_info->e_cnt == 0 || 1 < m_info->e_cnt)
		return (MAP_HAS_INVALID_NUM_END);
	if (m_info->p_cnt == 0 || 1 < m_info->p_cnt)
		return (MAP_HAS_INVALID_NUM_PLAYER);
	if (m_info->c_cnt == 0)
		return (COLLECTIBLE_NOT_FOUND);
	return (0);
}

void dfs(int x, int y, char ***tmp_map, char **map)
{
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT || map[y][x] == '1' || visited[y][x]) return;
    visited[y][x] = 1;
    if (map[y][x] == 'C') (*collected)++;
    if (map[y][x] == 'E') *found_exit = 1;
    dfs(x + 1, y, visited, collected, found_exit, item_count);
    dfs(x - 1, y, visited, collected, found_exit, item_count);
    dfs(x, y + 1, visited, collected, found_exit, item_count);
    dfs(x, y - 1, visited, collected, found_exit, item_count);
}