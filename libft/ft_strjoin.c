/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:32:05 by hhoummad          #+#    #+#             */
/*   Updated: 2019/11/05 15:44:31 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (p);
}
