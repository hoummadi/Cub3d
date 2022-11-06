/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:37:28 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/21 18:40:58 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cl(int t, int x)
{
	while (t >= 0 && x < g_data.w)
	{
		g_d_addr[t * g_data.w + x] = g_data.c;
		t--;
	}
}

static void	fl(int t, int x)
{
	while (t < g_data.h && x < g_data.w)
	{
		g_d_addr[t * g_data.w + x] = g_data.f;
		t++;
	}
}

void		draw_wall(int x, float a, float b, float i)
{
	float	y;
	int		t;
	float	j;

	j = 0;
	y = g_dis_pp * (SQ / g_wall.dist);
	t = (g_data.h / 2) - (y / 2);
	cl(t, x);
	g_hold = (float)SQ / y;
	while (++t < 0)
		j += g_hold;
	while (++i < y && t < g_data.h && x < g_data.w && j < SQ)
	{
		if ((int)(b) % SQ == 0 && g_wall.der == 1 && b < g_player.y)
			g_d_addr[t * g_data.w + x] = g_tex.so[(int)j * SQ + ((int)a % SQ)];
		else if ((int)(b) % SQ == 0 && g_wall.der == 1 && b > g_player.y)
			ADDR[t * G.w + x] = T.no[(int)j * SQ + (SQ - 1 - ((int)a % SQ))];
		else if ((int)(a) % SQ == 0 && g_wall.der == 2 && a > g_player.x)
			g_d_addr[t * g_data.w + x] = g_tex.we[(int)j * SQ + ((int)b % SQ)];
		else
			ADDR[t * G.w + x] = T.ea[(int)j * SQ + (SQ - 1 - ((int)b % SQ))];
		t++;
		j += g_hold;
	}
	fl(t, x);
}
