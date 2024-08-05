/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validater_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 04:43:09 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/06 05:13:19 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"
#include "../utilities/so_long_utils.h"

int	detect_invalid_char(char *str, char *valid_str, size_t col_num)
{
	size_t	valid_str_len;
	size_t	i;
	size_t	cnt_total;

	i = 0;
	cnt_total = 0;
	if (!str || !valid_str)
		return (MAP_HAS_INVALID_CHAR);
	valid_str_len = ft_strlen(valid_str);
	while (i < valid_str_len)
	{
		cnt_total += cnt_word(str, valid_str[i]);
		i++;
	}
	if (col_num == cnt_total)
		return (0);
	else
		return (MAP_HAS_INVALID_CHAR);
}
