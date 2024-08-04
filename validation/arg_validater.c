/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 23:16:17 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/04 23:39:35 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"

int	arg_check(int argc, char **argv)
{
	size_t	i;

	i = 0;
	if (argc != 2)
		return (ARG_NUM_INVALID);
	if (argv[1])
	{
		i = ft_strlen(argv[1]);
		//if (i < 4 || ft_strncmp())
			return (INVALID_FILE_TYPE);

	}
	return (0);
}
