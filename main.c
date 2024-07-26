/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:23:08 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/07/27 03:40:20 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	if (argcheck(argc, argv))
	{
		ft_putstr_fd(ARG_ERROR_MSG, STDERR_FILENO);
		return (-1);
	}
	so_long(argv[1]);
	return (0);
}
