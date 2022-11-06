/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 20:12:46 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/21 17:01:51 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	up_angle(int key)
{
	if (key == 123)
		g_player.angle -= RS;
	else
		g_player.angle += RS;
	g_player.angle = norm_anglef(g_player.angle);
}

static void	up_player(int key)
{
	if (key == 123 || key == 124)
		up_angle(key);
	else
		up_pos(key, 0, 0);
}

static void	up_vue(int key)
{
	if (key == 125)
	{
		if (g_vue > -200)
			g_vue -= 50;
	}
	else if (key == 126)
	{
		if (g_vue < 200)
			g_vue += 50;
	}
}

int			update(int key)
{
	if (key == 0 || key == 13 || key == 1 || key == 2
		|| key == 123 || key == 124)
	{
		mlx_clear_window(g_mlx_ptr, g_win_ptr);
		up_player(key);
		star_ray();
		mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_nimage, 0, 0);
	}
	else if (key == 53)
	{
		mlx_destroy_window(g_mlx_ptr, g_win_ptr);
		freedata(NULL);
		close(g_fd);
		exit(0);
	}
	else if (key == 125 || key == 126)
	{
		up_vue(key);
		mlx_clear_window(g_mlx_ptr, g_win_ptr);
		star_ray();
		mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_nimage, 0, 0);
	}
	return (0);
}
