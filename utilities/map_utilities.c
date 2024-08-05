/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:11:09 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/06 04:15:38 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "so_long_utils.h"
#include "../validation/so_long_validation.h"
#include "../libft/libft.h"

int	init_map(char *map_file_path, char ***bermap, t_map_info *map_i)
{
	int		i;
	int		fd;
	char	*temp;

	fd = open(map_file_path, O_RDONLY);
	if (fd < 0)
		return (FILE_OPEN_ERR);
	i = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		i++;
		free(temp);
	}
	close(fd);
	*bermap = (char **)malloc((i + 1) * sizeof(char *));
	if (!(*bermap))
		return (MEM_ALLOCATION_ERR);
	set_map_info_row(map_i, i);
	fd = open(map_file_path, O_RDONLY);
	if (fd < 0)
		return (FILE_OPEN_ERR);
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
		(*tmp_m)[i] = (char *)ft_calloc(1 * sizeof(char), m_inf->col_num);
		if (!(*tmp_m)[i])
		{
			free_map(tmp_m, i);
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
		(*bermap)[i] = get_next_line(fd);
		if (!(*bermap)[i])
			break ;
		if (i == 0)
			first_line_len = ft_strlen((*bermap)[i]);
		if (first_line_len == ft_strlen((*bermap)[i]) + 1 \
		&& i + 1 == (size_t)map_i->row_num)
			break ;
		if (first_line_len != ft_strlen((*bermap)[i]) && first_line_len > 2)
			return (close(fd), MAP_IS_NOT_RECTANGLE);
		i++;
	}
	close(fd);
	if (i < 2 || first_line_len < 3)
		return (MAP_TOO_SMALL);
	set_map_info_col(map_i, (unsigned int)first_line_len - 1);
	return (map_validator(*bermap, map_i));
}

int	free_map(char ***bermap, unsigned int l)
{
	unsigned int	i;

	i = 0;
	if (!bermap)
		return (0);
	while (i < l)
	{
		free((*bermap)[i]);
		(*bermap)[i] = NULL;
		i++;
	}
	free(*bermap);
	*bermap = NULL;
	return (0);
}
