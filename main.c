/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:23:08 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/07/31 06:26:46 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"

int	main(int argc, char *argv[])
{
	int	err_no;

	(void)argc; 
	// if (argcheck(argc, argv))
	// {
	// 	ft_putstr_fd(ARG_ERROR_MSG, STDERR_FILENO);
	// 	return (-1);
	// }
	err_no = so_long(argv[1]);
	printf("error no is %d\n",err_no);
	return (0);
}
