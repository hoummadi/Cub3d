/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:42:11 by hhoummad          #+#    #+#             */
/*   Updated: 2019/10/13 03:22:15 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*p;
	size_t	i;
	size_t	len;

	i = 0;
	len = n * size;
	if (!(p = malloc(len)))
		return (NULL);
	while (len > 0)
	{
		*(unsigned char *)p = 0;
		p++;
		i++;
		len--;
	}
	return (p - i);
}
