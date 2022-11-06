/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 23:08:42 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/13 18:20:27 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	redirect(char *line, int fd)
{
	if (ft_strnstr(line, "R ", 2))
		check_r(line);
	else if (ft_strnstr(line, "NO ", 3))
		check_path(line, "NO ");
	else if (ft_strnstr(line, "SO ", 3))
		check_path(line, "SO ");
	else if (ft_strnstr(line, "WE ", 3))
		check_path(line, "WE ");
	else if (ft_strnstr(line, "EA ", 3))
		check_path(line, "EA ");
	else if (ft_strnstr(line, "S ", 2))
		check_path(line, "S ");
	else if (ft_strnstr(line, "F ", 2))
		check_color(line, "F ");
	else if (ft_strnstr(line, "C ", 2))
		check_color(line, "C ");
	else if ((ft_strnstr(line, "1", 1) || ft_strnstr(line, " ", 1)))
		check_map(line, fd);
	else if (line[0] != '\0')
		puterror("Error\nLine Starts With Unallowed Character\n", line);
	else
		free(line);
}

void		readf(int fd)
{
	char	*line;
	int		ret;

	g_check = 0;
	g_ck_m = 0;
	g_som_spr = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
		redirect(line, fd);
	if (line[0] != '\0' && (line[0] == '1' || line[0] == ' '))
		g_ck_m++;
	if (ret == -1)
		puterror("Error\nCan't Read The File\n", NULL);
	free(line);
	if (g_check == 0)
		puterror("Error\nThere Is Nothing In The File\n", NULL);
	if (g_ck_m == 0)
		puterror("Error\nMap Doesn't Exist\n", NULL);
	if (g_ck_m < 3)
		puterror("Error\nThe Map Isn't Valid\n", NULL);
	if (g_ply == 0)
		puterror("Error\nPlayer Doesn't Exist In The Map\n", NULL);
}
