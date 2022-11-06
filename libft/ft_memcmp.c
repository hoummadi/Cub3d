/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:10:46 by hhoummad          #+#    #+#             */
/*   Updated: 2019/10/28 17:35:37 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*k1;
	unsigned char	*k2;

	k1 = (unsigned char*)s1;
	k2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (k1[i] != k2[i])
			return (k1[i] - k2[i]);
		i++;
	}
	return (0);
}
