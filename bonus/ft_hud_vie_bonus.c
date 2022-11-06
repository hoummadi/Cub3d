/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud_vie_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:59:27 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/11 12:57:17 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		data_hud_vie(void)
{
	int tmp_x;

	g_hud.y_a = g_data.h / 5;
	g_hud.y_b = g_hud.y_a / 2;
	g_hud.y_c = g_hud.y_b + (g_hud.y_b / 2);
	g_hud.a = g_data.w / 4;
	g_hud.b = g_data.w - g_hud.a;
	g_hud.c = g_hud.a + (g_hud.a / 2);
	g_hud.d = g_data.w - g_hud.c;
	tmp_x = (g_hud.d - g_hud.c) / 10;
	g_vie.s_x = g_hud.c + tmp_x;
	g_vie.e_x = g_hud.d - tmp_x;
	g_vie.s_y = g_hud.y_b / 6;
	g_vie.e_y = g_hud.y_b - g_vie.s_y - 15;
	tmp_x = ((g_vie.e_x - g_vie.s_x) / 5) * g_vital;
	g_vie.e_vie = g_vie.s_x + tmp_x;
}

static void	draw_hud(int x, int y)
{
	while (x < g_data.w)
	{
		y = 0;
		while (y < g_data.h)
		{
			if (((x < g_hud.a || x > g_hud.b) && (y < g_hud.y_a - 15 &&
				(x < g_hud.a - 15 || x > g_hud.b + 15 || y < g_hud.y_c - 15)))
				|| ((x < g_hud.c || x > g_hud.d) && (y < g_hud.y_c - 15 &&
				(x < g_hud.c - 15 || x > g_hud.d + 15))))
				g_d_addr[y * g_data.w + x] = 163;
			else if (((x < g_hud.a || x > g_hud.b) && (y < g_hud.y_a))
				|| ((x < g_hud.c || x > g_hud.d) && (y < g_hud.y_c)))
				g_d_addr[y * g_data.w + x] = 0;
			else
			{
				if (y < g_hud.y_b - 15)
					g_d_addr[y * g_data.w + x] = 163;
				else if (y < g_hud.y_b)
					g_d_addr[y * g_data.w + x] = 0;
			}
			y++;
		}
		x++;
	}
}

static void	draw_vie(int x, int y)
{
	x = g_vie.s_x;
	while (x < g_vie.e_x)
	{
		y = g_vie.s_y;
		while (y < g_vie.e_y)
		{
			if (x < g_vie.e_vie)
				g_d_addr[y * g_data.w + x] = 16711680;
			else
				g_d_addr[y * g_data.w + x] = 16800;
			y++;
		}
		x++;
	}
}

void		star_hv(void)
{
	data_hud_vie();
	draw_hud(0, 0);
	draw_vie(0, 0);
}
