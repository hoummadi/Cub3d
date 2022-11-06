/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:21:15 by hhoummad          #+#    #+#             */
/*   Updated: 2019/10/12 18:31:48 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		s;
	char	*dest;
	int		i;

	if (src == NULL)
		return (ft_strdup(""));
	i = 0;
	s = 0;
	while (src[s] != '\0')
		s++;
	if (!(dest = (char *)malloc(sizeof(dest) * (s + 1))))
		return (NULL);
	while (i <= s)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
