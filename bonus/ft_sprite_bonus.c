/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:40:02 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/21 17:20:01 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	calc_x_start(int i)
{
	float	sp_angle;
	float	pixel_num;
	int		rotation;

	sp_angle = norm_anglef(atan2(g_sprites[i].y - g_player.y,
			g_sprites[i].x - g_player.x) * (180 / M_PI));
	rotation = norm_angle(g_player.angle - (FOV / 2));
	sp_angle = sp_angle - rotation;
	if (sp_angle > 180)
		sp_angle -= 360;
	else if (sp_angle < -180)
		sp_angle += 360;
	pixel_num = (float)FOV / (float)g_data.w;
	g_prt.x_star = sp_angle / pixel_num;
}

void	befor_draw(int i)
{
	g_prt.h = g_dis_pp * (SQ / g_sprites[i].dis2);
	g_prt.y_star = (g_data.h / 2) - (g_prt.h / 2);
	g_prt.y_star = g_prt.y_star < 0 ? 0 : g_prt.y_star;
	g_prt.y_end = (g_data.h / 2) + (g_prt.h / 2);
	g_prt.y_end = g_prt.y_end >= g_data.h ? g_data.h : g_prt.y_end;
	calc_x_start(i);
	g_prt.x_star = g_prt.x_star - (g_prt.h / 2);
	g_prt.x_end = g_prt.x_star + g_prt.h;
}

void	draw_sprite(int i, int *tx)
{
	int		p;
	int		tx_x;
	int		tx_y;
	int		y;
	int		d;

	p = g_prt.x_star;
	while (p < g_prt.x_end && g_prt.x_star < g_data.w)
	{
		tx_x = (p - g_prt.x_star) * SQ / g_prt.h;
		y = g_prt.y_star;
		if (p >= 0 && p < g_data.w &&
			g_sprites[i].dis2 < g_wall_distance[p])
		{
			while (y < g_prt.y_end + abs(g_vue) && y + g_vue < g_data.h)
			{
				d = y + (g_prt.h / 2) - (g_data.h / 2);
				tx_y = d * ((SQ * 1.0) / g_prt.h);
				if (tx_y < 64 && tx_y >= 0 && tx[SQ * tx_y + tx_x] != 0)
					g_d_addr[(y + g_vue) * g_data.w + p] = tx[64 * tx_y + tx_x];
				y++;
			}
		}
		p++;
	}
}

void	star_sprite(void)
{
	int		i;

	i = 0;
	dis_sprite();
	sort_sprite();
	while (i < g_som_spr)
	{
		befor_draw(i);
		if (g_sprites[i].tp == '2')
			draw_sprite(i, g_tex.s);
		else if (g_sprites[i].tp == '3')
			draw_sprite(i, g_tex.t);
		i++;
	}
	free(g_wall_distance);
}
