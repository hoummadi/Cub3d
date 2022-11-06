/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 18:58:00 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/17 17:19:43 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_angle(char c)
{
	if (c == 'N')
		g_player.angle = 270;
	else if (c == 'W')
		g_player.angle = 180;
	else if (c == 'S')
		g_player.angle = 90;
	else if (c == 'E')
		g_player.angle = 0;
}

void		player_pos(int y, int x)
{
	int t;

	t = 0;
	while (y < g_h && t == 0)
	{
		x = 0;
		while (x < g_w[y] && t == 0)
		{
			if (g_data.map[y][x] == 'N' || g_data.map[y][x] == 'W'
				|| g_data.map[y][x] == 'S' || g_data.map[y][x] == 'E')
			{
				g_player.x = (x * SQ) + (SQ / 2);
				g_player.y = (y * SQ) + (SQ / 2);
				player_angle(g_data.map[y][x]);
				g_data.map[y][x] = '0';
				t = 1;
			}
			x++;
		}
		y++;
	}
}

void		up_pos(int key, float wanted_x, float wanted_y)
{
	if (key == S)
	{
		wanted_x = g_player.x - cos(g_player.angle * RADIN) * MS;
		wanted_y = g_player.y - sin(g_player.angle * RADIN) * MS;
	}
	else if (key == A)
	{
		wanted_x = g_player.x + sin(g_player.angle * RADIN) * MS;
		wanted_y = g_player.y - cos(g_player.angle * RADIN) * MS;
	}
	else if (key == W)
	{
		wanted_x = g_player.x + cos(g_player.angle * RADIN) * MS;
		wanted_y = g_player.y + sin(g_player.angle * RADIN) * MS;
	}
	else if (key == D)
	{
		wanted_x = g_player.x - sin(g_player.angle * RADIN) * MS;
		wanted_y = g_player.y + cos(g_player.angle * RADIN) * MS;
	}
	is_a_wall(wanted_x, wanted_y);
}

int			check_more2(int x, int y, int lax, int lay)
{
	int		ck;

	ck = 0;
	if (x != lax && y != lay)
	{
		if (g_data.map[y][x] == '1' || g_data.map[y][x] == '2')
			ck++;
		if (g_data.map[y][lax] == '1' || g_data.map[y][lax] == '2')
			ck++;
		if (g_data.map[lay][x] == '1' || g_data.map[lay][x] == '2')
			ck++;
		if (g_data.map[lay][lax] == '1' || g_data.map[lay][lax] == '2')
			ck++;
		if (ck >= 2)
			return (1);
	}
	return (0);
}
