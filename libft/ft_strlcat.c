/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 21:24:36 by hhoummad          #+#    #+#             */
/*   Updated: 2019/10/29 22:17:15 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int		i;
	size_t	c_d;
	size_t	c_s;

	c_d = 0;
	c_s = 0;
	i = -1;
	while (src[c_s])
		c_s++;
	if (!dest && !size)
		return (c_s + size);
	while (dest[c_d])
		c_d++;
	if (c_d >= size)
		return (c_s += size);
	else
		c_s += c_d;
	while (src[++i] && c_d < size - 1)
	{
		dest[c_d] = src[i];
		c_d++;
	}
	dest[c_d] = '\0';
	return (c_s);
}
