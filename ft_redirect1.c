/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 23:34:19 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/19 18:11:32 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_sp(char *line, int i)
{
	if (line[i] == ' ')
		puterror("Error\nOnly Information Can Be Separated by spaces\n", line);
	i = ft_strlen(line);
	if (line[i - 1] == ' ')
		puterror("Error\nOnly Information Can Be Separated by spaces\n", line);
}

void		check_r(char *line)
{
	char		**tab;
	static int	chek;

	if (chek > 0)
		puterror("Error\nDuplicated Resolution\n", line);
	tab = ft_split(line, ' ');
	if (tablen(tab) != 3)
	{
		free_2d(tab);
		puterror("Error\nResolution Element Is Wrong\n", line);
	}
	check_sp(line, 2);
	g_data.w = checkatoi(tab[1]) <= 2560 ? checkatoi(tab[1]) : 2560;
	g_data.h = checkatoi(tab[2]) <= 1440 ? checkatoi(tab[2]) : 1440;
	free_2d(tab);
	if (g_data.w <= 0 || g_data.h <= 0)
		puterror("Error\nResolution Element Is Wrong\n", line);
	g_check++;
	chek++;
	free(line);
}

static char	*cus_split(char *line, char *dir)
{
	int		i;
	int		fd;
	char	*ret;

	i = ft_strlen(dir);
	if ((size_t)i >= ft_strlen(line))
		puterror("Error\nThere Is No Path\n", line);
	ret = ft_strdup(line + i);
	free(line);
	if ((fd = open(ret, O_RDONLY)) == -1)
	{
		free(ret);
		ft_putstr_fd("Error\n", 2);
		ft_putendl_fd(strerror(errno), 2);
		close(g_fd);
		exit(1);
	}
	close(fd);
	return (ret);
}

void		check_path(char *line, char *dir)
{
	int			i;
	static int	chek[5];

	i = -1;
	if (ft_strncmp(dir, "NO ", 3) == 0 && ++chek[0] < 2)
		g_data.no = cus_split(line, dir);
	else if (ft_strncmp(dir, "SO ", 3) == 0 && ++chek[1] < 2)
		g_data.so = cus_split(line, dir);
	else if (ft_strncmp(dir, "WE ", 3) == 0 && ++chek[2] < 2)
		g_data.we = cus_split(line, dir);
	else if (ft_strncmp(dir, "EA ", 3) == 0 && ++chek[3] < 2)
		g_data.ea = cus_split(line, dir);
	else if (ft_strncmp(dir, "S ", 2) == 0 && ++chek[4] < 2)
		g_data.s = cus_split(line, dir);
	g_check++;
	while (++i < 5)
		if (chek[i] > 1)
			puterror("Error\nDuplicated Path\n", line);
}
