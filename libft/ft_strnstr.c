/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:50:04 by hhoummad          #+#    #+#             */
/*   Updated: 2019/10/30 17:11:18 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	c;

	i = 0;
	c = 0;
	if (to_find[i] == '\0')
		return ((char*)str);
	while (to_find[c] != '\0')
		c++;
	if (!str && len == 0)
		return (NULL);
	while (str[i] && i < len)
	{
		j = 0;
		while (to_find[j] == str[i + j] && i + j < len)
		{
			if (j == c - 1)
				return ((char*)str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
