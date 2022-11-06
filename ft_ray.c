/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:45:47 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/21 16:55:37 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ray_h(float wanted_x, float wanted_y, float n_angle)
{
	int		j;
	int		a;

	n_angle = y_angle_h(&a, &wanted_y, &j);
	while (j == 0)
	{
		j = 1;
		wanted_x = cal_step_h(wanted_y, n_angle);
		if (wanted_y >= 0 && wanted_y < g_h * 64 && wanted_x >= 0
			&& wanted_x < g_w[(int)(wanted_y / 64)] * 64)
		{
			if (fmod(wanted_x, SQ) == 0 && fmod(wanted_y, SQ) == 0)
				wanted_x -= 1;
			if ((j = is_wall_ray(wanted_x, wanted_y - a)) == 0)
				wanted_y = pmsq_h(wanted_y);
		}
	}
	if (wanted_y >= 0 && wanted_y < g_h * 64 && wanted_x >= 0
		&& wanted_x < g_w[(int)(wanted_y / 64)] * 64)
		remp_g_r(wanted_x, wanted_y, n_angle);
	else
		remp_g_r(800000, 800000, n_angle);
}

static void	ray_v(float x, float y, float n_angle)
{
	int		j;
	int		a;

	n_angle = y_angle_v(&a, &x, &j);
	while (j == 0)
	{
		j = 1;
		y = cal_step_v(x, n_angle);
		if (y >= 0 && y < g_h * 64 && x >= 0 && x < g_w[(int)(y / 64)] * 64)
		{
			if (fmod(x, SQ) == 0 && fmod(y, SQ) == 0)
				y -= 1;
			if ((j = is_wall_ray(x - a, y)) == 0)
				x = pmsq_v(x);
		}
	}
	if (y >= 0 && y < g_h * 64 && x >= 0 && x < g_w[(int)(y / 64)] * 64)
		if (sqrtf(powf(g_player.x - x, 2) + powf(g_player.y - y, 2)) >
			sqrtf(powf(g_player.x - g_r_x, 2) + powf(g_player.y - g_r_y, 2)))
			wallxy(g_r_x, g_r_y, 1);
		else
			wallxy(x, y, 2);
	else
		wallxy(g_r_x, g_r_y, 1);
}

void		star_ray(void)
{
	float	ray_ang;
	int		rayid;

	ray_ang = (float)FOV / (float)g_data.w;
	g_ray.loop_ang = g_player.angle - (FOV / 2);
	rayid = 0;
	if (!(g_wall_distance = malloc(sizeof(float) * g_data.w)))
		puterror("Error\nCan't Allocate Enough Memory\n", NULL);
	while (g_ray.loop_ang < g_player.angle + (FOV / 2))
	{
		g_ray.x = g_player.x;
		g_ray.y = g_player.y;
		ray_h(g_player.x, g_player.y, g_ray.loop_ang);
		g_ray.x = g_player.x;
		g_ray.y = g_player.y;
		ray_v(g_player.x, g_player.y, g_ray.loop_ang);
		draw_wall(rayid, g_wall.x, g_wall.y, -1);
		if (rayid < g_data.w)
			g_wall_distance[rayid] = g_wall.dist;
		rayid++;
		g_ray.loop_ang += ray_ang;
	}
	star_sprite();
}
