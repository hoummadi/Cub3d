/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:10:31 by hhoummad          #+#    #+#             */
/*   Updated: 2019/11/18 00:43:59 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup2(char *src)
{
	int		s;
	char	*dest;
	int		i;

	i = 0;
	s = 0;
	if (!src)
	{
		if (!(dest = (char *)malloc(1)))
			return (0);
		dest[0] = '\0';
		return (dest);
	}
	while (src[s] != '\0')
		s++;
	if (!(dest = (char *)malloc(sizeof(*dest) * (s + 1))))
		return (NULL);
	while (i < s)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*p;

	if (!s1 || !s2)
		return (ft_strdup(""));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(p = malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	k = -1;
	while (++k < i)
		p[k] = s1[k];
	k = 0;
	while (k < j)
	{
		p[i] = s2[k];
		k++;
		i++;
	}
	p[i] = '\0';
	free(s1);
	free(s2);
	return (p);
}
