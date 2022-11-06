/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:46:44 by hhoummad          #+#    #+#             */
/*   Updated: 2020/12/16 16:46:49 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	isone(int i, int j)
{
	while (j < g_w[i])
	{
		if (g_data.map[i][j] != '1' && g_data.map[i][j] != ' ')
			puterror("Error\nMap Isn't Surrounded With Walls\n", NULL);
		j++;
	}
}

static void	check_zero(int i, int j)
{
	if ((j == 0 || j == (g_w[i] - 1)) && g_data.map[i][j] != '1'
		&& g_data.map[i][j] != ' ')
		puterror("Error\nMap Isn't Surrounded With Walls\n", NULL);
	else if (g_data.map[i][j] != '1' && g_data.map[i][j] != ' ')
	{
		if (g_w[i - 1] <= j || g_w[i + 1] <= j || g_data.map[i - 1][j] == ' '
			|| g_data.map[i + 1][j] == ' ')
			puterror("Error\nMap Isn't Surrounded With Walls\n", NULL);
		if (g_data.map[i][j - 1] == ' ' || g_data.map[i][j + 1] == ' ')
			puterror("Error\nMap Isn't Surrounded With Walls\n", NULL);
	}
}

void		isvalid(int i, int j)
{
	while (i < g_h)
	{
		j = 0;
		if (i == 0 || i == (g_h - 1))
			isone(i, 0);
		else
			while (j < g_w[i])
			{
				check_zero(i, j);
				j++;
			}
		i++;
	}
}
