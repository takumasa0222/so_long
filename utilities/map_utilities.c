/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:11:09 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/07/31 07:19:30 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "so_long_utils.h"
#include "../validation/so_long_validation.h"

int	init_map(char *map_file_path, char ***bermap, t_map_info *map_i)
{
	int		i;
	int		fd;
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
	*bermap = (char **)malloc((i + 1) * sizeof(char *));
	if (!(*bermap))
		return (MEM_ALLOCATION_ERR);
	set_map_info_row(map_i, i);
	fd = open(map_file_path, O_RDONLY);
	if (fd < 0)
		return (close(fd), FILE_OPEN_ERR);
	return (get_map(fd, bermap, map_i));
}

int	init_tmp_map(char ***tmp_m, t_map_info **tmp_m_inf, t_map_info *m_inf)
{
	ssize_t	i;

	i = 0;
	*tmp_m_inf = (t_map_info *)malloc(1 * sizeof(t_map_info));
	if (!(*tmp_m_inf))
		return (MEM_ALLOCATION_ERR);
	*tmp_m = (char **)malloc(m_inf->row_num * sizeof(char *));
	if (!(*tmp_m))
		return (free(*tmp_m_inf), MEM_ALLOCATION_ERR);
	while (i < m_inf->row_num)
	{
		(*tmp_m)[i] = (char *)malloc(1 * sizeof(char));
		if (!(*tmp_m)[i])
		{
			//free_map_tmp(tmp_m_inf);
			return (free(*tmp_m_inf), MEM_ALLOCATION_ERR);
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
	size_t		i;
	size_t		first_line_len;

	i = 0;
	first_line_len = 0;
	while (1 && i < (size_t)map_i->row_num)
	{
		printf("i value is %ld\n",i);
		(*bermap)[i] = get_next_line(fd);
		printf("bermap value is %s\n", (*bermap)[i]);
		printf("strlen result %ld\n", ft_strlen((*bermap)[i]));
		if (!(*bermap)[i])
			break ;
		if (i == 0)
			first_line_len = ft_strlen((*bermap)[i]);
		// if (first_line_len != ft_strlen((*bermap)[i]) && first_line_len > 2)
		// 	return (free_map(bermap), MAP_IS_NOT_RECTANGLE);
		// else if (first_line_len < 3)
		// 	return (free_map(bermap), MAP_TOO_SMALL);
		i++;
	}
	exit(1);
	if (i < 2)
		return (free_map(bermap), MAP_TOO_SMALL);
	set_map_info_col(map_i, (unsigned int)first_line_len);
	set_map_info_row(map_i, (unsigned int)i);
	return (map_validator(*bermap, map_i));
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

// int	free_map_tmp(char ***map)
// {
	
// }