/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:04:36 by hhoummad          #+#    #+#             */
/*   Updated: 2019/10/27 14:58:00 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	void		*s1;

	if (!dest && !src)
		return (NULL);
	if (!n)
		return (dest);
	i = 0;
	if (src < dest)
	{
		src += n;
		dest += n;
		while (n--)
			*(unsigned char*)--dest = *(unsigned char*)--src;
		return (dest);
	}
	else
	{
		s1 = dest;
		while (n--)
		{
			*(unsigned char*)dest++ = *(unsigned char*)src++;
		}
		return (s1);
	}
}
