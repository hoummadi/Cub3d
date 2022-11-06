/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:36:14 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/13 14:41:56 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_sprite(int i)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (!(g_sprites = malloc(sizeof(t_spr) * g_som_spr)))
		puterror("Error\nCan't Allocate Enough Memory\n", NULL);
	while (i < g_h)
	{
		j = 0;
		while (j < g_w[i])
		{
			if (g_data.map[i][j] == '2' || g_data.map[i][j] == '3')
			{
				g_sprites[k].y = i * SQ + SQ / 2;
				g_sprites[k].x = j * SQ + SQ / 2;
				g_sprites[k].tp = g_data.map[i][j];
				if (g_data.map[i][j] == '3' && g_trap == 0)
					puterror("Error\nNo Path For Trap\n", NULL);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	dis_sprite(void)
{
	int		i;
	float	sp_angle;

	i = 0;
	while (i < g_som_spr)
	{
		g_sprites[i].dis = sqrtf(powf(g_player.x - g_sprites[i].x, 2)
			+ powf(g_player.y - g_sprites[i].y, 2));
		sp_angle = norm_anglef(atan2(g_sprites[i].y - g_player.y,
			g_sprites[i].x - g_player.x) * (180 / M_PI));
		sp_angle = g_player.angle - sp_angle;
		if (sp_angle > 180)
			sp_angle -= 360;
		else if (sp_angle < -180)
			sp_angle += 360;
		if (sp_angle > 40 || sp_angle < -40)
			g_sprites[i].dis2 = g_sprites[i].dis;
		else
			g_sprites[i].dis2 = g_sprites[i].dis *
				cos(fabs(sp_angle) * RADIN);
		i++;
	}
}

void	sort_sprite(void)
{
	int		i;
	int		j;
	t_spr	tmp_sprites;

	i = 0;
	while (i < g_som_spr)
	{
		j = i + 1;
		while (j < g_som_spr)
		{
			if (g_sprites[i].dis < g_sprites[j].dis)
			{
				tmp_sprites = g_sprites[i];
				g_sprites[i] = g_sprites[j];
				g_sprites[j] = tmp_sprites;
			}
			j++;
		}
		i++;
	}
}
