/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:18:15 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/20 16:03:43 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		wh_map(void)
{
	int i;

	g_h = tablen(g_data.map);
	if (!(g_w = malloc(sizeof(int) * (g_h + 1))))
		puterror("Error\nCan't Allocate Enough Memory\n", NULL);
	i = 0;
	while (i < g_h)
	{
		g_w[i] = ft_strlen(g_data.map[i]);
		i++;
	}
}

static void	check_ln(char *ln)
{
	int			i;
	int			one;

	if (ln[0] == '\0')
		puterror("Error\nThe Map Isn't Valid\n", ln);
	i = 0;
	one = 0;
	while (ln[i] && g_ply < 2)
	{
		if (ln[i] != '0' && ln[i] != '1' && ln[i] != '2' && ln[i] != 'N'
			&& ln[i] != 'W' && ln[i] != 'S' && ln[i] != 'E' && ln[i] != ' ')
			puterror("Error\nUnallowed Character In The Map\n", NULL);
		if (ln[i] == 'N' || ln[i] == 'W' || ln[i] == 'S' || ln[i] == 'E')
			g_ply++;
		if (ln[i] == '1' || ln[i] == ' ')
			one++;
		if (ln[i] == '2')
			g_som_spr++;
		i++;
	}
	if (one == 0)
		puterror("Error\nThe Map Isn't Valid\n", NULL);
	if (g_ply > 1)
		puterror("Error\nDuplicated Player In The Map\n", NULL);
}

static char	*ck_join(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

char		*joinmap(char *line, int fd)
{
	char	*str;
	int		j;

	j = 1;
	str = ft_strdup("");
	while (j > 0)
	{
		g_ck_m++;
		check_ln(line);
		line = ck_join(line, "\n");
		str = ck_join(str, line);
		free(line);
		j = get_next_line(fd, &line);
	}
	if (j == -1)
		puterror("Error\nCan't Read The File\n", NULL);
	check_ln(line);
	g_ck_m++;
	str = ck_join(str, line);
	free(line);
	return (str);
}
