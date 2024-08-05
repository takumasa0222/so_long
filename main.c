/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:23:08 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/06 03:52:54 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"
#include "./validation/so_long_validation.h"
#include "./utilities/so_long_utils.h"

int	main(int argc, char *argv[])
{
	int	err_no;

	err_no = 0;
	err_no = arg_check(argc, argv);
	if (err_no)
	{
		show_error_msg(err_no);
		return (-1);
	}
	err_no = so_long(argv[1]);
	show_error_msg(err_no);
	return (err_no);
}
