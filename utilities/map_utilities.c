/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:11:09 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/07/28 23:40:30 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_map(char *map_file_path, char ***bermap, t_map_info *map_i)
{
	int		i;
	int		fd;
	char	**bermap;
	char	*temp[MAX_ROW];

	fd = open(map_file_path, O_RDONLY);
	if (fd < 0)
		return (close(fd), FILE_OPEN_ERR);
	i = 0;
	while (1)
	{
		temp[i] = get_next_line(fd);
		if (!temp[i])
			break ;
		i++;
		free(temp[i]);
	}
	close(fd);
	*bermap = (char **)malloc(i * sizeof(char *));
	if (!(*bermap))
		return (MEM_ALLOCATION_ERR);
	fd = open(map_file_path, O_RDONLY);
	if (fd < 0)
		return (close(fd), FILE_OPEN_ERR);
	return (get_map(fd, &bermap, map_i));
}

int	init_tmp_map(char ***map_tmp, t_map_info **map_check, t_map_info *m_info)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	*map_check = (t_map_info *)malloc(1 * sizeof(t_map_info));
	if (!(*map_check))
		return (MEM_ALLOCATION_ERR);
	*map_tmp = (char **)malloc(m_info->row_num * sizeof(char *));
	if (!(*map_tmp))
		return (free(*map_check), MEM_ALLOCATION_ERR);
	while (i < m_info->row_num)
	{
		j = 0;
		while (j < m_info->col_num)
		{
			(*map_tmp)[j][i] = (char *)malloc(1 * sizeof(char));
			if (!(*map_tmp)[j++][i])
			{
				free_map_tmp(map_check);
				return (free(*map_check), MEM_ALLOCATION_ERR);
			}
		}
		i++;
	}
	return (0);
}

/*
This function set map array. if the map is not rectangle or too small return 
error number.
*/
int	get_map(int fd, char ***bermap, t_map_info *map_i)
{
	ssize_t		i;
	ssize_t		first_line_len;

	i = 0;
	if (!bermap)
		return (MAP_IS_NOT_ALLOCATED);
	while (1 && i < MAX_ROW)
	{
		(*bermap)[i] = get_next_line(fd);
		if (!(*bermap)[i])
			break ;
		if (i == 0)
			first_line_len = ft_strlen((*bermap)[i]);
		if (first_line_len == ft_strlen((*bermap)[i]) && first_line_len > 2)
			i++;
		else if (first_line_len < 3)
			return (free_map(bermap), MAP_TOO_SMALL);
		else
			return (free_map(bermap), MAP_IS_NOT_RECTANGLE);
	}
	if (i < 2)
		return (free_map(bermap), MAP_TOO_SMALL);
	set_map_info_col(map_i, (unsigned int)first_line_len);
	set_map_info_row(map_i, (unsigned int)i);
	return (map_validator(bermap, map_i));
}

int	free_map(char ***bermap)
{
	int	i;

	i = 0;
	if (!bermap)
		return (0);
	while (*bermap)
	{
		free((*bermap)[i]);
		i++;
	}
	return (0);
}

int	free_map_tmp(char ***map)
{
	
}