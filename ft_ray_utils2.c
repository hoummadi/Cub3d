/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:52:27 by hhoummad          #+#    #+#             */
/*   Updated: 2020/12/26 17:52:30 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
