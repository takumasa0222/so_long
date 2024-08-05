/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 03:18:04 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/06 05:05:03 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"
#include "../libft/libft.h"

void	show_error_msg(int err_no)
{
	ft_putstr_fd(BASE_ERR_MSG, 2);
	if (err_no == FILE_OPEN_ERR)
		ft_putendl_fd(FILE_OPEN_ERR_MSG, 2);
	else if (err_no == MAP_TOO_SMALL)
		ft_putendl_fd(MAP_TOO_SMALL_MSG, 2);
	else if (err_no == MAP_IS_NOT_RECTANGLE)
		ft_putendl_fd(MAP_IS_NOT_RECTANGLE_MSG, 2);
	else if (err_no == MAP_HAS_INVALID_CHAR)
		ft_putendl_fd(MAP_HAS_INVALID_CHAR_MSG, 2);
	else if (err_no == MEM_ALLOCATION_ERR)
		ft_putendl_fd(MEM_ALLOCATION_ERR_MSG, 2);
	else if (err_no == MAP_IS_NOT_ENCLOSED)
		ft_putendl_fd(MAP_IS_NOT_ENCLOSED_MSG, 2);
	else if (err_no == MAP_HAS_INVALID_NUM_END)
		ft_putendl_fd(MAP_HAS_INVALID_NUM_END_MSG, 2);
	else if (err_no == MAP_HAS_INVALID_NUM_PLAYER)
		ft_putendl_fd(MAP_HAS_INVALID_NUM_PLAYER_MSG, 2);
	else if (err_no == COLLECTIBLE_NOT_FOUND)
		ft_putendl_fd(COLLECTIBLE_NOT_FOUND_MSG, 2);
	else if (err_no == NO_AVAILABLE_PATH)
		ft_putendl_fd(NO_AVAILABLE_PATH_MSG, 2);
	else if (err_no == ARG_NUM_INVALID)
		ft_putendl_fd(ARG_NUM_INVALID_MSG, 2);
	else if (err_no == INVALID_FILE_TYPE)
		ft_putendl_fd(INVALID_FILE_TYPE_MSG, 2);
}
