/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:52:27 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/10 17:26:35 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

float	pmsq_h(float wanted)
{
	if (sin(g_ray.loop_ang * RADIN) > 0)
		return (wanted += SQ);
	else
		return (wanted -= SQ);
}

float	pmsq_v(float wanted)
{
	if (cos(g_ray.loop_ang * RADIN) > 0)
		return (wanted += SQ);
	else
		return (wanted -= SQ);
}
