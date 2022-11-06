/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:27:33 by hhoummad          #+#    #+#             */
/*   Updated: 2019/10/16 19:53:26 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	if (c == 0)
		return ((char*)s);
	while (*(--s) != c && --i > 0)
	{
		if (*s == '\0')
			return (0);
	}
	if (*s == c)
		return ((char*)s);
	return (NULL);
}
