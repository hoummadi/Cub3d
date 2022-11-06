/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:00:21 by hhoummad          #+#    #+#             */
/*   Updated: 2020/12/26 15:00:24 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	remp_g_r(float x, float y, float angle)
{
	g_r_x = x;
	g_r_y = y;
	g_r_ang = angle;
}

float	cal_step_v(float wanted, float angle)
{
	if (norm_anglef(g_ray.loop_ang) > 180 && norm_anglef(g_ray.loop_ang) < 360)
		return (g_player.y - (float)fabs(wanted - g_player.x)
			* fabs((float)tanf(angle * RADIN)));
	else
		return (g_player.y + (float)fabs(wanted - g_player.x)
			* fabs((float)tanf(angle * RADIN)));
}

float	cal_step_h(float wanted, float angle)
{
	if (g_ray.loop_ang > 90 && g_ray.loop_ang < 270)
		return (g_player.x - (float)fabs(wanted - g_player.y)
			* fabs((float)tanf(angle * RADIN)));
	else
		return (g_player.x + (float)fabs(wanted - g_player.y)
			* fabs((float)tanf(angle * RADIN)));
}

float	y_angle_h(int *a, float *wanted, int *j)
{
	*j = 0;
	if (sin(g_ray.loop_ang * RADIN) > 0)
	{
		*a = 0;
		*wanted = (((int)(g_player.y) / SQ) + 1) * SQ;
		if (g_ray.loop_ang > 90)
			return (g_ray.loop_ang - 90);
		else
			return (90 - g_ray.loop_ang);
	}
	else
	{
		*a = 1;
		*wanted = ((int)(g_player.y) / SQ) * SQ;
		if (g_ray.loop_ang > 270)
			return (g_ray.loop_ang - 270);
		else
			return (270 - g_ray.loop_ang);
	}
}

float	y_angle_v(int *a, float *wanted, int *j)
{
	*j = 0;
	if (cos(g_ray.loop_ang * RADIN) > 0)
	{
		*a = 0;
		*wanted = (((int)(g_player.x) / SQ) + 1) * SQ;
		if (g_ray.loop_ang > 270)
			return (360 - g_ray.loop_ang);
		else
			return (g_ray.loop_ang);
	}
	else
	{
		*a = 1;
		*wanted = ((int)(g_player.x) / SQ) * SQ;
		if (g_ray.loop_ang > 180)
			return (g_ray.loop_ang - 180);
		else
			return (180 - g_ray.loop_ang);
	}
}
