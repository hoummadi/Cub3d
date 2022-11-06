/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angles_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:09:50 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/10 17:23:22 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		norm_angle(int angle)
{
	if (angle > 360)
		return (angle - 360);
	else if (angle < 0)
		return (angle + 360);
	return (angle);
}

float	norm_anglef(float angle)
{
	if (angle > 360)
		return (angle - 360);
	else if (angle < 0)
		return (angle + 360);
	return (angle);
}
