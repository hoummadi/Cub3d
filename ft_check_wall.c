/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 12:40:47 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/17 17:06:48 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_more(int x, int y, int lax, int lay)
{
	int		ck;

	ck = 0;
	if (x != lax && y != lay)
	{
		if (g_data.map[y][x] == '1')
			ck++;
		if (g_data.map[y][lax] == '1')
			ck++;
		if (g_data.map[lay][x] == '1')
			ck++;
		if (g_data.map[lay][lax] == '1')
			ck++;
		if (ck >= 2)
			return (1);
	}
	return (0);
}

int		des_wall(float x_inter, float y_inter)
{
	int		x;
	int		y;

	x = (int)floor(x_inter) / SQ;
	y = (int)floor(y_inter) / SQ;
	if (y < g_h && x < g_w[y])
	{
		if (g_data.map[y][x] == '1')
			return (1);
		return (0);
	}
	return (1);
}

void	is_a_wall(float x_inter, float y_inter)
{
	int		x;
	int		y;
	int		lax;
	int		lay;

	x = (int)floor(x_inter) / SQ;
	y = (int)floor(y_inter) / SQ;
	lax = (int)floor(g_player.x) / SQ;
	lay = (int)floor(g_player.y) / SQ;
	if (y < g_h && x < g_w[y])
	{
		if (g_data.map[y][x] == '1' || g_data.map[y][x] == '2')
			return ;
		if (!check_more2(x, y, lax, lay) && des_wall(x_inter + 4,
			y_inter + 4) == 0 && des_wall(x_inter - 4, y_inter - 4) == 0)
		{
			g_player.x = x_inter;
			g_player.y = y_inter;
		}
	}
}

int		is_wall_ray(float x_inter, float y_inter)
{
	int		x;
	int		y;
	int		lax;
	int		lay;

	x = (int)floor(x_inter) / SQ;
	y = (int)floor(y_inter) / SQ;
	lax = (int)floor(g_ray.x) / SQ;
	lay = (int)floor(g_ray.y) / SQ;
	if (y < g_h && x < g_w[y])
	{
		if (g_data.map[y][x] == '1')
			return (1);
		if (!check_more(x, y, lax, lay))
		{
			g_ray.x = x_inter;
			g_ray.y = y_inter;
			return (0);
		}
	}
	return (1);
}

void	wallxy(float x, float y, int i)
{
	g_wall.x = x;
	g_wall.y = y;
	g_wall.der = i;
	g_wall.dist = sqrtf(powf(g_player.x - x, 2) + powf(g_player.y - y, 2));
	g_wall.dist = g_wall.dist
		* cos(fabs(g_player.angle - g_ray.loop_ang) * RADIN);
}
