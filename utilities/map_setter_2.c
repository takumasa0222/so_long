/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setter_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:10:33 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/07/31 06:27:47 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "../so_long.h"

void	set_map_info_x(t_map_info *map_info, ssize_t x)
{
	map_info->x = x;
}

void	set_map_info_y(t_map_info *map_info, ssize_t y)
{
	map_info->y = y;
}
