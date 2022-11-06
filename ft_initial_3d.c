/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initial_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 19:43:35 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/20 19:20:07 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*fillxpm(int *tex, double sx, double sy, int w)
{
	int		*data;
	double	x;
	double	y;
	int		a;
	int		b;

	if (!tex || !(data = (int *)malloc(sizeof(int) * (SQ * SQ))))
		puterror("Error\nCan't Allocate Enough Memory!\n", NULL);
	y = 0;
	a = 0;
	while (a < SQ)
	{
		x = 0;
		b = 0;
		while (b < SQ)
		{
			data[a * SQ + b] = tex[(int)y * w + (int)x];
			x += sx;
			b++;
		}
		y += sy;
		a++;
	}
	return (data);
}

static void	fix_xpm(char *dir, int i)
{
	double	st_x;
	double	st_y;

	st_x = (double)g_tex.w[i] / (double)SQ;
	st_y = (double)g_tex.h[i] / (double)SQ;
	if (ft_strnstr(dir, "NO ", 3))
		g_tex.no = fillxpm(g_tex2.no, st_x, st_y, g_tex.w[i]);
	else if (ft_strnstr(dir, "SO ", 3))
		g_tex.so = fillxpm(g_tex2.so, st_x, st_y, g_tex.w[i]);
	else if (ft_strnstr(dir, "WE ", 3))
		g_tex.we = fillxpm(g_tex2.we, st_x, st_y, g_tex.w[i]);
	else if (ft_strnstr(dir, "EA ", 3))
		g_tex.ea = fillxpm(g_tex2.ea, st_x, st_y, g_tex.w[i]);
	else if (ft_strnstr(dir, "S ", 2))
		g_tex.s = fillxpm(g_tex2.s, st_x, st_y, g_tex.w[i]);
}

static void	dataxpm(char *filename, char *dir, int i)
{
	void	*xpm_ptr;
	int		nl;

	if (!(xpm_ptr = mlx_xpm_file_to_image(g_mlx_ptr, filename,
		&g_tex.w[i], &g_tex.h[i])))
		puterror("Error\nXPM file is not valid\n", NULL);
	if (ft_strnstr(dir, "NO ", 3))
		g_tex2.no = (int *)mlx_get_data_addr(xpm_ptr, &nl, &nl, &nl);
	else if (ft_strnstr(dir, "SO ", 3))
		g_tex2.so = (int *)mlx_get_data_addr(xpm_ptr, &nl, &nl, &nl);
	else if (ft_strnstr(dir, "WE ", 3))
		g_tex2.we = (int *)mlx_get_data_addr(xpm_ptr, &nl, &nl, &nl);
	else if (ft_strnstr(dir, "EA ", 3))
		g_tex2.ea = (int *)mlx_get_data_addr(xpm_ptr, &nl, &nl, &nl);
	else if (ft_strnstr(dir, "S ", 2))
		g_tex2.s = (int *)mlx_get_data_addr(xpm_ptr, &nl, &nl, &nl);
	fix_xpm(dir, i);
}

void		init_scene(void)
{
	dataxpm(g_data.no, "NO ", 0);
	dataxpm(g_data.so, "SO ", 1);
	dataxpm(g_data.we, "WE ", 2);
	dataxpm(g_data.ea, "EA ", 3);
	dataxpm(g_data.s, "S ", 4);
	g_dis_pp = (g_data.w / 2) / fabs(tan((FOV / 2) * RADIN));
	player_pos(0, 0);
	init_sprite();
	star_ray();
}
