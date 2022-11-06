/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:21:54 by hhoummad          #+#    #+#             */
/*   Updated: 2019/11/03 17:33:47 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	n;
	size_t	k;

	i = 0;
	n = (size_t)start;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	k = ft_strlen(s + start);
	if (len > k)
		len = k;
	if (!(p = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i + start] && i < len)
	{
		p[i] = s[i + n];
		i++;
	}
	p[i] = '\0';
	return (p);
}
