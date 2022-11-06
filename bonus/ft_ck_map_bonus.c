/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ck_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 20:27:44 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/10 17:24:27 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_map(char *line, int fd)
{
	char *buf;

	if (g_check != 8)
		puterror("Error\nMap File Isn't Complete\n", NULL);
	g_check++;
	buf = joinmap(line, fd);
	g_data.map = ft_split(buf, '\n');
	wh_map();
	free(buf);
	isvalid(0, 0);
}
