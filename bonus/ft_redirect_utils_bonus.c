/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 01:06:12 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/21 17:53:35 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		checkatoi(char *str)
{
	int i;
	int	j;

	i = 0;
	if (!str)
		puterror("Error\nSomething Went Wrong\n", NULL);
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			return (-1);
		i++;
	}
	j = 0;
	while (str[j] == '0')
	{
		j++;
	}
	if (i - j > 5)
		return (ft_atoi("9999"));
	return (ft_atoi(str));
}

void	puterror(char *str, void *p)
{
	ft_putstr_fd(str, 2);
	freedata(p);
	close(g_fd);
	exit(1);
}

int		tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_2d(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
