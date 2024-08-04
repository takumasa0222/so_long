/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilities_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:23:26 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/07/31 05:26:50 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_char_find_place(char *set, int s)
{
	ssize_t	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i])
	{
		if (set[i] == s)
			return (i);
		i++;
	}
	return (0);
}

int	cnt_word(char *str, int c)
{
	ssize_t	i;
	int		ret;

	i = 0;
	ret = 0;
	if (!str)
		return (ret);
	while (str[i])
	{
		if (str[i] == c)
			ret++;
		i++;
	}
	return (ret);
}
