/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:17:40 by lray              #+#    #+#             */
/*   Updated: 2023/04/14 14:55:41 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

int	win_close(void);

int	key_listener(int kc)
{
	printf("keycode = %d\n", kc);
	if (kc == 53)
		win_close();
	return (0);
}

int mk_listener(int mc)
{
	printf("mousecode = %d\n", mc);
	return (0);
}

int mm_listener(int x, int y)
{
	printf("MX = %d MY = %d\n", x, y);
	return (0);
}

int	win_close(void)
{
	exit(0);
	return (0);
}

void	build_ground(void *ground_ptr)
{
	int	width = 800;
	int	heigth = 600;
	int	bpp = 32;
	int	size_line;
	char	*ground_data;
	int		color = 0xFFFFFF;
	int		offset;
	int		x;
	int		y;

	ground_data = mlx_get_data_addr(ground_ptr, &bpp, &size_line, NULL);
	x = 0;
	y = 0;
	while (x < width)
	{
		while (y < heigth)
		{
			offset = y * size_line + x * (bpp / 8);
			*(unsigned int *)(ground_data + offset) = color;
			//mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
			y++;
		}
		y = 0;
		x++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img_player;
	int		img_h = 64;
	int		img_w = 55;
	//void	*ground_ptr;
	//char	*ground_data;
	int		i;
	//int		bpp = 32;
	//int		size_line;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "Salut les connards");
	mlx_hook(win, 17, 0, win_close, mlx);
	mlx_hook(win, 2, 0, key_listener, mlx);
	mlx_hook(win, 4, 0, mk_listener, mlx);
	mlx_hook(win, 6, 0, mm_listener, mlx);

	//ground_ptr = mlx_new_image(mlx, 800, 600);
	//build_ground(ground_ptr);
	//ground_data = mlx_get_data_addr(ground_ptr, &bpp, &size_line, NULL);
	img_player = mlx_xpm_file_to_image(mlx, "img/player.xpm", &img_h, &img_w);
	//img_data = mlx_get_data_addr(img_player, &bpp, &size_line, NULL);
	i = 0;
	while (1)
	{

		mlx_clear_window(mlx, win);
		//mlx_put_image_to_window(mlx, win, ground_ptr, 0, 0);
		mlx_put_image_to_window(mlx, win, img_player, i, 0);
		//usleep(50);
		if (i )
		i += 10;
		mlx_do_sync(mlx);
	}
	//mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
	return (1);
}
