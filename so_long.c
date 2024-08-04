/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:53:21 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/04 14:45:06 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./utilities/so_long_utils.h"

int	so_long(char *map_file_path)
{
	int					map_valid_ret;
	char				**bermap;
	static t_map_info	map_i = {.row_num = 0, .col_num = 0, .c_cnt = 0, \
	.e_cnt = 0, .p_cnt = 0, .x = 0, .y = 0};

	map_valid_ret = init_map(map_file_path, &bermap, &map_i);
	if (map_valid_ret)
		error_call(map_valid_ret);
	init_render(bermap, &map_i);
}
