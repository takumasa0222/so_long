/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:23:08 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/04 23:23:37 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"
#include "./validation/so_long_validation.h"

int	main(int argc, char *argv[])
{
	int	err_no;

	(void)argc; 
	if (arg_check(argc, argv))
	{
		ft_putstr_fd(ARG_ERROR_MSG, STDERR_FILENO);
		return (-1);
	}
	err_no = so_long(argv[1]);
	return (0);
}
