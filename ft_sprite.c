/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:40:02 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/21 17:19:04 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	draw_sprite(int i)
{
	int		trp;
	int		tex_x;
	int		tex_y;
	int		y;
	int		d;

	trp = g_prt.x_star;
	while (trp < g_prt.x_end && g_prt.x_star < g_data.w)
	{
		tex_x = (trp - g_prt.x_star) * SQ / g_prt.h;
		y = g_prt.y_star;
		if (trp >= 0 && trp < g_data.w &&
			g_sprites[i].dis2 < g_wall_distance[trp])
		{
			while (y < g_prt.y_end)
			{
				d = y + (g_prt.h / 2) - (g_data.h / 2);
				tex_y = d * ((SQ * 1.0) / g_prt.h);
				if (g_tex.s[SQ * tex_y + tex_x] != 0)
					g_d_addr[y * g_data.w + trp] = g_tex.s[64 * tex_y + tex_x];
				y++;
			}
		}
		trp++;
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
		draw_sprite(i);
		i++;
	}
	free(g_wall_distance);
}
