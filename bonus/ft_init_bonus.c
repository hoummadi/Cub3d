/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:10:26 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/13 18:25:43 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		freedata(void *p)
{
	int i;

	i = 0;
	if (p)
		free(p);
	free(g_data.ea);
	free(g_data.no);
	free(g_data.so);
	free(g_data.we);
	free(g_data.s);
	if (g_data.map)
	{
		while (g_data.map[i])
		{
			free(g_data.map[i]);
			i++;
		}
		free(g_data.map);
	}
}

static void	setnull(void)
{
	g_data.ea = NULL;
	g_data.no = NULL;
	g_data.so = NULL;
	g_data.we = NULL;
	g_data.s = NULL;
	g_data.map = NULL;
	g_h = 0;
	g_ply = 0;
}

static void	ck_cub(char *fname)
{
	int		i;
	int		j;
	char	*set;

	set = ".cub";
	j = 0;
	i = ft_strlen(fname) - 4;
	while (set[j] != '\0')
	{
		if (fname[i] != set[j])
		{
			ft_putstr_fd("Error\nWrong File Extension\n", 2);
			exit(1);
		}
		j++;
		i++;
	}
}

void		init_data(char *fname)
{
	int fd2;

	ck_cub(fname);
	if ((g_fd = open(fname, O_RDONLY)) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putendl_fd(strerror(errno), 2);
		exit(1);
	}
	if ((fd2 = open("bonus/gameover.wav", O_RDONLY)) == -1)
	{
		ft_putstr_fd("Error\nWav file\n", 2);
		ft_putendl_fd(strerror(errno), 2);
		close(g_fd);
		exit(1);
	}
	close(fd2);
	setnull();
	readf(g_fd);
}
