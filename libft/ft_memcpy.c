/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:59:52 by hhoummad          #+#    #+#             */
/*   Updated: 2019/10/30 22:46:54 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*s1;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	s1 = dest;
	s = src;
	while (i < n)
	{
		s1[i] = s[i];
		i++;
	}
	return (dest);
}
