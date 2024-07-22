/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:23:08 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/07/22 23:35:30 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	if (argcheck(argc, argv))
	{
		showError(ARG_ERROR);
		return (0);
	}
	so_long(argv[1]);
	return (0);
}
