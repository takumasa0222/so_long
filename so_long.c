/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:53:21 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/07/27 03:40:27 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(char *map_file_path)
{
	int	fd;
	int map_valid_ret;

	fd = open(map_file_path, O_RDONLY);
	if (fd < 0)
		return(close(fd), FILE_OPEN_ERR);
	map_valid_ret = map_validator(fd);
	if (map_valid_ret < 0)
		return (close(fd), map_valid_ret);
	
}
