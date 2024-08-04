/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:25:09 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/07/31 06:49:27 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdio.h>
# include "./ft_get_next_line/get_next_line.h"


# define WALL '1'
# define ARG_ERROR_MSG "Argument is invalid"
# define FILE_OPEN_ERR -1
# define MAP_TOO_SMALL -2
# define MAP_IS_NOT_RECTANGLE -3
# define MAP_IS_NOT_ALLOCATED -4
# define MEM_ALLOCATION_ERR -5
# define MAP_IS_NOT_ENCLOSED -6
# define MAP_HAS_INVALID_NUM_END -7
# define MAP_HAS_INVALID_NUM_PLAYER -8
# define COLLECTIBLE_NOT_FOUND -9
# define NO_AVAILABLE_PATH -10


typedef struct s_map_info
{
	unsigned int	row_num;
	unsigned int	col_num;
	unsigned int	p_cnt;
	unsigned int	e_cnt;
	unsigned int	c_cnt;
	ssize_t			x;
	ssize_t			y;
}	t_map_info;

# define MAX_ROW 10923
//# define MAX_COL SSIZE_MAX /

int	so_long(char *map_file_path);

#endif