/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:51:27 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/07/31 23:27:32 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//int	main(void)
//{
//	void	*mlx;
//	// void	*mlx_win;
//	t_data	img;
//	// int		width;
//	// int		height;
//	// int		width2;
//	// int		height2;
//	// void	*image;
//	// void	*image2;

//	// width = 0;
//	// height = 0;

//	// width2 = 0;
//	// height2 = 0;
//	mlx = mlx_init();
//	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
//	mlx_new_window(mlx, 1920, 1080, "Hello world!");
//	img.img = mlx_new_image(mlx, 1920, 1080);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//								&img.endian);
//	// image = mlx_xpm_file_to_image(mlx, "./images/space.xpm", &width, &height);
//	// image2 = mlx_xpm_file_to_image(mlx, "./images/blackhole.xpm", &width2, &height2);
//	my_mlx_pixel_put(&img, 50, 50, 0x00FF0F00);
//	// mlx_put_image_to_window(mlx, mlx_win, image, 64, 64);
//	// mlx_put_image_to_window(mlx, mlx_win, image2, 0, 0);
//	mlx_loop(mlx);
//}
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	(void)vars;
	printf("%d\n",keycode);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	//mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);

	mlx_loop(vars.mlx);
	return(0);
}


