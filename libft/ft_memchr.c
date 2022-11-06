/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:16:33 by hhoummad          #+#    #+#             */
/*   Updated: 2019/10/17 00:51:17 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*k;
	size_t				i;

	k = s;
	i = 0;
	while (i < n)
	{
		if (k[i] == (unsigned char)c)
			return ((void*)k + i);
		i++;
	}
	return (0);
}
