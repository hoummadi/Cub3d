/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 03:48:37 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/21 17:58:20 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ck_vr(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	return (count);
}

static int	ft_trim(char *str)
{
	char	*tmp;
	int		ret;

	tmp = ft_strtrim(str, " ");
	ret = checkatoi(tmp);
	free(tmp);
	return (ret);
}

static int	put_color(char *tab)
{
	char	**rgb;
	int		clr[3];
	int		color;

	rgb = ft_split(tab, ',');
	if (tablen(rgb) != 3 || ck_vr(tab) != 2)
	{
		free_2d(rgb);
		puterror("Error\nColor Element Is Wrong\n", NULL);
	}
	clr[0] = ft_trim(rgb[0]);
	clr[1] = ft_trim(rgb[1]);
	clr[2] = ft_trim(rgb[2]);
	free_2d(rgb);
	if (clr[0] < 0 || clr[0] > 255 || clr[1] < 0 || clr[1] > 255
		|| clr[2] < 0 || clr[2] > 255)
		puterror("Error\nColor Element Is Wrong\n", NULL);
	color = clr[0] * 65536 + clr[1] * 256 + clr[2];
	return (color);
}

void		check_color(char *line, char *pos)
{
	char		*tab;
	int			i;
	static int	chek[2];

	i = -1;
	check_sp(line, 2);
	tab = ft_strdup(line + 2);
	if ((ft_strncmp(pos, "F ", 2) == 0) && ++chek[0])
		g_data.f = put_color(tab);
	else if ((ft_strncmp(pos, "C ", 2) == 0) && ++chek[1])
		g_data.c = put_color(tab);
	g_check++;
	free(tab);
	while (++i < 2)
		if (chek[i] > 1)
			puterror("Error\nDuplicated Color\n", line);
	free(line);
}
