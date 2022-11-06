/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:07:51 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/21 17:01:08 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		close_b(void)
{
	mlx_destroy_window(g_mlx_ptr, g_win_ptr);
	freedata(NULL);
	close(g_fd);
	exit(0);
}

void	start_visuals(void)
{
	if (!(g_mlx_ptr = mlx_init()))
		puterror("Error\nmlx init Failed\n", NULL);
	if (!(g_win_ptr = mlx_new_window(g_mlx_ptr, g_data.w, g_data.h, TITLE)))
		puterror("Error\nmlx new window Failed\n", NULL);
	if (!(g_nimage = mlx_new_image(g_mlx_ptr, g_data.w, g_data.h)))
		puterror("Error\nmlx new image Failed\n", NULL);
	if (!(g_d_addr = (int *)mlx_get_data_addr(g_nimage, &g_bits_per_pixel,
		&g_s_line, &g_endian)))
		puterror("Error\nmlx get data addr Failed\n", NULL);
	g_vue = 0;
	init_scene();
	if (g_save == 1)
		export_bmp(g_data.w, g_data.h);
	mlx_hook(g_win_ptr, 2, 1, &update, NULL);
	mlx_hook(g_win_ptr, 17, 0, &close_b, NULL);
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_nimage, 0, 0);
	mlx_loop(g_mlx_ptr);
}
