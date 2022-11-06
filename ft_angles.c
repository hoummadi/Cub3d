/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:11:49 by hhoummad          #+#    #+#             */
/*   Updated: 2020/12/23 12:11:58 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
