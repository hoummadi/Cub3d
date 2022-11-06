/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 22:37:18 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/17 17:28:03 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char *argv[])
{
	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("Error\nWrong Number Of Arguments\n", 2);
		return (1);
	}
	if (argc == 3)
	{
		g_save = 1;
		check_save(argv[2]);
	}
	else
		g_save = 0;
	init_data(argv[1]);
	start_visuals();
	return (0);
}
