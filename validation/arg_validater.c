/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 23:16:17 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/06 01:50:34 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"
#include "./so_long_validation.h"

int	arg_check(int argc, char **argv)
{
	size_t	i;
	char	*temp;

	i = 0;
	if (argc != 2)
		return (ARG_NUM_INVALID);
	if (argv[1])
	{
		i = ft_strlen(argv[1]);
		temp = ft_substr(argv[1], i - 4, 4);
		if (i < 4 || !temp || ft_strncmp(temp, BER_EXTENSIOIN, 4))
			return (INVALID_FILE_TYPE);
		free(temp);
	}
	return (0);
}
